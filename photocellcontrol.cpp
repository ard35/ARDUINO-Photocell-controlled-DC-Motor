#define ENBALE 5
#define DIRA 3
#define DIRB 4

int photocellPin = 0;
int i;

int redLed = 10;
int yellowLed = 9;
int greenLed = 8;

void setup() { //set pin direction
	pinMode(ENABLE, OUTPUT);
	pinMode(DIRA, OUTPUT);
	pinMode(DIRB, OUTPUT);
	pinMode(redLed, OUTPUT);
	pinMode(yellowLed, OUTPUT);
	pinMode(greenLed, OUTPUT);
	Serial.begin(5600);
	}
	
void loop() {
	int reading = analogRead (photocellPin); //assign int to photocellPin light input
	int speed = reading / 3; //divide photocellPin input reading to control DC Motor speed better
	serial.println("Fan on");
	analogWrite(DIRA, speed); //write to the DC motor in one direction with value of speed
	analogWrite(ENABLE,speed);
	delay(500); //delay in switching dc motor speed
	
	if(speed <= 105) { 
		//when speed is low
		//turn ON Green LED, turn OFF red & yellow LED
		digitalWrite(greenLed, HIGH);
		digitalWrite(redLed, LOW);
		digitalWrite(yellowLed, LOW);
		Serial.println("Fan LOW mode");
		}
		
	if(105 < speed && speed < 140) { 
		//when speed is medium
		//turn ON yellow LED, turn OFF red & green LED
		digitalWrite(greenLed, LOW);
		digitalWrite(redLed, LOW);
		digitalWrite(yellowLed, HIGH);
		Serial.println("Fan MEDIUM mode");
		}	
		
	if(speed >= 140) { 
		//when speed is high
		//turn ON red LED, turn OFF green & yellow LED
		digitalWrite(greenLed, LOW);
		digitalWrite(redLed, HIGH);
		digitalWrite(yellowLed, LOW);
		Serial.println("Fan LOW mode");
	}
}