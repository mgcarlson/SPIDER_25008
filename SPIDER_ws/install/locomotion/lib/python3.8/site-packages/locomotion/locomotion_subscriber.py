import rclpy
from rclpy.node import Node

import time
import threading
from . import servoControllerRight, servoControllerLeft
from spider_interfaces.msg import LocCommands
from adafruit_servokit import ServoKit


class LocomotionSubscriber(Node):

    def __init__(self):
        #pcaA1=servoControllerLeft(0x40) #initialize class
        #pcaB1=servoControllerLeft(0x41)
        #pcaB2=servoControllerRight(0x42)
        #pcaA2=servoControllerRight(0x43)
        pcaA1=servoControllerLeft.servoControllerLeft(40) #initialize class
        pcaB1=servoControllerLeft.servoControllerLeft(41)
        pcaB2=servoControllerRight.servoControllerRight(42)
        pcaA2=servoControllerRight.servoControllerRight(43)

        self.pcaA1_move1     = threading.Thread(target=pcaA1.moveForwardFront)
        self.pcaA1_move2     = threading.Thread(target=pcaA1.moveForwardBack)
        self.pcaA1_move3     = threading.Thread(target=pcaA1.moveForwardShift1)
        self.pcaA1_move4     = threading.Thread(target=pcaA1.moveForwardShift2)        
        self.pcaA1_stop      = threading.Thread(target=pcaA1.stop)
        self.pcaA1_turnRight = threading.Thread(target=pcaA1.turnRight)
        self.pcaA1_turnLeft  = threading.Thread(target=pcaA1.turnLeft)
        
        self.pcaB1_move1     = threading.Thread(target=pcaB1.moveForwardFront)
        self.pcaB1_move2     = threading.Thread(target=pcaB1.moveForwardBack)
        self.pcaB1_move3     = threading.Thread(target=pcaB1.moveForwardShift1)
        self.pcaB1_move4     = threading.Thread(target=pcaB1.moveForwardShift2)
        self.pcaB1_stop      = threading.Thread(target=pcaB1.stop)
        self.pcaB1_turnRight = threading.Thread(target=pcaB1.turnRight)
        self.pcaB1_turnLeft  = threading.Thread(target=pcaB1.turnLeft)

        self.pcaA2_move1     = threading.Thread(target=pcaA2.moveForwardFront)
        self.pcaA2_move2     = threading.Thread(target=pcaA2.moveForwardBack)
        self.pcaA2_move3     = threading.Thread(target=pcaA2.moveForwardShift1)
        self.pcaA2_move4     = threading.Thread(target=pcaA2.moveForwardShift2)
        self.pcaA2_stop      = threading.Thread(target=pcaA2.stop)
        self.pcaA2_turnRight = threading.Thread(target=pcaA2.turnRight)
        self.pcaA2_turnLeft  = threading.Thread(target=pcaA2.turnLeft)

        self.pcaB2_move1     = threading.Thread(target=pcaB2.moveForwardFront)
        self.pcaB2_move2     = threading.Thread(target=pcaB2.moveForwardBack)
        self.pcaB2_move3     = threading.Thread(target=pcaB2.moveForwardShift1)
        self.pcaB2_move4     = threading.Thread(target=pcaB2.moveForwardShift2)
        self.pcaB2_stop      = threading.Thread(target=pcaB2.stop)
        self.pcaB2_turnRight = threading.Thread(target=pcaB2.turnRight)
        self.pcaB2_turnLeft  = threading.Thread(target=pcaB2.turnLeft)

        super().__init__('locomotion_subscriber')
        self.subscription = self.create_subscription(
            LocCommands,
            'LocCommands',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info('Move Command: "%s"' % msg.move_type.data)
        for i in range(msg.move_amount):
            if msg.move_type.data == "move": #move forward
                self.pcaA1_move1.start()
                self.pcaA2_move1.start()
                self.pcaB1_move3.start()
                self.pcaB2_move3.start()

                self.pcaA1_move2.join()
                self.pcaA2_move2.join()
                self.pcaB1_move4.join()
                self.pcaB2_move4.join()

                self.pcaA1_move3.start()
                self.pcaA2_move3.start()
                self.pcaB1_move1.start()
                self.pcaB2_move1.start()

                self.pcaA1_move4.join()
                self.pcaA2_move4.join()
                self.pcaB1_move2.join()
                self.pcaB2_move2.join()
                
            elif msg.move_type.data == "turnRight": # turn right
                self.pcaA1_turnRight.start()
                self.pcaA2_turnRight.start()
                self.pcaB1_turnRight.start()
                self.pcaB2_turnRight.start()

                self.pcaA1_turnRight.join()
                self.pcaA2_turnRight.join()
                self.pcaB1_turnRight.join()
                self.pcaB2_turnRight.join()
            elif msg.move_type.data == "turnLeft": # turn left
                self.pcaA1_turnLeft.start()
                self.pcaA2_turnLeft.start()
                self.pcaB1_turnLeft.start()
                self.pcaB2_turnLeft.start()

                self.pcaA1_turnLeft.join()
                self.pcaA2_turnLeft.join()
                self.pcaB1_turnLeft.join()
                self.pcaB2_turnLeft.join()
            else: # stop
                self.pcaA1_stop.start()
                self.pcaA2_stop.start()
                self.pcaB1_stop.start()
                self.pcaB2_stop.start()

                self.pcaA1_stop.join()
                self.pcaA2_stop.join()
                self.pcaB1_stop.join()
                self.pcaB2_stop.join()

def main(args=None):
    rclpy.init(args=args)

    locomotion_subscriber = LocomotionSubscriber()

    rclpy.spin(locomotion_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    locomotion_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()