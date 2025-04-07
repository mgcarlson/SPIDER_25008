import Jetson.GPIO as GPIO
import time

LED_PIN = 29
#print(GPIO.getmode())
GPIO.setmode(GPIO.BOARD)
#GPIO.cleanup(LED_PIN)
print(GPIO.model)
GPIO.setup(LED_PIN, GPIO.IN)
#GPIO.setup(LED_PIN, GPIO.HIGH)
try: 
    while True:
        cmd = input("Enter 'on', 'off', or 'q'").strip().lower()
        if cmd == 'on':
            GPIO.output(LED_PIN, GPIO.HIGH)
            print("LED ON")
        elif cmd == 'off':
            GPIO.output(LED_PIN, GPIO.LOW)
            print("LED OFF")
        elif cmd == 'q':
            break
        else:
            print("Invalid Command")
finally:
    GPIO.cleanup()
    print("Cleaned up GPIO")

