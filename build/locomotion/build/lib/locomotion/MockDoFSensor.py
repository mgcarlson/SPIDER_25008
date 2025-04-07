import math
class MockDoFSensor:
    def __init__(self):
       self.euler =               (0,0.0,0.0)
       self.quaternion =          (0.0,0.0,0.0,0.0)
       self.gyro =                (0.0,0.0,0.0)
       self.linear_acceleration = (0.0,0.0,0.0)
       self.magnetic = (0.0,0.0,0.0)

    def changeHeading(self, delta):
        temp = self.euler[0] + delta
        if(temp >= 360.0):
            temp -= 360.0
        elif(temp < 0.0):
            temp += 360.0
        heading, pitch, roll = self.euler
        self.euler = (temp, pitch, roll)
        self.convertToQuaternion()

    def changePitch(self, delta):
        temp = self.euler[1] + delta
        if(temp >= 360.0):
            temp -= 360.0
        elif(temp < 0.0):
            temp += 360.0
        self.euler[1] = temp
        heading, pitch, roll = self.euler
        self.euler = (heading, temp, roll)
        self.convertToQuaternion()

    def changeRoll(self, delta):
        temp = self.euler[2] + delta
        if(temp >= 360.0):
            temp -= 360.0
        elif(temp < 0.0):
            temp += 360.0
        self.euler[2] = temp
        heading, pitch, roll = self.euler
        self.euler = (heading, pitch, temp)
        self.convertToQuaternion()

    def convertToQuaternion(self):
        cy = math.cos(self.euler[0] * 0.5)
        sy = math.sin(self.euler[0] * 0.5)
        cp = math.cos(self.euler[1] * 0.5)
        sp = math.sin(self.euler[1] * 0.5)
        cr = math.cos(self.euler[2] * 0.5)
        sr = math.sin(self.euler[2] * 0.5)

        tempW = cy * cp * cr + sy * sp * sr
        tempX = cy * cp * sr - sy * sp * cr
        tempY = sy * cp * sr + cy * sp * cr
        tempZ = sy * cp * cr - cy * sp * sr

        self.quaternion = (tempW, tempX, tempY, tempZ)
