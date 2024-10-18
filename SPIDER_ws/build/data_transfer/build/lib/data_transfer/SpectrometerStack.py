import board
from adafruit_tca9548a import TCA9548A
from adafruit_as7341 import AS7341
import csv
class SpectrometerStack:
    def __init__(self, simBool):
        self.simBool = simBool
        if self.simBool is False:
            i2c = board.I2C() 

            #Create the TCA9548A object and give it the I2C bus
            tca = TCA9548A(i2c)

            for channel in range(8):
                if tca[channel].try_lock():
                    print("Channel {}:".format(channel), end="")
                    addresses = tca[channel].scan()
                    print([hex(address) for address in addresses if address != 0x70])
                    tca[channel].unlock()

            #For each sensor, create it using the TCA9548A channel instead of the I2C object
            self.spec = []
            self.spec.append(AS7341(tca[0]))
            self.spec.append(AS7341(tca[1]))
            self.spec.append(AS7341(tca[2]))

    #After initial setup, can just use sensors as normal.
    def data_collection(self):
        R = []
        G = []
        B = []
        N = []
        for sensor in range(len(self.spec)):
            B.append(self.spec[sensor]._480nm)
            G.append(self.spec[sensor]._555nm)
            R.append(self.spec[sensor]._680nm)
            N.append(self.spec[sensor]._nir)
        r = sum(R)/float(len(R))
        g = sum(G)/float(len(G))
        b = sum(B)/float(len(B))
        n = sum(N)/float(len(N))
        dict = {'Red':r,
                'Green':g,
                'Blue':b,
                'NIR':n}
        return dict
    def collect_and_write(self, seconds):
        fileName = "/home/dfolse/repos/SPIDER_Data/raw/spec_data_%d.csv" % int(seconds)
        with open(fileName, "w", newline='') as file:
            if self.simBool:
                data = {'Red':240,
                        'Green':2100 ,
                        'Blue':140,
                        'NIR':4540}
            else:
                data = self.data_collection()
            csv_writer = csv.writer(file)
            csv_writer.writerow(["TimeStamp", "Red", "Green", "Blue", "NIR"])
            csv_writer.writerow([f"{seconds:.3f}", data['Red'], data['Green'], data['Blue'], data['NIR']])

        file.close()