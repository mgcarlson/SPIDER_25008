import time
import threading
from locomotion.servoLeveler import ServoLeveler
from locomotion.MockServoDriver import MockServoDriver
from adafruit_servokit import ServoKit
import numpy as np
from scipy.optimize import fsolve
import matplotlib.pyplot as plt
import pandas as pd

# HORIZ, VERT, ELB (0 2 4) (6 8 10)
# PCA_LA 0x40
# Left 1
# Left 2

# PCA_LB 0x41
# Left 3
# Left 4

# PCA_RA 0x42
# Right 1
# Right 2

# PCA_RB 0x43
# Right 3
# Right 4

# Driver Nums
LA = 0
LB = 1
RA = 2
RB = 3

## Legs
# Left Legs
L1 = 0
L2 = 1
L3 = 0
L4 = 1
# Right Legs
R1 = 0
R2 = 1
R3 = 0
R4 = 1

# Angle Indices
STOP = 0
UP = 1
INIT = 2

# Turn Indices
TURN_RIGHT_1 = 3
TURN_RIGHT_2 = 4
TURN_RIGHT_3 = 5
TURN_RIGHT_4 = 6

TURN_LEFT_1 = 6
TURN_LEFT_2 = 5
TURN_LEFT_3 = 4
TURN_LEFT_4 = 3

#Servo QoL
H = 0
V = 1
E = 2

DELAY = 0.05

LENGTH2 = 0.2
LENGTH3 = 0.495
HEIGHT = 0.3048
LN = 0.08

