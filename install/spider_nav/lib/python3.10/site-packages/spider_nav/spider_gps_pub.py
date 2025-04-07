import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix, NavSatStatus
from std_msgs.msg import Header
from spider_nav.utils.adafruit_gps_ros import Adafruit_Gps_Ros
import time

class SpiderGPSPublisher(Node):

    def __init__(self):
        super().__init__('spider_gps_publisher')
        self.publisher_ = self.create_publisher(NavSatFix, 'gps/fix', 10)
        
        self.declare_parameter('sim_gps', False)
        self.simBool = self.get_parameter('sim_gps').value

        self.sensor = Adafruit_Gps_Ros(self.simBool)

        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        self.lastPrint = time.monotonic()

    def timer_callback(self):
        current = time.monotonic()
        if(current - self.lastPrint >= 1):
            self.lastPrint = current
            if self.simBool == False:
                if (self.sensor.gps.update()):
                    if(self.sensor.gps.read(32) is not None):
                        self.logGpsData()
            else:
                self.logGpsData()
            #set a bunch of variables
            tempNavStatus = NavSatStatus()
            tempNavStatus.status = self.sensor.setFix()
            tempNavStatus.service = 1
            tempHeader = Header()
            tempHeader.stamp = self.get_clock().now().to_msg()
            tempHeader.frame_id = "SPIDER_GPS"
            msg = NavSatFix()
            msg.header = tempHeader
            msg.status = tempNavStatus
            if (self.sensor.gps.longitude is not None):
                msg.longitude = self.sensor.gps.longitude
            if (self.sensor.gps.latitude is not None):
                msg.latitude = self.sensor.gps.latitude
            if (self.sensor.gps.altitude_m is not None):
                msg.altitude = self.sensor.gps.altitude_m
            if (self.sensor.gps.pdop is not None):
                msg.position_covariance = self.sensor.setCovariance()
            msg.position_covariance_type = 1

            self.publisher_.publish(msg)
            self.i += 1

    def logGpsData(self):
        self.get_logger().info("=" * 40)  # self.get_logger().info a separator line.
        if (self.sensor.gps.longitude is not None):
            self.get_logger().info("Longitude: {0:.6f} degrees".format(self.sensor.gps.longitude))
        if (self.sensor.gps.latitude is not None):
            self.get_logger().info("Latitude: {0:.6f} degrees".format(self.sensor.gps.latitude))
        if self.simBool is False:
            if (self.sensor.gps.fix_quality is not None):
                self.get_logger().info("Fix quality: {}".format(self.sensor.gps.fix_quality))
            if self.sensor.gps.satellites is not None:
                self.get_logger().info("# satellites: {}".format(self.sensor.gps.satellites))
            if self.sensor.gps.altitude_m is not None:
                self.get_logger().info("Altitude: {} meters".format(self.sensor.gps.altitude_m))
            if self.sensor.gps.speed_knots is not None:
                self.get_logger().info("Speed: {} knots".format(self.sensor.gps.speed_knots))
            if self.sensor.gps.track_angle_deg is not None:
                self.get_logger().info("Track angle: {} degrees".format(self.sensor.gps.track_angle_deg))
            if self.sensor.gps.horizontal_dilution is not None:
                self.get_logger().info("Horizontal dilution: {}".format(self.sensor.gps.horizontal_dilution))
            if self.sensor.gps.height_geoid is not None:
                self.get_logger().info("Height geoid: {} meters".format(self.sensor.gps.height_geoid))
def main(args=None):
    rclpy.init(args=args)

    spider_gps_publisher = SpiderGPSPublisher()

    rclpy.spin(spider_gps_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    spider_gps_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()