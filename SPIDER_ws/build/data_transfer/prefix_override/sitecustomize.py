import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/alexcc/repos/SPIDER_25008/SPIDER_ws/install/data_transfer'
