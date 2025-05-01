#include <AFMotor.h>
AF_DCMotor motor(1); //M1
void setup() {
	Serial.begin(9600);
	motor.setSpeed(255);
	Serial.println("Ready");
}

void loop() {
	if(Serial.available()){
		char cmd = Serial.read();
		if(cmd == 'F'){
		motor.run(FORWARD);
		Serial.println("Forward");
		}
		if(cmd=='B'){
		motor.run(BACKWARD);
		Serial.println("Back");
		}
		else if (cmd =='S'){
		motor.run(RELEASE);
		Serial.println("Stop");
		}
}
}
