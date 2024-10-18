import pandas as pd
import numpy
import random
from datetime import datetime
import time

def sampleINT(s,lw,up):
    l = []
    for i in range(s):
        r = random.uniform(lw,up)
        r = round(r,3)
        l.append(r)
    return l

def main():
    path = "/home/dfolse/repos/SPIDER_Data/testData/"
    while True:
        s = 43
        NIR = sampleINT(s,0.4,0.6)
        RED = sampleINT(s,0.03,0.05)
        GRE = sampleINT(s,0.09,0.11)
        DF = pd.DataFrame({'NIR':NIR,
                       'Red':RED,
                       'Green':GRE
            })
        t = datetime.now().strftime('%Y-%m-%d %H-%M-%S')
        DF.to_csv(path+'Sample_Data_'+t+'.csv')
        time.sleep(1.2)
main()