class LocomotionController:
    def __init__(self, addressLA, addressLB, addressRA, addressRB, addressSL, simDriver, simSensor, graph):
        # TODO turn into csv reader
        self.graph = graph                                                              # Driver Leg  Servo 
        self.angles = [[[[90,90,90,80,85,95,100],[135,165,170],[120,90,90]],  #   LA    1   H V E
                        [[90,90,90,80,85,95,100],[140,170,180],[115,90,90]]], #   LA    2   H V E
                       [[[90,90,90,80,85,95,100],[125,155,160],[125,90,90]],  #   LB    3   H V E
                        [[90,90,90,80,85,95,100],[140,170,170],[120,90,90]]], #   LB    4   H V E
                       [[[90,90,90,80,85,95,100],[45,15,15], [60,90,90]],     #   RA    1   H V E
                        [[90,90,90,80,85,95,100],[35,5,5], [60,90,90]]],    #   RA    2   H V E
                       [[[90,90,90,80,85,95,100],[35,5,5], [80,90,90]],     #   RB    3   H V E
                        [[90,90,90,80,85,95,100],[50,20,10], [70,90,90]]]]    #   RB    4   H V E

        # Initialize Drivers
        self.driver = []
        #REAL
        if(simDriver is False):
            self.driver.append(ServoKit(channels=16, address=addressLA))
            self.driver.append(ServoKit(channels=16, address=addressLB))
            self.driver.append(ServoKit(channels=16, address=addressRA))
            self.driver.append(ServoKit(channels=16, address=addressRB))
        #MOCK
        else:
            self.driver.append(MockServoDriver(channels=16, address=addressLA)) #LA
            self.driver.append(MockServoDriver(channels=16, address=addressLB)) #LB
            self.driver.append(MockServoDriver(channels=16, address=addressRA)) #RA
            self.driver.append(MockServoDriver(channels=16, address=addressRB)) #RB
        if simSensor is True:
            self.sensor = ServoLeveler(address=addressSL, simSensor=simSensor)
        self.last_heading = 0.0
        self.simBool = simSensor
        self.setUpAngles(100000, 0.1)
        if(self.graph is True):
            # Create labels for leg number, servo number, and angle
            leg_labels = ['Leg ' + str(i+1) for i in range(self.forward_angles.shape[0])]
            servo_labels = ['Servo ' + str(i+1) for i in range(self.forward_angles.shape[1])]
            angle_labels = ['Angle ' + str(i+1) for i in range(self.forward_angles.shape[2])]

            # Flatten the 3D array into a 2D array for DataFrame
            # Each row will represent one combination of leg number, servo number, and angle
            # The columns will represent the values of the 3D array
            df_values = self.forward_angles.reshape(-1, self.forward_angles.shape[-1])

            # Create a DataFrame with appropriate labels
            df = pd.DataFrame(df_values, columns=angle_labels)

            # Add MultiIndex for leg number and servo number
            index = pd.MultiIndex.from_product([leg_labels, servo_labels], names=['Leg', 'Servo'])
            df.index = index

            # Define the filename for the Excel file
            excel_file = "fw_angles.xlsx"

            # Write the DataFrame to an Excel file
            df.to_excel(excel_file)

            print("Excel file created successfully.")
    def updateHeading(self, newHeading):
        self.last_heading = newHeading
        return
    def setUpAngles(self, numSteps, step_distance):
        # Using NumPy array
        self.forward_angles = np.zeros((8, 3, 42))  # numSteps should be the maximum number of angles you anticipate storing
        self.setUpAnglesLeg(numSteps,0,20,step_distance)
        self.setUpAnglesLeg(numSteps,1,20,step_distance)
        self.setUpAnglesLeg(numSteps,2,0,step_distance)
        self.setUpAnglesLeg(numSteps,3,0,step_distance)
        self.setUpAnglesLeg(numSteps,4,5,step_distance)
        self.setUpAnglesLeg(numSteps,5,5,step_distance)
        self.setUpAnglesLeg(numSteps,6,20,step_distance)
        self.setUpAnglesLeg(numSteps,7,20,step_distance)

    def setUpAnglesLeg(self, numSteps, leg, horizAngle, distance):
        VerticalAngledeg = np.zeros(numSteps)
        ElbowAngledeg = np.zeros(numSteps)
        L_array = np.zeros(numSteps)
        D_Array = np.zeros(numSteps)

        # Initial values
        thetan = np.deg2rad(horizAngle)
        if(leg <= 1):
            K = 0.2 + 1.057 * 0.0937 * np.sin(np.deg2rad(20))
            Inputs = [thetan, K]
        elif(leg == 2 or leg == 3):
            K = 0.2 - 1.057 * 0.0937 * np.sin(np.deg2rad(5))
            Inputs = [thetan, K]
        elif(leg == 4 or leg == 5):
            K = 0.2 - 1.057 * 0.0937 * np.sin(np.deg2rad(-5))
            Inputs = [thetan, K]    
        elif(leg >= 6):
            K = 0.2 + 1.057 * 0.0937 * np.sin(np.deg2rad(-20))
            Inputs = [thetan, K]
            
        i = 0
        while True:
            # Guesses: t2, t3, L, D
            guesses = [np.deg2rad(50), np.deg2rad(330), 0.5, 0.5]
            if(leg <= 1):
                thetas = fsolve(self.SPIDER_FSOLVE_FRONT, guesses, args=(Inputs,))
            if(leg == 2 or leg == 3):
                thetas = fsolve(self.SPIDER_FSOLVE_FRONT_MID, guesses, args=(Inputs,))
            if(leg == 4 or leg == 5):
                thetas = fsolve(self.SPIDER_FSOLVE_BACK_MID, guesses, args=(Inputs,))
            elif(leg >= 6):
                thetas = fsolve(self.SPIDER_FSOLVE_BACK, guesses, args=(Inputs,))
            VerticalAngledeg[i] = np.rad2deg(thetas[0])
            ElbowAngledeg[i] = np.rad2deg(thetas[1])
            L_array[i] = thetas[2]
            D_Array[i] = thetas[3]
            thetan -= 0.001
            if(leg <= 1):
                K = 0.2 - 1.057 * thetas[3] * np.sin(np.deg2rad(20))
                Inputs = [thetan, K]
            elif(leg == 2 or leg == 3):
                K = 0.2 - 1.057 * thetas[3] * np.sin(np.deg2rad(5))
                Inputs = [thetan, K]
            elif(leg == 4 or leg == 5):
                K = 0.2 - 1.057 * thetas[3] * np.sin(np.deg2rad(-5))
                Inputs = [thetan, K]    
            elif(leg >= 6):
                K = 0.2 - 1.057 * thetas[3] * np.sin(np.deg2rad(-20))
                Inputs = [thetan, K]
            if abs(D_Array[0] - thetas[3]) >= abs(distance): #0.1874 for 15
                break
            i+=1
        
        Thetanarray = np.linspace(np.rad2deg(thetan), horizAngle, i + 1)

        vert_array = VerticalAngledeg[0:len(Thetanarray)]
        elb_array = ElbowAngledeg[0:len(Thetanarray)]

        vertGraphCoeff = np.polyfit(Thetanarray, vert_array, 1)
        elbGraphCoeff = np.polyfit(Thetanarray, elb_array, 1)


        vert_equation = np.poly1d(vertGraphCoeff)
        elb_equation = np.poly1d(elbGraphCoeff)
        
        horiz_angles = np.linspace(Thetanarray[-1], Thetanarray[0],42)
        vert_angles = vert_equation(horiz_angles)
        elb_angles = elb_equation(horiz_angles)

        # Plot the polynomials
        if(self.graph is True):
            plt.plot(Thetanarray, vert_array, label='Vertical True:')
            plt.plot(horiz_angles, vert_angles, label='Vertical Normalized:')

            plt.plot(Thetanarray, elb_array, label='Elbow True:')
            plt.plot(horiz_angles, elb_angles, label='Elbow Normalized:')

            # Add labels and title
            plt.xlabel('Horizontal angles')
            plt.ylabel('Vertical/Elbow Angles')
            plt.title('Plot of Leg %d Angles' % (leg))

            # Add legend
            plt.legend()

            # Show the plot
            plt.grid(True)
            plt.show()

        for i in range(len(horiz_angles)):
            if (leg == 0): # left 1
                self.forward_angles[leg, 0, i] = 75 + horiz_angles[i]  
                self.forward_angles[leg, 1, i] = (self.angles[LA][L1][V][STOP] - 70) + vert_angles[i]  
                self.forward_angles[leg, 2, i] = self.angles[LA][L1][E][STOP] + (180 + vert_angles[i] + 90 - 15 - elb_angles[i]) - 52
            elif (leg == 1): # right 1
                self.forward_angles[leg, 0, i] = 105 - horiz_angles[i]  
                self.forward_angles[leg, 1, i] = (self.angles[RA][R1][V][STOP] + 70) - vert_angles[i]  
                self.forward_angles[leg, 2, i] = self.angles[RA][R1][E][STOP] - (180 + vert_angles[i] + 90 - 15 - elb_angles[i])  + 50
            elif (leg == 2): # left 2
                self.forward_angles[leg, 0, i] = 90 + horiz_angles[i]  
                self.forward_angles[leg, 1, i] = (self.angles[LA][L2][V][STOP] - 70) + vert_angles[i]  
                self.forward_angles[leg, 2, i] = self.angles[LA][L2][E][STOP] + (180 + vert_angles[i] + 90 - 15 - elb_angles[i])  - 52
            elif (leg == 3): # right 2
                self.forward_angles[leg, 0, i] = 90 - horiz_angles[i]  
                self.forward_angles[leg, 1, i] = (self.angles[RA][R2][V][STOP] + 70) - vert_angles[i]  
                self.forward_angles[leg, 2, i] = self.angles[RA][R2][E][STOP] - (180 + vert_angles[i] + 90 - 15 - elb_angles[i])  + 50
            elif (leg == 4): # left 3
                self.forward_angles[leg, 0, i] = 100 + horiz_angles[i]  
                self.forward_angles[leg, 1, i] = (self.angles[LB][L3][V][STOP] - 70) + vert_angles[i]  
                self.forward_angles[leg, 2, i] = self.angles[LB][L3][E][STOP] + (180 + vert_angles[i] + 90 - 15 - elb_angles[i])  - 47
            elif (leg == 5): # right 3
                self.forward_angles[leg, 0, i] = 80 - horiz_angles[i]  
                self.forward_angles[leg, 1, i] = (self.angles[RB][R3][V][STOP] + 70) - vert_angles[i]  
                self.forward_angles[leg, 2, i] = self.angles[RB][R3][E][STOP] - (180 + vert_angles[i] + 90 - 15 - elb_angles[i])  + 50
            elif (leg == 6): # left 4
                self.forward_angles[leg, 0, i] = 95 + horiz_angles[i]  
                self.forward_angles[leg, 1, i] = (self.angles[LB][L4][V][STOP] - 70) + vert_angles[i]  
                self.forward_angles[leg, 2, i] = self.angles[LB][L4][E][STOP] + (180 + vert_angles[i] + 90 - 15 - elb_angles[i])  - 47
            elif (leg == 7): # right 4
                self.forward_angles[leg, 0, i] = 85 - horiz_angles[i]  
                self.forward_angles[leg, 1, i] = (self.angles[RB][R4][V][STOP] + 70) - vert_angles[i]  
                self.forward_angles[leg, 2, i] = self.angles[RB][R4][E][STOP] - (180 + vert_angles[i] + 90 - 15 - elb_angles[i])  + 45
            else: 
                print("not a leg")
        print("leg %d, d = %f, length of theta n array %d, length of vertical %d, length of elbow %d" % (leg, D_Array[0] - D_Array[len(Thetanarray) - 1], len(horiz_angles), len(vert_angles), len(elb_angles)))
        return D_Array[0] - D_Array[len(Thetanarray) - 1]

    def SPIDER_FSOLVE(self, x, tn):
        G = [(LN + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1])) * np.cos(tn) - 0.2,
            (LN + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1])) * np.sin(tn) - x[3],
            LENGTH2 * np.sin(x[0]) + LENGTH3 * np.sin(x[1]) + HEIGHT,
            0.08 + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1]) - x[2]]
        return G
    
    def SPIDER_FSOLVE_FRONT(self, x, t):
        G = [(LN + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1])) * np.cos(t[0]) + 1.057 * x[3] * np.sin(np.deg2rad(20)) - t[1],
            (LN + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1])) * np.sin(t[0]) - x[3],
            LENGTH2 * np.sin(x[0]) + LENGTH3 * np.sin(x[1]) + HEIGHT,
            0.08 + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1]) - x[2]]
        return G
    def SPIDER_FSOLVE_FRONT_MID(self, x, t):
        G = [(LN + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1])) * np.cos(t[0]) + 1.057 * x[3] * np.sin(np.deg2rad(5)) - t[1],
            (LN + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1])) * np.sin(t[0]) - x[3],
            LENGTH2 * np.sin(x[0]) + LENGTH3 * np.sin(x[1]) + HEIGHT,
            0.08 + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1]) - x[2]]
        return G
    def SPIDER_FSOLVE_BACK_MID(self, x, t):
        G = [(LN + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1])) * np.cos(t[0]) + 1.057 * x[3] * np.sin(np.deg2rad(-5)) - t[1],
            (LN + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1])) * np.sin(t[0]) - x[3],
            LENGTH2 * np.sin(x[0]) + LENGTH3 * np.sin(x[1]) + HEIGHT,
            0.08 + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1]) - x[2]]
        return G
    def SPIDER_FSOLVE_BACK(self, x, t):
        G = [(LN + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1])) * np.cos(t[0]) + 1.057 * x[3] * np.sin(np.deg2rad(-20)) - t[1],
            (LN + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1])) * np.sin(t[0]) - x[3],
            LENGTH2 * np.sin(x[0]) + LENGTH3 * np.sin(x[1]) + HEIGHT,
            0.08 + LENGTH2 * np.cos(x[0]) + LENGTH3 * np.cos(x[1]) - x[2]]
        return G
    
    def startUp(self):
        for i in range(len(self.driver)):
            for j in range(0,11,2):
                if j < 5:
                    self.driver[i].servo[j].angle = self.angles[i][0][j // 2][INIT]
                else:
                    self.driver[i].servo[j].angle = self.angles[i][1][(j - 6) // 2][INIT]
        #self.calibrate()
        return
    def convertSensorReading(self, curr_angle, goal_angle):
        goal_max = goal_angle + 3
        goal_min = goal_angle - 3         
        if(goal_max >= 360):
            goal_max -= 360
            if(curr_angle >= goal_min and (curr_angle >= goal_max or curr_angle - 360 <= goal_max)):
                return True
            else:
                return False 
        if(goal_min < 0):
            goal_min += 360
            if((curr_angle >= goal_min or curr_angle + 360 <= goal_min) and curr_angle <= goal_max):
                return True
            else:
                return False 
        else:
            if(curr_angle >= goal_min and curr_angle <= goal_max):
                return True
            else:
                return False 

    def checkRotationPose(self, goal_angle):
        if self.simBool is True:
            self.last_heading, pitch, roll = self.sensor.checkEuler()
        return self.convertSensorReading(self.last_heading, goal_angle)
        
    def calibrate(self):
        self.stop()
        while(True):
            heading, pitch, roll = self.sensor.checkEuler()
            if roll > 180:
                roll -= 360
                
            if((pitch + 2 > 0 and pitch - 2 < 0) and (roll + 2 > 0 and roll - 2 < 0)):
                break
            if(pitch > 0): #leaning forward
                self.updatePitch('back')
            elif(pitch < 0): #leaning back
                self.updatePitch('forward')
            if(roll > 0): #leaning right
                self.updateRoll('left')
            elif(roll < 0): #leaning left
                self.updateRoll('right')
            self.quickStop()
        return
    def quickStop(self):
        for i in range(len(self.driver)):
            for j in range(0,11,2):
                if j < 5:
                    self.driver[i].servo[j].angle = self.angles[i][0][j // 2][STOP]
                else:
                    self.driver[i].servo[j].angle = self.angles[i][1][(j - 6) // 2][STOP]
        return
    def turnOff(self):
        for i in range(len(self.driver)):
            for j in range(0,11,2):
                if j < 5:
                    self.driver[i].servo[j].angle = None
                else:
                    self.driver[i].servo[j].angle = None
        return
    def updatePitch(self, direction):
        if(direction == 'forward'):
            dir = 1
        else: # direction is back
            dir = -1
        for leg in self.angles[LA]:
            for angle in self.angles[LA][leg][V]:
                self.angles[LA][leg][V][angle] += dir

        for leg in self.angles[LB]:
            for angle in self.angles[LB][leg][V]:
                self.angles[LB][leg][V][angle] -= dir
        
        for leg in self.angles[RA]:
            for angle in self.angles[RA][leg][V]:
                self.angles[RA][leg][V][angle] -= dir

        for leg in self.angles[RB]:
            for angle in self.angles[RB][leg][V]:
                self.angles[RB][leg][V][angle] += dir
        return
    def updateRoll(self, direction):
        if(direction == 'left'):
            dir = 1
        else: # direction is right
            dir = -1
        for leg in self.angles[LA]:
            for angle in self.angles[LA][leg][V]:
                self.angles[LA][leg][V][angle] += dir

        for leg in self.angles[LB]:
            for angle in self.angles[LB][leg][V]:
                self.angles[LB][leg][V][angle] += dir
        
        for leg in self.angles[RA]:
            for angle in self.angles[RA][leg][V]:
                self.angles[RA][leg][V][angle] += dir

        for leg in self.angles[RB]:
            for angle in self.angles[RB][leg][V]:
                self.angles[RB][leg][V][angle] += dir
        return
    def moveForward(self, num_moves):
        self.setUpFw()
        for i in range(num_moves):
            self.moveOneStep()
        return
    def setUpFw(self):
        a = self.angles
        fa = self.forward_angles
        self.moveLegSet(LA, RB, [0,0], [ fa[0][0][len(fa[0][0]) - 1], a[LA][L1][V][UP], fa[0][2][len(fa[0][2]) - 1],
                                    fa[5][0][len(fa[5][0]) - 1], a[RB][R3][V][UP], fa[5][2][len(fa[5][2]) - 1] ])
        self.moveLegSet(LA, RB, [0,0], [ fa[0][0][len(fa[0][0]) - 1], fa[0][1][len(fa[0][1]) - 1], fa[0][2][len(fa[0][2]) - 1],
                                    fa[5][0][len(fa[5][0]) - 1], fa[5][1][len(fa[5][1]) - 1], fa[5][2][len(fa[5][2]) - 1] ])
        
        self.moveLegSet(LA, RB, [1,1], [ fa[2][0][int(2 * len(fa[0][0]) / 3) - 1], a[LA][L2][V][UP], fa[2][2][int(2 * len(fa[0][0]) / 3) - 1],
                                    fa[7][0][int(2 * len(fa[0][0]) / 3) - 1], a[RB][R4][V][UP], fa[7][2][int(2 * len(fa[0][0]) / 3) - 1] ])
        self.moveLegSet(LA, RB, [1,1], [ fa[2][0][int(2 * len(fa[0][0]) / 3) - 1], fa[2][1][int(2 * len(fa[0][0]) / 3) - 1], fa[2][2][int(2 * len(fa[0][0]) / 3) - 1],
                                    fa[7][0][int(2 * len(fa[0][0]) / 3) - 1], fa[7][1][int(2 * len(fa[0][0]) / 3) - 1], fa[7][2][int(2 * len(fa[0][0]) / 3) - 1] ])

        self.moveLegSet(RA, LB, [0,0], [ fa[1][0][int(len(fa[1][0]) / 3) - 1], a[RA][R1][V][UP], fa[1][2][int(len(fa[1][2]) / 3) - 1],
                                    fa[4][0][int(len(fa[4][0]) / 3) - 1], a[LB][L3][V][UP], fa[4][2][int(len(fa[4][2]) / 3) - 1] ])
        self.moveLegSet(RA, LB, [0,0], [ fa[1][0][int(len(fa[1][0]) / 3) - 1], fa[1][1][int(len(fa[1][1]) / 3) - 1], fa[1][2][int(len(fa[1][2]) / 3) - 1],
                                    fa[4][0][int(len(fa[4][0]) / 3) - 1], fa[4][1][int(len(fa[4][1]) / 3) - 1], fa[4][2][int(len(fa[4][2]) / 3) - 1] ])
        
        self.moveLegSet(RA, LB, [1,1], [ fa[3][0][0], a[RA][R2][V][UP], fa[3][2][0],
                                    fa[6][0][0], a[LB][L4][V][UP], fa[6][2][0] ])
        self.moveLegSet(RA, LB, [1,1], [ fa[3][0][0], fa[3][1][0], fa[3][2][0],
                                    fa[6][0][0], fa[6][1][0], fa[6][2][0] ])
        print("Completed Set Up: ")
        #for i in range(4):
        #    for j in range(0, 11, 2):
        #        print("Driver %d, Servo: %d, Angle: %f " % (i, j, self.driver[i].servo[j].angle))

    def moveLegsFw(self, excludeSet):
        fa = self.forward_angles
        totalIdx = len(fa[0][0]) - 1
        startIdx = int(len(fa[0][0]) / 3) - 1
        twoThirdIdx = int(2 * len(fa[0][0]) / 3) - 1
        for angleIdx in range(int(len(fa[0][0]) / 3)):
            if 0 in excludeSet and 5 in excludeSet:
#---------------------------------------------------------------------------------------------------
                self.driver[0].servo[6].angle  = fa[2][0][totalIdx - (startIdx - angleIdx)] # leg L2
                self.driver[0].servo[8].angle  = fa[2][1][totalIdx - (startIdx - angleIdx)]
                self.driver[0].servo[10].angle = fa[2][2][totalIdx - (startIdx - angleIdx)]

                self.driver[3].servo[6].angle  = fa[7][0][totalIdx - (startIdx - angleIdx)] # leg R4
                self.driver[3].servo[8].angle  = fa[7][1][totalIdx - (startIdx - angleIdx)]
                self.driver[3].servo[10].angle = fa[7][2][totalIdx - (startIdx - angleIdx)]
#-------------------------------------------------------------------------------------------------
                self.driver[2].servo[0].angle  = fa[1][0][totalIdx - (twoThirdIdx - angleIdx)] # leg R1
                self.driver[2].servo[2].angle  = fa[1][1][totalIdx - (twoThirdIdx - angleIdx)]
                self.driver[2].servo[4].angle  = fa[1][2][totalIdx - (twoThirdIdx - angleIdx)]

                self.driver[1].servo[0].angle  = fa[4][0][totalIdx - (twoThirdIdx - angleIdx)] # leg L3
                self.driver[1].servo[2].angle  = fa[4][1][totalIdx - (twoThirdIdx - angleIdx)]
                self.driver[1].servo[4].angle  = fa[4][2][totalIdx - (twoThirdIdx - angleIdx)]
#------------------------------------------------------------------------------------------------
                self.driver[2].servo[6].angle  = fa[3][0][angleIdx] # leg R2
                self.driver[2].servo[8].angle  = fa[3][1][angleIdx]
                self.driver[2].servo[10].angle = fa[3][2][angleIdx]

                self.driver[1].servo[6].angle  = fa[6][0][angleIdx] # leg L4
                self.driver[1].servo[8].angle  = fa[6][1][angleIdx]
                self.driver[1].servo[10].angle = fa[6][2][angleIdx]
#-----------------------------------------------------------------------------------------------

            elif 2 in excludeSet and 7 in excludeSet:
#---------------------------------------------------------------------------------------------------
                self.driver[2].servo[0].angle  = fa[1][0][totalIdx - (startIdx - angleIdx)] # leg R1
                self.driver[2].servo[2].angle  = fa[1][1][totalIdx - (startIdx - angleIdx)]
                self.driver[2].servo[4].angle  = fa[1][2][totalIdx - (startIdx - angleIdx)]

                self.driver[1].servo[0].angle  = fa[4][0][totalIdx - (startIdx - angleIdx)] # leg L3
                self.driver[1].servo[2].angle  = fa[4][1][totalIdx - (startIdx - angleIdx)]
                self.driver[1].servo[4].angle  = fa[4][2][totalIdx - (startIdx - angleIdx)]
#-------------------------------------------------------------------------------------------------
                self.driver[2].servo[6].angle  = fa[3][0][totalIdx - (twoThirdIdx - angleIdx)] # leg R2
                self.driver[2].servo[8].angle  = fa[3][1][totalIdx - (twoThirdIdx - angleIdx)]
                self.driver[2].servo[10].angle = fa[3][2][totalIdx - (twoThirdIdx - angleIdx)]

                self.driver[1].servo[6].angle  = fa[6][0][totalIdx - (twoThirdIdx - angleIdx)] # leg L4
                self.driver[1].servo[8].angle  = fa[6][1][totalIdx - (twoThirdIdx - angleIdx)]
                self.driver[1].servo[10].angle = fa[6][2][totalIdx - (twoThirdIdx - angleIdx)]
#------------------------------------------------------------------------------------------------
                self.driver[0].servo[0].angle  = fa[0][0][angleIdx] # leg L1
                self.driver[0].servo[2].angle  = fa[0][1][angleIdx]
                self.driver[0].servo[4].angle  = fa[0][2][angleIdx]

                self.driver[3].servo[0].angle  = fa[5][0][angleIdx] # leg R3
                self.driver[3].servo[2].angle  = fa[5][1][angleIdx]
                self.driver[3].servo[4].angle  = fa[5][2][angleIdx]
#-----------------------------------------------------------------------------------------------

            elif 1 in excludeSet and 4 in excludeSet:
#---------------------------------------------------------------------------------------------------
                self.driver[2].servo[6].angle  = fa[3][0][totalIdx - (startIdx - angleIdx)] # leg R2
                self.driver[2].servo[8].angle  = fa[3][1][totalIdx - (startIdx - angleIdx)]
                self.driver[2].servo[10].angle = fa[3][2][totalIdx - (startIdx - angleIdx)]

                self.driver[1].servo[6].angle  = fa[6][0][totalIdx - (startIdx - angleIdx)] # leg L4
                self.driver[1].servo[8].angle  = fa[6][1][totalIdx - (startIdx - angleIdx)]
                self.driver[1].servo[10].angle = fa[6][2][totalIdx - (startIdx - angleIdx)]
#-------------------------------------------------------------------------------------------------
                self.driver[0].servo[0].angle  = fa[0][0][totalIdx - (twoThirdIdx - angleIdx)] # leg L1
                self.driver[0].servo[2].angle  = fa[0][1][totalIdx - (twoThirdIdx - angleIdx)]
                self.driver[0].servo[4].angle  = fa[0][2][totalIdx - (twoThirdIdx - angleIdx)]

                self.driver[3].servo[0].angle  = fa[5][0][totalIdx - (twoThirdIdx - angleIdx)] # leg R3
                self.driver[3].servo[2].angle  = fa[5][1][totalIdx - (twoThirdIdx - angleIdx)]
                self.driver[3].servo[4].angle  = fa[5][2][totalIdx - (twoThirdIdx - angleIdx)]
#------------------------------------------------------------------------------------------------
                self.driver[0].servo[6].angle  = fa[2][0][angleIdx] # leg L2
                self.driver[0].servo[8].angle  = fa[2][1][angleIdx]
                self.driver[0].servo[10].angle = fa[2][2][angleIdx]

                self.driver[3].servo[6].angle  = fa[7][0][angleIdx] # leg R4
                self.driver[3].servo[8].angle  = fa[7][1][angleIdx]
                self.driver[3].servo[10].angle = fa[7][2][angleIdx]
#-----------------------------------------------------------------------------------------------

            elif 3 in excludeSet and 6 in excludeSet:
#---------------------------------------------------------------------------------------------------
                self.driver[0].servo[0].angle  = fa[0][0][totalIdx - (startIdx - angleIdx)] # leg L1
                self.driver[0].servo[2].angle  = fa[0][1][totalIdx - (startIdx - angleIdx)]
                self.driver[0].servo[4].angle  = fa[0][2][totalIdx - (startIdx - angleIdx)]

                self.driver[3].servo[0].angle  = fa[5][0][totalIdx - (startIdx - angleIdx)] # leg R3
                self.driver[3].servo[2].angle  = fa[5][1][totalIdx - (startIdx - angleIdx)]
                self.driver[3].servo[4].angle  = fa[5][2][totalIdx - (startIdx - angleIdx)]
#-------------------------------------------------------------------------------------------------
                self.driver[0].servo[6].angle  = fa[2][0][totalIdx - (twoThirdIdx - angleIdx)] # leg L2
                self.driver[0].servo[8].angle  = fa[2][1][totalIdx - (twoThirdIdx - angleIdx)]
                self.driver[0].servo[10].angle = fa[2][2][totalIdx - (twoThirdIdx - angleIdx)]

                self.driver[3].servo[6].angle  = fa[7][0][totalIdx - (twoThirdIdx - angleIdx)] # leg R4
                self.driver[3].servo[8].angle  = fa[7][1][totalIdx - (twoThirdIdx - angleIdx)]
                self.driver[3].servo[10].angle = fa[7][2][totalIdx - (twoThirdIdx - angleIdx)]
#------------------------------------------------------------------------------------------------
                self.driver[2].servo[0].angle  = fa[1][0][angleIdx] # leg R1
                self.driver[2].servo[2].angle  = fa[1][1][angleIdx]
                self.driver[2].servo[4].angle  = fa[1][2][angleIdx]

                self.driver[1].servo[0].angle  = fa[4][0][angleIdx] # leg L3
                self.driver[1].servo[2].angle  = fa[4][1][angleIdx]
                self.driver[1].servo[4].angle  = fa[4][2][angleIdx]
#-----------------------------------------------------------------------------------------------

            else:
                print("Invalid move")
                return
    def moveOneStep(self):
        a = self.angles
        fa = self.forward_angles
        ## Begin Pattern
        # LA RB 1 move
        #self.quickSetVert(LA, 0, a[LA][L1][V][UP])
        #self.quickSetVert(RB, 0, a[RB][R3][V][UP])
        self.moveLegSet(LA, RB, [0,0], [ fa[0][0][0], a[LA][L1][V][UP], fa[0][2][0],
                                    fa[5][0][0], a[RB][R3][V][UP], fa[5][2][0] ])
        
        self.moveLegsFw(excludeSet=[0,5])

        self.moveLegSet(LA, RB, [0,0], [ fa[0][0][0], fa[0][1][0], fa[0][2][0],
                                    fa[5][0][0], fa[5][1][0], fa[5][2][0] ])

        # LA RB 2 move
        #self.quickSetVert(LA, 1, a[LA][L2][V][UP])
        #self.quickSetVert(RB, 1, a[RB][R4][V][UP])
        self.moveLegSet(LA, RB, [1,1], [ fa[2][0][0], a[LA][L2][V][UP], fa[2][2][0],
                                    fa[7][0][0], a[RB][R4][V][UP], fa[7][2][0] ])
        
        self.moveLegsFw(excludeSet=[2,7])

        self.moveLegSet(LA, RB, [1,1], [ fa[2][0][0], fa[2][1][0], fa[2][2][0],
                                    fa[7][0][0], fa[7][1][0], fa[7][2][0] ])
        
        # RA LB 1 move
        #self.quickSetVert(RA, 0, a[RA][R1][V][UP])
        #self.quickSetVert(LB, 0, a[LB][L3][V][UP])
        self.moveLegSet(RA, LB, [0,0], [ fa[1][0][0], a[RA][R1][V][UP], fa[1][2][0],
                                    fa[4][0][0], a[LB][L3][V][UP], fa[4][2][0] ])
        
        self.moveLegsFw(excludeSet=[1,4])

        self.moveLegSet(RA, LB, [0,0], [ fa[1][0][0], fa[1][1][0], fa[1][2][0],
                                    fa[4][0][0], fa[4][1][0], fa[4][2][0] ])

        # RA LB 2 move
        #self.quickSetVert(RA, 1, a[RA][R2][V][UP])
        #self.quickSetVert(LB, 1, a[LB][L4][V][UP])
        self.moveLegSet(RA, LB, [1,1], [ fa[3][0][0], a[RA][R2][V][UP], fa[3][2][0],
                                    fa[6][0][0], a[LB][L4][V][UP], fa[6][2][0] ])
        
        self.moveLegsFw(excludeSet=[3,6])

        self.moveLegSet(RA, LB, [1,1], [ fa[3][0][0], fa[3][1][0], fa[3][2][0],
                                    fa[6][0][0], fa[6][1][0], fa[6][2][0] ])
        print("Finish Step ")
        #for i in range(4):
        #    for j in range(0, 11, 2):
        #        print("Driver %d, Servo: %d, Angle: %f " % (i, j, self.driver[i].servo[j].angle))
    def quickSetVert(self, driver, leg, angle):
        if leg == 0:
            self.driver[driver].servo[2].angle = angle
        else:
            self.driver[driver].servo[8].angle = angle
        return
    def stop(self):
        a = self.angles
        
        # Move the sets of legs up then down
        self.moveLegSet(LA, RB, [0,0], [ a[LA][L1][H][STOP], a[LA][L1][V][UP], a[LA][L1][E][STOP],
                                    a[RB][R3][H][STOP], a[RB][R3][V][UP], a[RB][R3][E][STOP] ])
        self.moveLegSet(LA, RB, [0,0], [ a[LA][L1][H][STOP], a[LA][L1][V][STOP], a[LA][L1][E][STOP],
                                    a[RB][R3][H][STOP], a[RB][R3][V][STOP], a[RB][R3][E][STOP] ])
        
        self.moveLegSet(LA, RB, [1,1], [ a[LA][L2][H][STOP], a[LA][L2][V][UP], a[LA][L2][E][STOP],
                                    a[RB][R4][H][STOP], a[RB][R4][V][UP], a[RB][R4][E][STOP] ])
        self.moveLegSet(LA, RB, [1,1], [ a[LA][L2][H][STOP], a[LA][L2][V][STOP], a[LA][L2][E][STOP],
                                    a[RB][R4][H][STOP], a[RB][R4][V][STOP], a[RB][R4][E][STOP] ])
        
        self.moveLegSet(RA, LB, [0,0], [ a[RA][R1][H][STOP], a[RA][R1][V][UP], a[RA][R1][E][STOP],
                                    a[LB][L3][H][STOP], a[LB][L3][V][UP], a[LB][L3][E][STOP] ])
        self.moveLegSet(RA, LB, [0,0], [ a[RA][R1][H][STOP], a[RA][R1][V][STOP], a[RA][R1][E][STOP],
                                    a[LB][L3][H][STOP], a[LB][L3][V][STOP], a[LB][L3][E][STOP] ])
        
        self.moveLegSet(RA, LB, [1,1], [ a[RA][R2][H][STOP], a[RA][R2][V][UP], a[RA][R2][E][STOP],
                                    a[LB][L4][H][STOP], a[LB][L4][V][UP], a[LB][L4][E][STOP] ])
        self.moveLegSet(RA, LB, [1,1], [ a[RA][R2][H][STOP], a[RA][R2][V][STOP], a[RA][R2][E][STOP],
                                    a[LB][L4][H][STOP], a[LB][L4][V][STOP], a[LB][L4][E][STOP] ])

        print("Completed Stop: ")
        #for i in range(4):
        #    for j in range(0, 11, 2):
        #        print("Driver %d, Servo: %d, Angle: %f " % (i, j, self.driver[i].servo[j].angle))
        return
    def setUpTurn(self, direction):
        a = self.angles # easier to type and read lol
        if(direction == "left"):
            ## Set up into correct move
            self.moveLegSet(LA, RB, [0,0], [ a[LA][L1][H][TURN_LEFT_2], a[LA][L1][V][UP], a[LA][L1][E][STOP],
                                        a[RB][R3][H][TURN_LEFT_2], a[RB][R3][V][UP], a[RB][R3][E][STOP] ])
            self.moveLegSet(LA, RB, [0,0], [ a[LA][L1][H][TURN_LEFT_1], a[LA][L1][V][STOP], a[LA][L1][E][STOP],
                                        a[RB][R3][H][TURN_LEFT_1], a[RB][R3][V][STOP], a[RB][R3][E][STOP] ])
            
            self.moveLegSet(LA, RB, [1,1], [ a[LA][L2][H][TURN_LEFT_2], a[LA][L2][V][UP], a[LA][L2][E][STOP],
                                        a[RB][R4][H][TURN_LEFT_2], a[RB][R4][V][UP], a[RB][R4][E][STOP] ])
            self.moveLegSet(LA, RB, [1,1], [ a[LA][L2][H][TURN_LEFT_2], a[LA][L2][V][STOP], a[LA][L2][E][STOP],
                                        a[RB][R4][H][TURN_LEFT_2], a[RB][R4][V][STOP], a[RB][R4][E][STOP] ])

            self.moveLegSet(RA, LB, [0,0], [ a[RA][R1][H][TURN_LEFT_3], a[RA][R1][V][UP], a[RA][R1][E][STOP],
                                        a[LB][L3][H][TURN_LEFT_3], a[LB][L3][V][UP], a[LB][L3][E][STOP] ])
            self.moveLegSet(RA, LB, [0,0], [ a[RA][R1][H][TURN_LEFT_3], a[RA][R1][V][STOP], a[RA][R1][E][STOP],
                                        a[LB][L3][H][TURN_LEFT_3], a[LB][L3][V][STOP], a[LB][L3][E][STOP] ])
            
            self.moveLegSet(RA, LB, [1,1], [ a[RA][R2][H][TURN_LEFT_4], a[RA][R2][V][UP], a[RA][R2][E][STOP],
                                        a[LB][L4][H][TURN_LEFT_3], a[LB][L4][V][UP], a[LB][L4][E][STOP] ])
            self.moveLegSet(RA, LB, [1,1], [ a[RA][R2][H][TURN_LEFT_4], a[RA][R2][V][STOP], a[RA][R2][E][STOP],
                                        a[LB][L4][H][TURN_LEFT_4], a[LB][L4][V][STOP], a[LB][L4][E][STOP] ])
        else:
            ## Set up into correct move
            self.moveLegSet(LA, RB, [0,0], [ a[LA][L1][H][TURN_RIGHT_2], a[LA][L1][V][UP], a[LA][L1][E][STOP],
                                        a[RB][R3][H][TURN_RIGHT_2], a[RB][R3][V][UP], a[RB][R3][E][STOP] ])
            self.moveLegSet(LA, RB, [0,0], [ a[LA][L1][H][TURN_RIGHT_1], a[LA][L1][V][STOP], a[LA][L1][E][STOP],
                                        a[RB][R3][H][TURN_RIGHT_1], a[RB][R3][V][STOP], a[RB][R3][E][STOP] ])
            
            self.moveLegSet(LA, RB, [1,1], [ a[LA][L2][H][TURN_RIGHT_2], a[LA][L2][V][UP], a[LA][L2][E][STOP],
                                        a[RB][R4][H][TURN_RIGHT_2], a[RB][R4][V][UP], a[RB][R4][E][STOP] ])
            self.moveLegSet(LA, RB, [1,1], [ a[LA][L2][H][TURN_RIGHT_2], a[LA][L2][V][STOP], a[LA][L2][E][STOP],
                                        a[RB][R4][H][TURN_RIGHT_2], a[RB][R4][V][STOP], a[RB][R4][E][STOP] ])

            self.moveLegSet(RA, LB, [0,0], [ a[RA][R1][H][TURN_RIGHT_3], a[RA][R1][V][UP], a[RA][R1][E][STOP],
                                        a[LB][L3][H][TURN_RIGHT_3], a[LB][L3][V][UP], a[LB][L3][E][STOP] ])
            self.moveLegSet(RA, LB, [0,0], [ a[RA][R1][H][TURN_RIGHT_3], a[RA][R1][V][STOP], a[RA][R1][E][STOP],
                                        a[LB][L3][H][TURN_RIGHT_3], a[LB][L3][V][STOP], a[LB][L3][E][STOP] ])
            
            self.moveLegSet(RA, LB, [1,1], [ a[RA][R2][H][TURN_RIGHT_4], a[RA][R2][V][UP], a[RA][R2][E][STOP],
                                        a[LB][L4][H][TURN_RIGHT_3], a[LB][L4][V][UP], a[LB][L4][E][STOP] ])
            self.moveLegSet(RA, LB, [1,1], [ a[RA][R2][H][TURN_RIGHT_4], a[RA][R2][V][STOP], a[RA][R2][E][STOP],
                                        a[LB][L4][H][TURN_RIGHT_4], a[LB][L4][V][STOP], a[LB][L4][E][STOP] ])
    def moveLegsTurnExp(self, direction, excludeSet, deltaAngle):
        if 0 in excludeSet:
            for i in range(deltaAngle):
                self.driver[LA].servo[6].angle += direction * 1
                self.driver[LB].servo[0].angle += direction * 1
                self.driver[LB].servo[6].angle += direction * 1
                self.driver[RA].servo[0].angle += direction * 1
                self.driver[RA].servo[6].angle += direction * 1
                self.driver[RB].servo[6].angle += direction * 1
                time.sleep(0.1)
        elif 2 in excludeSet:
            for i in range(deltaAngle):
                self.driver[LA].servo[0].angle += direction * 1
                self.driver[LB].servo[0].angle += direction * 1
                self.driver[LB].servo[6].angle += direction * 1
                self.driver[RA].servo[0].angle += direction * 1
                self.driver[RA].servo[6].angle += direction * 1
                self.driver[RB].servo[0].angle += direction * 1
                time.sleep(0.1)
        elif 4 in excludeSet:
            for i in range(deltaAngle):
                self.driver[LA].servo[0].angle += direction * 1
                self.driver[LA].servo[6].angle += direction * 1
                self.driver[LB].servo[0].angle += direction * 1
                self.driver[RA].servo[6].angle += direction * 1
                self.driver[RB].servo[0].angle += direction * 1
                self.driver[RB].servo[6].angle += direction * 1
                time.sleep(0.1)


        elif 6 in excludeSet:
            for i in range(deltaAngle):
                self.driver[LA].servo[0].angle += direction * 1
                self.driver[LA].servo[6].angle += direction * 1
                self.driver[LB].servo[0].angle += direction * 1
                self.driver[RA].servo[0].angle += direction * 1
                self.driver[RB].servo[0].angle += direction * 1
                self.driver[RB].servo[6].angle += direction * 1
                time.sleep(0.1)

        return
            
    def turnOnceExp(self, direction, goal_angle):
        a = self.angles
        if direction == "right":
         ## Begin Pattern
            # LA RB 1 move
            self.moveLegSet(LA, RB, [0,0], [ a[LA][L1][H][STOP], a[LA][L1][V][UP], a[LA][L1][E][STOP],
                                        a[RB][R3][H][STOP], a[RB][R3][V][UP], a[RB][R3][E][STOP] ])
            
            self.moveLegsTurnExp(1, [0,5], 5)

            self.moveLegSet(LA, RB, [0,0], [ a[LA][L1][H][TURN_RIGHT_4], a[LA][L1][V][STOP], a[LA][L1][E][STOP],
                                        a[RB][R3][H][TURN_RIGHT_4], a[RB][R3][V][STOP], a[RB][R3][E][STOP] ])
            if(self.simBool is True):
                self.sensor.sensor_9DoF.changeHeading(5)
            if (self.checkRotationPose(goal_angle)):
                return True
            # LA RB 2 move
            self.moveLegSet(LA, RB, [1,1], [ a[LA][L2][H][STOP], a[LA][L2][V][UP], a[LA][L2][E][STOP],
                                        a[RB][R4][H][STOP], a[RB][R4][V][UP], a[RB][R4][E][STOP] ])
            
            self.moveLegsTurnExp(1, [2,7], 5)

            
            self.moveLegSet(LA, RB, [1,1], [ a[LA][L2][H][TURN_RIGHT_4], a[LA][L2][V][STOP], a[LA][L2][E][STOP],
                                        a[RB][R4][H][TURN_RIGHT_4], a[RB][R4][V][STOP], a[RB][R4][E][STOP] ])
            if(self.simBool is True):
                self.sensor.sensor_9DoF.changeHeading(5)
            if (self.checkRotationPose(goal_angle)):
                return True
            
            # RA LB 1 move
            self.moveLegSet(RA, LB, [0,0], [ a[RA][R1][H][STOP], a[RA][R1][V][UP], a[RA][R1][E][STOP],
                                        a[LB][L3][H][STOP], a[LB][L3][V][UP], a[LB][L3][E][STOP] ])
            
            self.moveLegsTurnExp(1, [1,4], 5)
            

            self.moveLegSet(RA, LB, [0,0], [ a[RA][R1][H][TURN_RIGHT_4], a[RA][R1][V][STOP], a[RA][R1][E][STOP],
                                        a[LB][L3][H][TURN_RIGHT_4], a[LB][L3][V][STOP], a[LB][L3][E][STOP] ])
            if(self.simBool is True):
                self.sensor.sensor_9DoF.changeHeading(5)
            if (self.checkRotationPose(goal_angle)):
                return True
            
            # RA LB 2 move

            self.moveLegSet(RA, LB, [1,1], [ a[RA][R2][H][STOP], a[RA][R2][V][UP], a[RA][R2][E][STOP],
                                        a[LB][L4][H][STOP], a[LB][L4][V][UP], a[LB][L4][E][STOP] ])
            
            self.moveLegsTurnExp(1, [3,6], 5)

            self.moveLegSet(RA, LB, [1,1], [ a[RA][R2][H][TURN_RIGHT_4], a[RA][R2][V][STOP], a[RA][R2][E][STOP],
                                        a[LB][L4][H][TURN_RIGHT_4], a[LB][L4][V][STOP], a[LB][L4][E][STOP] ])
            if(self.simBool is True):
                self.sensor.sensor_9DoF.changeHeading(5)
            if (self.checkRotationPose(goal_angle)):
                return True
            return False
        else:
            ## Begin Pattern
            # LA RB 1 move
            self.moveLegSet(LA, RB, [0,0], [ a[LA][L1][H][STOP], a[LA][L1][V][UP], a[LA][L1][E][STOP],
                                        a[RB][R3][H][STOP], a[RB][R3][V][UP], a[RB][R3][E][STOP] ])
                        
            self.moveLegsTurnExp(-1, [0,5], 5)


            self.moveLegSet(LA, RB, [0,0], [ a[LA][L1][H][TURN_LEFT_4], a[LA][L1][V][STOP], a[LA][L1][E][STOP],
                                        a[RB][R3][H][TURN_LEFT_4], a[RB][R3][V][STOP], a[RB][R3][E][STOP] ])
            if(self.simBool is True):
                self.sensor.sensor_9DoF.changeHeading(-5)
            if (self.checkRotationPose(goal_angle)):
                return True
            
            # LA RB 2 move
            self.moveLegSet(LA, RB, [1,1], [ a[LA][L2][H][STOP], a[LA][L2][V][UP], a[LA][L2][E][STOP],
                                        a[RB][R4][H][STOP], a[RB][R4][V][UP], a[RB][R4][E][STOP] ])
            
            self.moveLegsTurnExp(-1, [2,7], 5)

            
            self.moveLegSet(LA, RB, [1,1], [ a[LA][L2][H][TURN_LEFT_4], a[LA][L2][V][STOP], a[LA][L2][E][STOP],
                                        a[RB][R4][H][TURN_LEFT_4], a[RB][R4][V][STOP], a[RB][R4][E][STOP] ])
            if(self.simBool is True):
                self.sensor.sensor_9DoF.changeHeading(-3)
            if (self.checkRotationPose(goal_angle)):
                return True
            
            # RA LB 1 move
            self.moveLegSet(RA, LB, [0,0], [ a[RA][R1][H][STOP], a[RA][R1][V][UP], a[RA][R1][E][STOP],
                                        a[LB][L3][H][STOP], a[LB][L3][V][UP], a[LB][L3][E][STOP] ])
            
            self.moveLegsTurnExp(-1, [1,4], 5)

            

            self.moveLegSet(RA, LB, [0,0], [ a[RA][R1][H][TURN_LEFT_4], a[RA][R1][V][STOP], a[RA][R1][E][STOP],
                                        a[LB][L3][H][TURN_LEFT_4], a[LB][L3][V][STOP], a[LB][L3][E][STOP] ])
            if(self.simBool is True):
                self.sensor.sensor_9DoF.changeHeading(-5)
            if (self.checkRotationPose(goal_angle)):
                return True
            
            # RA LB 2 move

            self.moveLegSet(RA, LB, [1,1], [ a[RA][R2][H][STOP], a[RA][R2][V][UP], a[RA][R2][E][STOP],
                                        a[LB][L4][H][STOP], a[LB][L4][V][UP], a[LB][L4][E][STOP] ])
            
            self.moveLegsTurnExp(-1, [3,6], 5)


            self.moveLegSet(RA, LB, [1,1], [ a[RA][R2][H][TURN_LEFT_4], a[RA][R2][V][STOP], a[RA][R2][E][STOP],
                                        a[LB][L4][H][TURN_LEFT_4], a[LB][L4][V][STOP], a[LB][L4][E][STOP] ])
            if(self.simBool is True):
                self.sensor.sensor_9DoF.changeHeading(-5)
            if (self.checkRotationPose(goal_angle)):
                return True
            return False
        
    def turn(self, direction, deltaAngle): # Allow the robot to turn
        if(deltaAngle < 3):
            print("Angle too small")
            return
        if self.simBool is True:
            start_heading, pitch, roll = self.sensor.checkEuler()
        else:
            start_heading = self.last_heading
        self.setUpTurn(direction)
        if(direction.lower() == "left"): #counterclockwise
            goal_angle = start_heading - deltaAngle
            if(goal_angle < 0):
                goal_angle += 360
        else: #clockwise
            goal_angle = start_heading + deltaAngle
            if(goal_angle >= 360):
                goal_angle -= 360
        atAngle = False
        while(atAngle is False):
            atAngle = self.turnOnceExp(direction, goal_angle)
            
            print("Completed Turn: ")
            #for i in range(4):
            #    for servo in range(0, 11, 2):
            #        print("Driver %d, Servo: %d, Angle: %f " % (i, servo, self.driver[i].servo[servo].angle))

        return
    def moveLegSet(self, driver_1, driver_2, legs, goal_state):
        self.moveLegExp(driver_num=driver_1, driver_num_2=driver_2, leg=legs[0], goal_state=goal_state)

    def moveLegExp(self, driver_num, driver_num_2, leg, goal_state):
        if(leg == 0):
            start_idx = 0
            end_idx   = 5
        else:
            start_idx = 6
            end_idx   = 11
        aa = []
        for servo in range(start_idx, end_idx, 2):
            tempIndex = self.dynIndex(leg, servo, driver_num)
            aa.append(np.arange(10, dtype=float) * ((goal_state[tempIndex] - self.driver[driver_num].servo[servo].angle) / (10 - 1)) + self.driver[driver_num].servo[servo].angle)

            tempIndex2 = self.dynIndex(leg, servo, driver_num_2)            
            aa.append(np.arange(10, dtype=float) * ((goal_state[tempIndex2] - self.driver[driver_num_2].servo[servo].angle) / (10 - 1)) + self.driver[driver_num_2].servo[servo].angle)            
        for i in range(10):
            aaIdx = 0
            for servo in range(start_idx, end_idx, 2):
                self.driver[driver_num].servo[servo].angle = aa[aaIdx][i]
                aaIdx += 1
                self.driver[driver_num_2].servo[servo].angle = aa[aaIdx][i]
                aaIdx += 1
                time.sleep(0.01)
                
    def dynIndex(self, leg, servo, driver_num):
        if(driver_num is LA or driver_num is RA):
            if(leg == 0):
                return servo // 2
            else:
                return (servo - 6) // 2
        elif(driver_num is LB or driver_num is RB):
            if(leg == 0):
                return (servo + 6) // 2
            else:
                return servo // 2
    
    def serviceSelect(self, move_type, move_amount, delta_angle):
        if(move_type.lower() == 'stop'):
            self.stop()
        elif(move_type.lower() == 'start'):
            self.startUp()
        elif(move_type.lower() == 'calibrate'):
            self.calibrate()
        elif(move_type.lower() == 'move'):
            self.moveForward(move_amount)
        elif(move_type.lower() == 'turnright'):
            self.turn('right', delta_angle)
        elif(move_type.lower() == 'turnleft'):
            self.turn('left', delta_angle)
        elif(move_type.lower() == 'turnoff'):
            self.turnOff()
        elif(move_type.lower() == 'quickstop'):
            self.quickStop()
        elif(move_type.lower() == 'setup_fw'):
            self.setUpFw()
        elif(move_type.lower() == 'setup_turn_left'):
            self.setUpTurn('left')
        elif(move_type.lower() == 'setup_turn_right'):
            self.setUpTurn('right')    
        else:
            print("Invalid Move %s" % move_type)
        return

if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(description='SPIDER Locomotion Testing Parser')
    parser.add_argument('--move-type', '-m', dest='move_type', type=str, default='stop', required=False, help='move type')
    parser.add_argument('--move-amount', '-n', dest='move_amount', type=int, default=1, required=False, help='move amount')
    parser.add_argument('--sim-driver', '-sd', dest='sim_driver', action="store_true", required=False, help='simulate the drivers?')
    parser.add_argument('--sim-sensor', '-ss', dest='sim_sensor', action="store_true", required=False, help='simulate the sensor?')
    parser.add_argument('--delta-angle', '-da', dest='deltaAngle', type=float, default=0, required=False, help='how far to turn?')
    parser.add_argument('--graph', '-g', dest='graph', action="store_true", required=False, help='graph the angles?')
    args = parser.parse_args()
    parser.set_defaults(graph=True, sim_sensor=False, sim_driver=False)

    lc = LocomotionController(0x40,0x43,0x41,0x42,0x39, args.sim_driver, args.sim_sensor, args.graph)
    
    lc.serviceSelect(args.move_type, args.move_amount, args.deltaAngle)
