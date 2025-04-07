import time 
from adafruit_servokit import ServoKit
import busio
import board
import adafruit_motor.servo

i2c_bus = busio.I2C(board.SCL, board.SDA)

#drivers = {
        #0x40: ServoKit(channels=16, address=0x40, i2c=i2c_bus),
        #0x41: ServoKit(channels=16, address=0x41, i2c=i2c_bus),
        #0x42: ServoKit(channels=16, address=0x42, i2c=i2c_bus),
        #0x43: ServoKit(channels=16, address=0x43, i2c=i2c_bus),
        #}
driver0 = ServoKit(channels=16, address=0x40, i2c=i2c_bus)
driver1 = ServoKit(channels=16, address=0x41, i2c=i2c_bus)
driver2 = ServoKit(channels=16, address=0x42, i2c=i2c_bus)
driver3 = ServoKit(channels=16, address=0x43, i2c=i2c_bus)


def move_servo(driver, servo, goal_angle):
    startAngle = int(driver.servo[servo].angle)
    print(startAngle)
    step = 1 if goal_angle > startAngle else -1
    for i in range(startAngle, goal_angle, step):
        print(i)
        driver.servo[servo].angle = i
        time.sleep(0.02)

if __name__ == "__main__":
    #servo = adafruit_motor.servo.Servo(0)
    #for addr, kit in drivers.items():
       # for servo in range(0, 12, 2):
    #move_servo(kit, servo, 120)
    #driver.servo[0].angle = 180
    #startAngle = int(driver2.servo[4].angle

    #BEGIN INITIALIZING MOTORS
    
    #driver0 actions
    #horizontals
    #l1
    driver0.servo[0].set_pulse_width_range(500, 2500)
    driver0.servo[0].angle = 90
    #l2
    driver0.servo[6].set_pulse_width_range(500, 2500)
    driver0.servo[6].angle = 90
    #verticals
    #l1
    driver0.servo[2].set_pulse_width_range(500, 2500)
    driver0.servo[2].angle = 135
    #l2
    driver0.servo[8].set_pulse_width_range(500, 2500)
    driver0.servo[8].angle = 135
    #elbows
    #l1
    driver0.servo[4].set_pulse_width_range(500, 2500)
    driver0.servo[4].angle = 110
    #l2
    driver0.servo[10].set_pulse_width_range(500, 2500)
    driver0.servo[10].angle = 115
    
    #driver1 actions
    #horizontals
    #r1
    driver1.servo[0].set_pulse_width_range(500, 2500)
    driver1.servo[0].angle = 90
    #r2
    driver1.servo[6].set_pulse_width_range(500, 2500)
    driver1.servo[6].angle = 100
    #verticals
    #r1
    driver1.servo[2].set_pulse_width_range(500, 2500)
    driver1.servo[2].angle = 45
    #r2
    driver1.servo[8].set_pulse_width_range(500, 2500)
    driver1.servo[8].angle = 45
    #elbows
    #r1
    driver1.servo[4].set_pulse_width_range(500, 2500)
    driver1.servo[4].angle = 60
    #r2
    driver1.servo[10].set_pulse_width_range(500, 2500)
    driver1.servo[10].angle = 60
    
    #driver 2 actions
    #horizontals
    #r3
    driver2.servo[0].set_pulse_width_range(500, 2500)
    driver2.servo[0].angle = 80
    #r4
    driver2.servo[6].set_pulse_width_range(500, 2500)
    driver2.servo[6].angle = 90
    #verticals
    #r3
    driver2.servo[2].set_pulse_width_range(500, 2500)
    driver2.servo[2].angle = 50
    #r4
    driver2.servo[8].set_pulse_width_range(500, 2500)
    driver2.servo[8].angle = 40
    #elbows
    #r3
    driver2.servo[4].set_pulse_width_range(500, 2500)
    driver2.servo[4].angle = 75
    #r4
    driver2.servo[10].set_pulse_width_range(500, 2500)
    driver2.servo[10].angle = 60

    #driver3 actions
    #horizontals
    #l3
    driver3.servo[0].set_pulse_width_range(500, 2500)
    driver3.servo[0].angle = 85
    #l4
    driver3.servo[6].set_pulse_width_range(500, 2500)
    driver3.servo[6].angle = 90
    #verticals
    #l3
    driver3.servo[2].set_pulse_width_range(500, 2500)
    driver3.servo[2].angle = 130
    #l4
    driver3.servo[8].set_pulse_width_range(500, 2500)
    driver3.servo[8].angle = 130
    #elbows
    #l3
    driver3.servo[4].set_pulse_width_range(500, 2500)
    driver3.servo[4].angle = 105
    #l4
    driver3.servo[10].set_pulse_width_range(500, 2500)
    driver3.servo[10].angle = 105
