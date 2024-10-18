import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Quaternion, Vector3
from std_msgs.msg import Header
from locomotion.servoLeveler import ServoLeveler

import time

class SpiderIMUPublisher(Node):

    def __init__(self):
        super().__init__('spider_imu_publisher')
        self.publisher_ = self.create_publisher(Imu, 'imu', 10)

        self.declare_parameter('sim_imu', False)
        self.simBool = self.get_parameter('sim_imu').value

        self.sensor = ServoLeveler(0x28, self.simBool)

        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        #set a bunch of variables
        cal_z, cal_w, cal_yaw = self.sensor.calibrate_orientation()
        tempQuatTuple = self.sensor.sensor_9DoF.quaternion
        tempQuaternion = Quaternion()
        #tempQuaternion.w = cal_w
        tempQuaternion.w = tempQuatTuple[0]
        tempQuaternion.x = tempQuatTuple[1]
        tempQuaternion.y = tempQuatTuple[2]
        #tempQuaternion.z = cal_z
        tempQuaternion.z = tempQuatTuple[3]

        tempAngTuple = self.sensor.sensor_9DoF.gyro
        tempAngVel = Vector3()
        tempAngVel.x = tempAngTuple[0]
        tempAngVel.y = tempAngTuple[1]
        tempAngVel.z = tempAngTuple[2]

        tempAccTuple = self.sensor.sensor_9DoF.linear_acceleration
        tempAcc = Vector3()
        tempAcc.x = tempAccTuple[0]
        tempAcc.y = tempAccTuple[1]
        tempAcc.z = tempAccTuple[2]

        currTime = self.get_clock().now()
        tempHeader = Header()
        tempHeader.stamp = currTime.to_msg()
        tempHeader.frame_id = "SPIDER_IMU"
        msg = Imu()
        msg.header = tempHeader
        msg.orientation = tempQuaternion
        msg.angular_velocity = tempAngVel
        msg.linear_acceleration = tempAcc

        msg.orientation_covariance[0] = -1
        msg.linear_acceleration_covariance[0] = -1
        msg.angular_velocity_covariance[0] = -1

        self.publisher_.publish(msg)
        self.logImuData(cal_z, tempAngTuple, tempAccTuple, currTime.seconds_nanoseconds())
        self.i += 1

    def logImuData(self, heading, angTuple, accTuple, currTime):
        self.get_logger().info("=" * 40)  # self.get_logger().info a separator line.
        
        self.get_logger().info("Time: ")
        self.get_logger().info(self.convertTuple(currTime))

        self.get_logger().info("Orientation: ")
        self.get_logger().info(str(heading))
        
        self.get_logger().info("Velocity: ")
        self.get_logger().info(self.convertTuple(angTuple))

        self.get_logger().info("Acceleration: ")
        self.get_logger().info(self.convertTuple(accTuple))

    def convertTuple(self, tempTup):
        sep = ', '
        return sep.join(map(str, tempTup))
def main(args=None):
    rclpy.init(args=args)

    spider_imu_publisher = SpiderIMUPublisher()

    rclpy.spin(spider_imu_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    spider_imu_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
