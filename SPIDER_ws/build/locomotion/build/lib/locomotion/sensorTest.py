import board
from adafruit_tca9548a import TCA9548A
from adafruit_as7341 import AS7341


i2c = board.I2C() 
tca = TCA9548A(i2c)


spec = []
spec.append(AS7341(tca[0]))
spec.append(AS7341(tca[1]))
spec.append(AS7341(tca[2]))
sum = 0
for sensor in spec:
    print("sensor %d = %d" % (sensor, spec[sensor].channel_415))
    sum += spec[sensor].channel_415
print("average %f" % (sum / 3))
