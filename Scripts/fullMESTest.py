from adafruit_servokit import ServoKit
import time
import serial

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

time.sleep(2)

# Set up the ServoKit instance for 16 channels
kit = ServoKit(channels=16, address=0x44)

# Servo channel mapping
servo1 = kit.servo[0]  # Corresponds to Arduino pin 9
servo2 = kit.servo[2]  # Corresponds to Arduino pin 10
servo3 = kit.servo[4] # Corresponds to Arduino pin 11

# Initial servo positions
servo1.set_pulse_width_range(500,2500)
servo2.set_pulse_width_range(500,2500)
servo3.set_pulse_width_range(500,2500)
servo1.angle = 64
servo2.angle = 177
servo3.angle = 93

print("Enter 'F' to move forward, 'B' to move backward, 'L' for left, 'R' for right, 'C' for center.")
def smooth_dual_move(servo_a, start_a, target_a, servo_b, start_b, target_b, delay_ms = 25):
    steps = max(abs(target_a-start_a),abs(target_b-start_b))
    for i in range(steps+1):
        pos_a = int(start_a+(target_a-start_a)*i/steps)
        pos_b = int(start_b+(target_b-start_b)*i/steps)
        #servo_a.angle = pos_a
        servo_b.angle = pos_b
        servo_a.angle = pos_a
        time.sleep(delay_ms / 1000)
def smooth_move(servo, start_angle, end_angle, delay_ms=20):
    step = 1 if end_angle > start_angle else -1
    for angle in range(start_angle, end_angle + step, step):
        servo.angle = angle
        time.sleep(delay_ms / 1000)

while True:
    try:
        command = input("Command (F/B/L/R/C): ").strip().upper()

        if command == 'F':  # Move Forward
            print("Moving Forward")
            start1 = int(servo1.angle or 0)
            start2 = int(servo2.angle or 0)
            smooth_dual_move(servo1, start1, 158, servo2, start2, 85)

        elif command == 'B':  # Move Backward
            print("Moving Backward")
            start1 = int(servo1.angle or 0)
            start2 = int(servo2.angle or 0)
            smooth_dual_move(servo1, start1, 64, servo2, start2, 177)

        elif command == 'L':  # Move Left
            print("Moving Left")
            current = int(servo3.angle or 0)
            smooth_move(servo3, current, 105)

        elif command == 'C':  # Move to Center
            print("Moving to Center")
            current = int(servo3.angle or 0)
            smooth_move(servo3, current, 93)

        elif command == 'R':  # Move Right
            print("Moving Right")
            current = int(servo3.angle or 0)
            smooth_move(servo3, current, 80)
        
        elif command =='A': #Attack
            print("Attacking Weed")
            start1 = int(servo1.angle or 0)
            start2 = int(servo2.angle or 0)
            smooth_dual_move(servo1, start1, 135, servo2, start2, 108)
            ser.write(b'B\n')
            time.sleep(6)
            start1 = int(servo1.angle or 0)
            start2 = int(servo2.angle or 0)
            smooth_dual_move(servo1, start1, 158, servo2, start2, 85)
            time.sleep(5)
            print("Moving Left")
            current = int(servo3.angle or 0)
            smooth_move(servo3, current, 105)
            time.sleep(2)
            print("Moving Right")
            current = int(servo3.angle or 0)
            smooth_move(servo3, current, 80)
            time.sleep(2)
            print("Moving to Center")
            current = int(servo3.angle or 0)
            smooth_move(servo3, current, 93)
            ser.write(b'S\n')
            print("Sent stop")
            time.sleep(4)
            print("End of attack")
            start1 = int(servo1.angle or 0)
            start2 = int(servo2.angle or 0)
            smooth_dual_move(servo1, start1, 64, servo2, start2, 177)
            
            ser.close()

        else:
            print("Invalid command.")

    except KeyboardInterrupt:
        print("\nExiting.")
        break

