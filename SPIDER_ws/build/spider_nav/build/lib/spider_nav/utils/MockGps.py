from geographiclib.geodesic import Geodesic

class MockGps:
    def __init__(self):
        self.has_Fix = True
        self.latitude = 32.23145
        self.longitude = -110.95664
        self.altitude_m = 0.0
        self.pdop = 1
    def updatePosition(self, dist, angle):
        geod = Geodesic.WGS84
        # Calculate the new coordinates
        res = geod.Direct(self.latitude, self.longitude, angle, dist)
        self.latitude = res['lat2']
        self.longitude = res['lon2']
        return
    def has_fix(self):
        return True