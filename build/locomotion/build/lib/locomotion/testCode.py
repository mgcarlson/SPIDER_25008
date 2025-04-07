from locomotion.locomotionController import LocomotionController

if __name__ == "__main__":
    lc = LocomotionController(0x40,0x43,0x41,0x42,0x39, False, True, False)
    lc.serviceSelect('turnRight', 0, 90.0)
    lc.serviceSelect('move', 15, 0.0)
    lc.serviceSelect('turnRight', 0, 90.0)
    lc.serviceSelect('move', 15, 90.0)
    lc.serviceSelect('turnRight', 0, 90.0)
    lc.serviceSelect('move', 0, 90.0)
