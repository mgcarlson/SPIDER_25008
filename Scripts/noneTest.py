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
#driver2 = ServoKit(channels=16, address=0x42, i2c=i2c_bus)
#driver3 = ServoKit(channels=16, address=0x43, i2c=i2c_bus)

if __name__ == "__main__":

    #driver0 actions
    #horizontals
    #l1
    driver0.servo[0].set_pulse_width_range(500, 2500)
    driver0.servo[0].angle = 90
    #l2
    driver0.servo[6].set_pulse_width_range(500, 2500)
    driver0.servo[6].angle = None
    #verticals
    #l1
    driver0.servo[2].set_pulse_width_range(500, 2500)
    driver0.servo[2].angle = None
    #l2
    driver0.servo[8].set_pulse_width_range(500, 2500)
    driver0.servo[8].angle = None
    #elbows
    #l1
    driver0.servo[4].set_pulse_width_range(500, 2500)
    driver0.servo[4].angle = None
    #l2
    driver0.servo[10].set_pulse_width_range(500, 2500)
    driver0.servo[10].angle = None
    
    #drivekr1 actions
    #horizontals
    #r1
    driver1.servo[0].set_pulse_width_range(500, 2500)
    driver1.servo[0].angle = None
    #r2
    driver1.servo[6].set_pulse_width_range(500, 2500)
    driver1.servo[6].angle = None
    #verticals
    #r1
    driver1.servo[2].set_pulse_width_range(500, 2500)
    driver1.servo[2].angle = None
    #r2
    driver1.servo[8].set_pulse_width_range(500, 2500)
    driver1.servo[8].angle = None
    #elbows
    #r1
    driver1.servo[4].set_pulse_width_range(500, 2500)
    driver1.servo[4].angle = None 
    #r2
    driver1.servo[10].set_pulse_width_range(500, 2500)
    driver1.servo[10].angle = None
    '''
    #driver 2 actions
    #horizontals
    #r3
    driver2.servo[0].set_pulse_width_range(500, 2500)
    driver2.servo[0].angle = 90
    #r4
    driver2.servo[6].set_pulse_width_range(500, 2500)
    driver2.servo[6].angle = 90
    #verticals
    #r3
    driver2.servo[2].set_pulse_width_range(500, 2500)
    driver2.servo[2].angle = 90
    #r4
    driver2.servo[8].set_pulse_width_range(500, 2500)
    driver2.servo[8].angle = 90
    #elbows
    #r3
    driver2.servo[4].set_pulse_width_range(500, 2500)
    driver2.servo[4].angle = None
    #r4
    driver2.servo[10].set_pulse_width_range(500, 2500)
    driver2.servo[10].angle = None

    #driver3 actions
    #horizontals
    #l3
    driver3.servo[0].set_pulse_width_range(500, 2500)
    driver3.servo[0].angle = None
    #l4
    driver3.servo[6].set_pulse_width_range(500, 2500)
    driver3.servo[6].angle = None
    #verticals
    #l3
    driver3.servo[2].set_pulse_width_range(500, 2500)
    driver3.servo[2].angle = None
    #l4
    driver3.servo[8].set_pulse_width_range(500, 2500)
    driver3.servo[8].angle = None
    #elbows
    #l3
    driver3.servo[4].set_pulse_width_range(500, 2500)
    driver3.servo[4].angle = None
    #l4
    driver3.servo[10].set_pulse_width_range(500, 2500)
    driver3.servo[10].angle = None
    '''
