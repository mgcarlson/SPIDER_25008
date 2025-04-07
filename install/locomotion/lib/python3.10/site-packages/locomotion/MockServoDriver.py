class MockServo:
    def __init__(self, angle=0):
        self.angle = angle

class MockServoDriver:
    servo = []

    def __init__(self, channels, address):
        self.channels = channels
        self.address = address
        self.servo = [MockServo() for _ in range(channels)]