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


if __name__ == "__main__":
    #driver0 actions
    #horizontals
    #rs
    driver0.servo[0].set_pulse_width_range(500, 2500)
    driver0.servo[0].angle = 140
    #ls
    driver0.servo[2].set_pulse_width_range(500, 2500)
    driver0.servo[2].angle = 103
    #mid
    driver0.servo[4].set_pulse_width_range(500, 2500)
    print("hello")
    driver0.servo[4].angle = 93
