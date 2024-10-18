import rclpy
from std_msgs.msg import String
from rclpy.node import Node
from spider_interfaces.msg import LocCommands
from spider_interfaces.srv import LocService
from sensor_msgs.msg import Imu
from locomotion.locomotionController import LocomotionController
from geometry_msgs.msg import Quaternion
import math


class LocomotionService(Node):

    def __init__(self):
        super().__init__('locomotion_service')

        self.declare_parameter('sim_imu', False)
        self.declare_parameter('sim_driver', False)

        self.sim_imu = self.get_parameter('sim_imu').value
        self.sim_driver = self.get_parameter('sim_driver').value
        if self.sim_imu is False:
            self.imu_subscription = self.create_subscription(
                    Imu,
                    '/imu',
                    self.imu_callback,
                    1
                )
        self.move_type = "stop"
        self.move_amount = 1
        self.srv = self.create_service(LocService, 'LocService', self.loc_service_callback)
        self.lc = LocomotionController(0x40,0x43,0x41,0x42,0x39, self.sim_driver, self.sim_imu, False)
        self.last_heading = 0.0

    def loc_service_callback(self, request, response):
        self.get_logger().info('Incoming request\nmove type: %s move amount: %d delta angle %f' % (request.move_type.data, request.move_amount, request.delta_angle))
        self.lc.serviceSelect(request.move_type.data, request.move_amount, request.delta_angle)
        response.status = String()
        response.status.data = 'Great Success!'
        return response
    def imu_callback(self, msg: Imu):
        """
        Callback to store the last heading
        """
        _, _, self.last_heading = self.euler_from_quaternion(msg.orientation)
        self.lc.updateHeading(self.last_heading)
    def euler_from_quaternion(self, q: Quaternion):
        """
        Convert a quaternion into euler angles
        taken from: https://automaticaddison.com/how-to-convert-a-quaternion-into-euler-angles-in-python/
        """
        t0 = +2.0 * (q.w * q.x + q.y * q.z)
        t1 = +1.0 - 2.0 * (q.x * q.x + q.y * q.y)
        roll_x = math.atan2(t0, t1)

        t2 = +2.0 * (q.w * q.y - q.z * q.x)
        t2 = +1.0 if t2 > +1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        pitch_y = math.asin(t2)

        t3 = +2.0 * (q.w * q.z + q.x * q.y)
        t4 = +1.0 - 2.0 * (q.y * q.y + q.z * q.z)
        yaw_z = math.atan2(t3, t4)

        return roll_x, pitch_y, yaw_z


def main(args=None):
    rclpy.init(args=args)

    locomotion_service = LocomotionService()

    rclpy.spin(locomotion_service)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    locomotion_service.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
