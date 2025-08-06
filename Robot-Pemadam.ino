#include <IRremote.hpp>
#include <AFMotor.h>

#define IR_RECEIVE_PIN 9 // pin SERVO_2
#define pompa 10

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int pwm = 150; 

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN); // pin SERVO_1 motorshield
    
  pinMode(pompa, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if(IrReceiver.decode()){
    IrReceiver.resume();
  switch(IrReceiver.decodedIRData.decodedRawData) {
    case 3877175040:
      maju();
      delay(5);
      IrReceiver.resume();
      break;
    case 2907897600:
      mundur();
      delay(5);
      IrReceiver.resume();
      break;
    case 2774204160:
      kanan();
      delay(5);
      IrReceiver.resume();
      break;
    case 4144561920:
      kiri();
      IrReceiver.resume();
      delay(5);
      break;
    case 3810328320:
      Stop();
      delay(5);
      IrReceiver.resume();
      break;
    case 3910598400:
      digitalWrite(pompa, HIGH);
      delay(5000);
      IrReceiver.resume();
      break;
   
    case 4061003520:
      digitalWrite(pompa, LOW);
      IrReceiver.resume();
      break;
}
}
}
void maju() {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void mundur() {

  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void kanan()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(FORWARD);  
  motor4.setSpeed(255); 
  motor4.run(BACKWARD);  
}

void kiri()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);  
  motor2.setSpeed(255); 
  motor2.run(FORWARD);  
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(FORWARD); 
}
void Stop()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE);
  motor2.setSpeed(0);  
  motor2.run(RELEASE); 
  motor3.setSpeed(0);  
  motor3.run(RELEASE); 
  motor4.setSpeed(0);  
  motor4.run(RELEASE); 
}


