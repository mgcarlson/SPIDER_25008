import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2)

ser.write(b'1')
time.sleep(2)
ser.write(b'0')
time.sleep(1)
ser.close()
print("hello done")
