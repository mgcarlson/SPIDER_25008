import time
import board
import busio

import adafruit_ads1x15.ads1015 as ADS
#from adafruit_ads1x15 import ads as ADS
from adafruit_ads1x15.analog_in import AnalogIn
#from adafruit_blinka.microcontroller.generic_linux.i2c import I2C


i2c = busio.I2C(board.SCL, board.SDA)
#i2c = I2C(0)
ads = ADS.ADS1015(i2c)

ads.gain = 2/3 

chan = AnalogIn(ads, ADS.P0)

while True:
    print(f"Voltage: {chan.voltage:.3f}V")
    time.sleep(1)
