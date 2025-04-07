import threading
from adafruit_servokit import ServoKit

def moveServo(driver, servo, goal_angle):
        startAngle = 0
        if (driver.servo[servo].angle > goal_angle):
            for i in range (startAngle, goal_angle, 1):
                driver.servo[servo].angle +=1
        elif (driver.servo[servo].angle < goal_angle):
            for i in range (startAngle, goal_angle, 1):
                driver.servo[servo].angle -=1

if __name__ == "__main__":
    pca = ServoKit(channels=16, address=0x40)

    t1 = threading.Thread(target=moveServo, args=(pca, 0, 150))
    #t2 = threading.Thread(target=moveServo, args=(pca, 1, 150))

    t1.start()
    #t2.start()

    t1.join()
    #t2.join()
