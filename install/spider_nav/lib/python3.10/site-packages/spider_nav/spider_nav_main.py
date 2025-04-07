import pandas as pd
import rclpy
from rclpy.node import Node
from spider_interfaces.srv import LocService
from sensor_msgs.msg import NavSatFix, Imu
from math import radians, cos, sin, sqrt, atan2, dist, degrees
from spider_nav.utils.gps_utils import euler_from_quaternion
import torch
import time
from locomotion.servoLeveler import ServoLeveler
from spider_nav.utils.adafruit_gps_ros import Adafruit_Gps_Ros
from depthai_ros_msgs.msg import SpatialDetectionArray, SpatialDetection
from vision_msgs.msg import ObjectHypothesis, BoundingBox2D
from geometry_msgs.msg import Point


class Spider_Nav_Main(Node):

    def __init__(self):
        super().__init__('spider_nav_main')

        self.declare_parameter('input_file', '/home/dfolse/repos/SPIDER_Web/map1.csv')
        self.declare_parameter('sim_imu', False)
        self.declare_parameter('sim_gps', False)

        self.input_file = self.get_parameter('input_file').value
        self.sim_imu = self.get_parameter('sim_imu').value
        self.sim_gps = self.get_parameter('sim_gps').value

        self.waypoints_df = pd.read_csv(self.input_file)
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

        num_waypoints = self.waypoints_df.shape[0]
        self.waypointGoalList = []
        
        for waypoint in range(num_waypoints):
            self.waypointGoalList.append(False)

        self.cli = self.create_client(LocService, 'LocService')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = LocService.Request()

        if self.sim_gps is False:
            self.gps_subscription = self.create_subscription(
                NavSatFix,
                '/gps/fix',
                self.gps_callback,
                1
            )
            self.last_gps_position = NavSatFix()
        else:
            self.mock_gps = Adafruit_Gps_Ros(True)
            self.last_gps_position = self.mock_gps.gps
        if self.sim_imu is False:
            self.imu_subscription = self.create_subscription(
                Imu,
                '/imu',
                self.imu_callback,
                1
            )
            self.last_heading = 0.0
        else:
            self.mock_imu = ServoLeveler(0x39, True)
            self.last_heading = 0.0
        self.obs_subscription = self.create_subscription(
            SpatialDetectionArray,
            '/oak/nn/spatial_detections',
            self.obs_callback,
            1
        )
        self.detections = []
    def send_request(self, move_type, move_amount, delta_angle):
        self.req.move_type.data = move_type
        self.req.move_amount = move_amount
        self.req.delta_angle = delta_angle
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return

    def lat_lon_to_cartesian(self, lat, lon):
        # Earth radius in meters
        R = 6371000
        
        x = R * torch.cos(lat) * torch.cos(lon)
        y = R * torch.cos(lat) * torch.sin(lon)
        z = R * torch.sin(lat)
        
        return torch.stack([x, y, z], dim=-1)
    
    def calculate_move(self, lat1, lon1, lat2, lon2):
        # Convert latitude and longitude from degrees to radians
        lat1_tensor = torch.tensor(lat1).to(self.device)
        lon1_tensor = torch.tensor(lon1).to(self.device)
        lat2_tensor = torch.tensor(lat2).to(self.device)
        lon2_tensor = torch.tensor(lon2).to(self.device)

        lat1_rad = torch.deg2rad(lat1_tensor)
        lon1_rad = torch.deg2rad(lon1_tensor)
        lat2_rad = torch.deg2rad(lat2_tensor)
        lon2_rad = torch.deg2rad(lon2_tensor)

        #figure out the distance
        distance = self.euclidean_distance(self.lat_lon_to_cartesian(lat1_rad, lon1_rad), self.lat_lon_to_cartesian(lat2_rad, lon2_rad))

        # Calculate difference in longitudes
        delta_lon = lon2_rad - lon1_rad

        # Calculate bearing angle using the formula
        y = torch.sin(delta_lon) * torch.cos(lat2_rad)
        x = torch.cos(lat1_rad) * torch.sin(lat2_rad) - torch.sin(lat1_rad) * torch.cos(lat2_rad) * torch.cos(delta_lon)
        bearing_rad = torch.atan2(y, x)

        # Convert radians to degrees
        bearing_deg = torch.rad2deg(bearing_rad)

        # Ensure angle is between 0 and 360 degrees
        bearing_deg = (bearing_deg + 360) % 360

        return distance, bearing_deg
    
    def euclidean_distance(self, point1, point2):
        """Calculate Euclidean distance between two points."""
        return torch.norm(point1 - point2, dim=-1)

    def gps_callback(self, msg: NavSatFix):
        """
        Callback to store the last GPS pose
        """
        self.last_gps_position = msg

    def obs_callback(self, msg: NavSatFix):
        """
        Callback to store the last GPS pose
        """
        self.detections = msg.detections

    def imu_callback(self, msg: Imu):
        """
        Callback to store the last heading
        """
        _, _, self.last_heading = euler_from_quaternion(msg.orientation)
        
    def wait_for_response(self):
        while rclpy.ok():
            rclpy.spin_once(self)
            if self.future.done():
                try:
                    response = self.future.result()
                    self.get_logger().info('Cool? "%s"' % response.status.data)
                except Exception as e:
                    self.get_logger().error(f'Service call failed: {e}')
                break

    def checkForGoal(self, lat, lon):
        dist, angle = self.calculate_move(self.last_gps_position.latitude, self.last_gps_position.longitude, lat, lon)
        if(dist <= 1):
            return True
        else:
            return False
        
    def decideMove(self):
        self.get_logger().info('Heading %f, Long: %f, Lat: %f' % (self.last_heading, self.last_gps_position.latitude, self.last_gps_position.longitude))
        waypoint_num = None
        for i in range(len(self.waypointGoalList)):
            self.get_logger().info(str(self.waypointGoalList[i]))
            if(self.waypointGoalList[i] is False):
                waypoint_num = i
                break
            else:
                continue
        if waypoint_num == None:
            return -1
        dist, angle = self.calculate_move(self.last_gps_position.latitude, self.last_gps_position.longitude,
                                           self.waypoints_df['Latitude'].iloc[waypoint_num], self.waypoints_df['Longitude'].iloc[waypoint_num])
        self.get_logger().info("Distance: %f Angle: %f to next waypoint" % (dist, angle))
        
        if(dist <= 1):
            self.waypointGoalList[waypoint_num] = True
            if(all(self.waypointGoalList) == True):
                return ('stop', 0, 0.0)
            dist, angle = self.calculate_move(self.last_gps_position.latitude, self.last_gps_position.longitude,
                                           self.waypoints_df['Latitude'].iloc[waypoint_num + 1], self.waypoints_df['Longitude'].iloc[waypoint_num + 1])
        
        diff = (angle - self.last_heading + 180) % 360 - 180
        if(abs(diff) >= 5):
            
            if self.sim_imu:
                    self.mock_imu.sensor_9DoF.changeHeading(diff)
                    self.last_heading, _, _ = self.mock_imu.checkEuler()
                    
            if diff > 0:
                return ('turnRight', 0, abs(diff))
            elif diff < 0:
                return ('turnLeft', 0, abs(diff))
            else:
                self.get_logger().info(str(angle))
                self.get_logger().info(str(diff))
                return
        else:
            if dist < 6:
                if self.sim_gps:
                    self.mock_gps.gps.updatePosition(dist, self.last_heading)
                    self.last_gps_position = self.mock_gps.gps
                return ('move', int((dist / 0.25)), 0.0)
            else:
                if self.sim_gps:
                    self.mock_gps.gps.updatePosition(5, self.last_heading)
                    self.last_gps_position = self.mock_gps.gps
                return('move', 20, 0.0)
    def checkDetections(self):
        needsRecheck = False
        self.get_logger().info('Checking for Obstacle')

        if not self.detections:
            return (0,0,0) # All clear
        else:
            tempDetections = self.detections
            for detection in tempDetections:
                isMoving = False
                p = [0,0]
                q = [detection.z, detection.x]
                distance = dist(p,q)
                if(distance < 6 and detection.z < 0.75):
                    needsAvoid = True
                    time.sleep(0.5)
                    temp2 = self.detections
                    for detection2 in temp2:
                        if detection2.tracking_id == detection.tracking_id:
                            p = [0,0]
                            q = [detection.z, detection.x]
                            if(dist(p,q) + 0.2 >= distance and dist(p,q) - 0.2 <= distance):
                                isMoving = False
                            else:
                                isMoving = True
                        else:
                            isGone = True
                angle = degrees(atan2(detection.x, detection.z))
                if isGone is True:
                    needsAvoid = False
                    isMoving = False
                    continue
                if isMoving is False and needsAvoid is True and detection.x > 0:
                    return (2, distance, angle) #do move sequence left
                elif isMoving is False and needsAvoid is True and detection.x <= 0:
                    return (3, distance, angle) #do move sequence right
                elif needsAvoid is False and isMoving is False:
                    continue
                elif isMoving is True:
                    needsRecheck = True
                    continue 
                else:
                    continue
            if needsRecheck is True:
                self.checkDetections()
            else:
                return (1, 0, 0) # Obstacles but no need to avoid
    def avoidObstacle(self, code, distance, angle):
        if code == 0 or code == 1:
            return
        elif code == 2: #left
            self.get_logger().info('Avoiding Obstacle Left')
            self.send_request('turnLeft', 0, 30.0)
            if self.sim_imu:
                self.mock_imu.sensor_9DoF.changeHeading(-30)
                self.last_heading, _, _ = self.mock_imu.checkEuler()
            self.wait_for_response()
            return
        elif code == 3: #right
            self.get_logger().info('Avoiding Obstacle Right')
            self.send_request('turnRight', 0, 30.0)
            self.mock_imu.sensor_9DoF.changeHeading(30)
            self.last_heading, _, _ = self.mock_imu.checkEuler()
            self.wait_for_response()
            return
        
def main(args=None):
    rclpy.init(args=args)

    spider_nav_main = Spider_Nav_Main()
    i = 0
    code = -1
    while (all(spider_nav_main.waypointGoalList) != True):
        spider_nav_main.get_logger().info('Move %d' % (i))
        code, distance, angle = spider_nav_main.checkDetections()
        while code != 0 and code != 1:
            spider_nav_main.avoidObstacle(code, distance, angle)
            code, distance, angle = spider_nav_main.checkDetections()
            if code == 0 or code == 1:
                spider_nav_main.send_request('move', 10)
                spider_nav_main.wait_for_response()
                break
        move, amount, deltaAngle = spider_nav_main.decideMove()
        spider_nav_main.get_logger().info('Move %s, amount: %d, deltaAngle: %f' % (move, amount, deltaAngle))
        spider_nav_main.send_request(str(move), int(amount), float(deltaAngle))
        spider_nav_main.wait_for_response()
        for j in range(len(spider_nav_main.waypointGoalList)):
            spider_nav_main.get_logger().info('%d' % spider_nav_main.waypointGoalList[j])
        i += 1

    spider_nav_main.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()