import time
from adafruit_servokit import ServoKit
from adafruit_motor import servo
import threading
from . import  MockServoDriver

STOP_ELB_ANGLE = 150
STOP_VERT_ANGLE = 126
STOP_HORIZ_ANGLE = 90

VERT_UP_ANGLE = 141
VERT_DOWN_ANGLE = 126

HORIZ_FORW_ANGLE = 105
HORIZ_SHIFT1_ANGLE = 95
HORIZ_HALF_ANGLE = 90
HORIZ_SHIFT2_ANGLE = 85
HORIZ_BACK_ANGLE = 75

ELB_OUT_ANGLE = 135
ELB_SHIFT1_ANGLE = 140
ELB_HALF_ANGLE = 142
ELB_SHIFT2_ANGLE = 145
ELB_IN_ANGLE = 150

DELAY = 0.1

#0 HORIZ, 1 VERT, 2 ELB
# PCA2 0x41
# 0,1,2 Front Right
# 3,4,5 3rd Right

# PCA3 0x42
# 0,1,2 2nd set right
# 3,4,5 Back Right

# PCA1 0x40
# 0,1,2 Front Left
# 3,4,5 3rd Left

# PCA4 0x43
# 0,1,2 2nd set left
# 3,4,5 Back Left

class servoControllerRight:
  def __init__(self, address):
    self.N = 6
    self.rest_pos = [STOP_HORIZ_ANGLE, STOP_VERT_ANGLE, STOP_ELB_ANGLE,
                      STOP_HORIZ_ANGLE, STOP_VERT_ANGLE, STOP_ELB_ANGLE]
    #self.driver = ServoKit(channels=16, address=address)
    self.driver = MockServoDriver.MockServoDriver(channels=16, address=address)

  def moveForwardFront(self):
    moveHalfHoriz = threading.Thread(target=self.moveServo, args=(self.driver, 0, HORIZ_HALF_ANGLE))
    moveFullHoriz = threading.Thread(target=self.moveServo, args=(self.driver, 0, HORIZ_FORW_ANGLE))
    moveElb       = threading.Thread(target=self.moveServo, args=(self.driver, 2, ELB_OUT_ANGLE))
    moveVertUp    = threading.Thread(target=self.moveServo, args=(self.driver, 1, VERT_UP_ANGLE))
    moveVertDown  = threading.Thread(target=self.moveServo, args=(self.driver, 1, VERT_DOWN_ANGLE))

    moveBackHoriz = threading.Thread(target=self.moveServo, args=(self.driver, 3, HORIZ_BACK_ANGLE))
    moveBackElb = threading.Thread(target=self.moveServo, args=(self.driver, 5, ELB_OUT_ANGLE))

    moveVertUp.start()
    moveHalfHoriz.start()
    moveElb.start()

    moveVertUp.join()
    moveHalfHoriz.join()
    moveElb.join()

    moveBackHoriz.start()
    moveBackElb.start()
    moveFullHoriz.start()
    moveVertDown.start()

    moveBackHoriz.join()
    moveBackElb.join()
    moveFullHoriz.join()
    moveVertDown.join()
    return
  
  def moveForwardBack(self):
    moveHalfHoriz = threading.Thread(target=self.moveServo, args=(self.driver, 3, HORIZ_HALF_ANGLE))
    moveFullHoriz = threading.Thread(target=self.moveServo, args=(self.driver, 3, HORIZ_FORW_ANGLE))
    moveElb       = threading.Thread(target=self.moveServo, args=(self.driver, 5, ELB_OUT_ANGLE))
    moveVertUp    = threading.Thread(target=self.moveServo, args=(self.driver, 2, VERT_UP_ANGLE))
    moveVertDown  = threading.Thread(target=self.moveServo, args=(self.driver, 2, VERT_DOWN_ANGLE))

    moveShift1Horiz = threading.Thread(target=self.moveServo, args=(self.driver, 0, HORIZ_SHIFT1_ANGLE))
    moveShift1Elb = threading.Thread(target=self.moveServo, args=(self.driver, 2, ELB_SHIFT1_ANGLE))

    moveVertUp.start()
    moveHalfHoriz.start()
    moveElb.start()

    moveVertUp.join()
    moveHalfHoriz.join()
    moveElb.join()

    moveShift1Horiz.start()
    moveShift1Elb.start()
    moveFullHoriz.start()
    moveVertDown.start()

    moveShift1Horiz.join()
    moveShift1Elb.join()
    moveFullHoriz.join()
    moveVertDown.join()
    return
  def moveForwardShift1(self):
    moveShift2Horiz = threading.Thread(target=self.moveServo, args=(self.driver, 0, HORIZ_SHIFT2_ANGLE))
    moveShift2Elb = threading.Thread(target=self.moveServo, args=(self.driver, 2, ELB_SHIFT2_ANGLE))
    moveShift1Horiz = threading.Thread(target=self.moveServo, args=(self.driver, 3, HORIZ_SHIFT1_ANGLE))
    moveShift1Elb = threading.Thread(target=self.moveServo, args=(self.driver, 5, ELB_SHIFT1_ANGLE))

    moveShift1Horiz.start()
    moveShift1Elb.start()
    moveShift2Horiz.start()
    moveShift2Elb.start()

    moveShift1Horiz.join()
    moveShift1Elb.join()
    moveShift2Horiz.join()
    moveShift2Elb.join()
    return

  def moveForwardShift2(self):
    moveShift2Horiz = threading.Thread(target=self.moveServo, args=(self.driver, 3, HORIZ_SHIFT2_ANGLE))
    moveShift2Elb = threading.Thread(target=self.moveServo, args=(self.driver, 5, ELB_SHIFT2_ANGLE))
    moveBackHoriz = threading.Thread(target=self.moveServo, args=(self.driver, 0, HORIZ_BACK_ANGLE))
    moveOutElb = threading.Thread(target=self.moveServo, args=(self.driver, 2, ELB_OUT_ANGLE))

    moveBackHoriz.start()
    moveOutElb.start()
    moveShift2Horiz.start()
    moveShift2Elb.start()

    moveBackHoriz.join()
    moveOutElb.join()
    moveShift2Horiz.join()
    moveShift2Elb.join()
    return 
  
  def turnRight(self):
    moveHalfHoriz = threading.Thread(target=self.moveServo, args=(self.driver, 0, HORIZ_HALF_ANGLE))
    moveFullHoriz = threading.Thread(target=self.moveServo, args=(self.driver, 0, HORIZ_BACK_ANGLE))
    moveElbIn     = threading.Thread(target=self.moveServo, args=(self.driver, 2, ELB_IN_ANGLE))
    moveVertUp    = threading.Thread(target=self.moveServo, args=(self.driver, 1, VERT_UP_ANGLE))
    moveVertDown  = threading.Thread(target=self.moveServo, args=(self.driver, 1, VERT_DOWN_ANGLE))

    moveHalfHoriz2 = threading.Thread(target=self.moveServo, args=(self.driver, 3, HORIZ_HALF_ANGLE))
    moveFullHoriz2 = threading.Thread(target=self.moveServo, args=(self.driver, 3, HORIZ_BACK_ANGLE))
    moveElbIn2     = threading.Thread(target=self.moveServo, args=(self.driver, 5, ELB_IN_ANGLE))
    moveVertUp2    = threading.Thread(target=self.moveServo, args=(self.driver, 4, VERT_UP_ANGLE))
    moveVertDown2  = threading.Thread(target=self.moveServo, args=(self.driver, 4, VERT_DOWN_ANGLE))

    moveHalfHoriz.start()
    moveVertUp.start()
    moveElbIn.start()
    
    moveHalfHoriz.join()
    moveVertUp.join()
    moveElbIn.join()

    moveFullHoriz.start()
    moveVertDown.start()

    moveFullHoriz.join()
    moveVertDown.join()

    time.sleep(0.5)

    moveHalfHoriz2.start()
    moveVertUp2.start()
    moveElbIn2.start()
    
    moveHalfHoriz2.join()
    moveVertUp2.join()
    moveElbIn2.join()

    moveFullHoriz2.start()
    moveVertDown2.start()

    moveFullHoriz2.join()
    moveVertDown2.join()
    return
  def turnLeft(self):
    moveHalfHoriz = threading.Thread(target=self.moveServo, args=(self.driver, 0, HORIZ_HALF_ANGLE))
    moveFullHoriz = threading.Thread(target=self.moveServo, args=(self.driver, 0, HORIZ_FORW_ANGLE))
    moveElbIn     = threading.Thread(target=self.moveServo, args=(self.driver, 2, ELB_IN_ANGLE))
    moveVertUp    = threading.Thread(target=self.moveServo, args=(self.driver, 1, VERT_UP_ANGLE))
    moveVertDown  = threading.Thread(target=self.moveServo, args=(self.driver, 1, VERT_DOWN_ANGLE))

    moveHalfHoriz2 = threading.Thread(target=self.moveServo, args=(self.driver, 3, HORIZ_HALF_ANGLE))
    moveFullHoriz2 = threading.Thread(target=self.moveServo, args=(self.driver, 3, HORIZ_FORW_ANGLE))
    moveElbIn2     = threading.Thread(target=self.moveServo, args=(self.driver, 5, ELB_IN_ANGLE))
    moveVertUp2    = threading.Thread(target=self.moveServo, args=(self.driver, 4, VERT_UP_ANGLE))
    moveVertDown2  = threading.Thread(target=self.moveServo, args=(self.driver, 4, VERT_DOWN_ANGLE))

    moveHalfHoriz.start()
    moveVertUp.start()
    moveElbIn.start()
    
    moveHalfHoriz.join()
    moveVertUp.join()
    moveElbIn.join()

    moveFullHoriz.start()
    moveVertDown.start()

    moveFullHoriz.join()
    moveVertDown.join()

    time.sleep(0.5)

    moveHalfHoriz2.start()
    moveVertUp2.start()
    moveElbIn2.start()
    
    moveHalfHoriz2.join()
    moveVertUp2.join()
    moveElbIn2.join()

    moveFullHoriz2.start()
    moveVertDown2.start()

    moveFullHoriz2.join()
    moveVertDown2.join()
    return
  def stop(self):
    print("stopping driver at address " + self.driver.address)
    for i in range(self.N):
      self.driver.servo[i].angle = self.rest_pos(i)
    return
  
  def moveServo(self, servo, goal_angle):
    print("moving driver at address " + self.driver.address + "to " + goal_angle)
    if self.driver.servo[servo].angle > goal_angle:
      for i in range(self.driver.servo[servo].angle, goal_angle, -1):
        self.driver.servo[servo].angle = i
        time.sleep(DELAY)
    else:
      for i in range(self.driver.servo[servo].angle, goal_angle, 1):
        self.driver.servo[servo].angle = i
        time.sleep(DELAY)
    return





