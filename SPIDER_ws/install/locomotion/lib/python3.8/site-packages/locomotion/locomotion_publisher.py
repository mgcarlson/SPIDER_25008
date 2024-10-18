import rclpy
from rclpy.node import Node
from spider_interfaces.msg import LocCommands
from spider_interfaces.srv import LocService


class LocomotionPublisher(Node):

    def __init__(self):
        super().__init__('locomotion_publisher')
        self.publisher_ = self.create_publisher(LocCommands, 'LocCommands', 10)
        timer_period = 25.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        self.move_type = "stop"
        self.move_amount = 5
        self.srv = self.create_service(LocService, 'LocService', self.loc_service_callback)

    def loc_service_callback(self, request, response):
        self.get_logger().info('Incoming request\na: %s b: %d' % (request.move_type.data, request.move_amount))
        self.update_msg(request.move_type.data, request.move_amount)
        response.status = "Great Success"
        return response

    def update_msg(self, move_type, move_amount): # update the message so that the service data is now in there
        self.move_type = move_type
        self.move_amount = move_amount

    def timer_callback(self): # callback function to publish the message for the subscriber
        msg = LocCommands()
        msg.move_type.data = self.move_type
        msg.move_amount = self.move_amount
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s" for %d moves' % (msg.move_type.data, msg.move_amount))
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    locomotion_publisher = LocomotionPublisher()

    rclpy.spin(locomotion_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    locomotion_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()