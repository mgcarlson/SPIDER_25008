import rclpy
import subprocess
from rclpy.node import Node
from data_transfer.SpectrometerStack import SpectrometerStack
from std_msgs.msg import String
from sensor_msgs.msg import NavSatFix, Imu
from spider_nav.utils.gps_utils import euler_from_quaternion
import csv

class SubscribeTransfer(Node):

    def __init__(self):
        super().__init__('subscribe_transfer')
        
        self.declare_parameter('sim_data', False)
        self.simBool = self.get_parameter('sim_data').value

        self.data_command_subscription = self.create_subscription(
            String,
            'commitCommand',
            self.listener_callback,
            10)
        self.gps_subscription = self.create_subscription(
            NavSatFix,
            '/gps/fix',
            self.gps_callback,
            1
            )
        self.imu_subscription = self.create_subscription(
            Imu,
            '/imu',
            self.imu_callback,
            1
            )
        self.spec_array = SpectrometerStack(self.simBool)
        self.last_gps_position = NavSatFix()
        self.last_heading = 0.0

    def listener_callback(self, msg):
        self.get_logger().info('Received Command: "%s"' % msg.data)
        seconds = self.get_clock().now().to_msg().sec + self.get_clock().now().to_msg().nanosec / 1000000000
        self.spec_array.collect_and_write(seconds)
        self.convert_gps_imu_to_file(seconds)
        rc = subprocess.call("/home/dfolse/repos/SPIDER/Scripts/uploadData.sh")
        if (rc == 0):
            self.get_logger().info('Successfully pushed new data')
        else:
            self.get_logger().info('No Connection, waiting for connection to push')
    def convert_gps_imu_to_file(self, seconds):
        fileName = "/home/dfolse/repos/SPIDER_Data/raw/gps_data_%d.csv" % int(seconds)
        with open(fileName, "w", newline='') as file:
            csv_writer = csv.writer(file)
            csv_writer.writerow(["TimeStamp", "Latitude", "Longitude", "Angle"])
            csv_writer.writerow([f"{seconds:.3f}", self.last_gps_position.latitude, self.last_gps_position.latitude, self.last_heading])
        return
    
    def gps_callback(self, msg: NavSatFix):
        """
        Callback to store the last GPS pose
        """
        self.last_gps_position = msg

    def imu_callback(self, msg: Imu):
        """
        Callback to store the last heading
        """
        _, _, self.last_heading = euler_from_quaternion(msg.orientation)


def main(args=None):
    rclpy.init(args=args)

    subscribe_transfer = SubscribeTransfer()

    rclpy.spin(subscribe_transfer)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    subscribe_transfer.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
