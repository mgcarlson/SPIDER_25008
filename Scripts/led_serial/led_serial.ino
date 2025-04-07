#define IN1 8
#define IN2 9
#define ENA 10
void setup() {
	pinMode(IN1,OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(ENA, OUTPUT);
	Serial.begin(9600);

}

void loop() {
	if(Serial.available()){
		char cmd = Serial.read();
		if(cmd == '1'){
			digitalWrite(IN1, HIGH);
			digitalWrite(IN2, LOW);
			analogWrite(ENA,255);
		}	
		else if (cmd == '0'){
			digitalWrite(IN1, LOW);
			digitalWrite(IN2,LOW);
			analogWrite(ENA, 0);
			
		}	
}
}
