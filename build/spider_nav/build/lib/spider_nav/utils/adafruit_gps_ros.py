import time
import adafruit_gps
import serial
from spider_nav.utils.MockGps import MockGps
class Adafruit_Gps_Ros():
    def __init__(self, simBool):
        self.simBool = simBool
        if self.simBool is False:
            self.uart = serial.Serial("/dev/ttyUSB0", baudrate=9600, timeout=10)
            self.gps = adafruit_gps.GPS(self.uart, debug=False)  # Use UART/pyserial

            self.gps.send_command(b"PMTK314,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0") # turn things on

            self.gps.send_command(b"PMTK220,1000") #set upudate rate to one second
        else:
            self.gps = MockGps()
    def setFix(self):
        if(self.gps.has_fix is True or self.simBool is True):
            return 1 # SBAS fix only
        else:
            return -1 # no fix
    def setCovariance(self):
        if self.simBool is False:
            return [self.gps.pdop, 0.0, 0.0,
                    self.gps.pdop, 0.0, 0.0,
                    self.gps.pdop, 0.0, 0.0]
        else:
            return [0.0, 0.0, 0.0,
                    0.0, 0.0, 0.0,
                    0.0, 0.0, 0.0]