import rclpy
from rclpy.node import Node
from datetime import datetime
from datetime import timedelta
from std_msgs.msg import String


class PublishTransfer(Node):

    def __init__(self):
        super().__init__('publish_transfer')
        self.publisher_ = self.create_publisher(String, 'commitCommand', 10)
        timer_period = 10  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        now = datetime.now()
        startTime = now - timedelta(minutes = 5)
        timeFormat = '%Y-%m-%d, %H:%M:%S'
        msg = String()
        msg.data = '10 seconds has passed, collect and commit data from %s to %s' % (now.strftime(timeFormat), startTime.strftime(timeFormat))
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    publish_transfer = PublishTransfer()

    rclpy.spin(publish_transfer)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    publish_transfer.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
