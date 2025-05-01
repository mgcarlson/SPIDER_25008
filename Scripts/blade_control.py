import serial
import time

ser = serial.Serial('/dev/ttyACM0',9600, timeout=1)

time.sleep(2)

#Send
ser.write(b'B\n')
print("SentF")

print("Arduino says:", ser.readline().decode().strip())

time.sleep(10)
ser.write(b'S\n')
print("Sent Stop")

ser.close()

print("Bye")
