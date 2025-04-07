import sys

from spider_interfaces.srv import LocService
import rclpy
from rclpy.node import Node


class navClientAsync(Node):

    def __init__(self):
        super().__init__('nav_client_async')
        self.cli = self.create_client(LocService, 'LocService')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = LocService.Request()

    def send_request(self, move_type, move_amount, delta_angle):
        self.req.move_type.data = move_type
        self.req.move_amount = move_amount
        self.req.delta_angle = delta_angle
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()


def main(args=None):
    rclpy.init(args=args)

    nav_client = navClientAsync()
    response = nav_client.send_request(sys.argv[1], int(sys.argv[2]), float(sys.argv[3]))
    
    nav_client.get_logger().info('Cool? "%s"' % response.status.data)

    nav_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()