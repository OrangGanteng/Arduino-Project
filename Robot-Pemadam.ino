#include <IRremote.hpp>
#include <AFMotor.h>


Servo myservo;

#define IR_RECEIVE_PIN 9 // pin SERVO_2
#define pin_ngencrit 10
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int pwm = 150;

const int kode_maju = 3877175040;
const int kode_mundur = 2907897600;
const int kode_belok_kanan = 2774204160;
const int kode_belok_kiri = 4144561920;
const int kode_berhenti = 3810328320;

const int kode_ngencrit = 3910598400;
const int kode_ngencrit_tutup = 4061003520;

const int servo_tutup = 35; // servo 0 derajat

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN); // pin SERVO_1 motorshield
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
      belok_kanan();
      delay(5);
      IrReceiver.resume();
      break;
    case 4144561920:
      belok_kiri();
      IrReceiver.resume();
      delay(5);
      break;
    case 3810328320:
      berhenti();
      delay(5);
      IrReceiver.resume();
      break;
    case 3910598400:
      digitalWrite(pin_ngencrit, HIGH);
      delay(5000);
      IrReceiver.resume();
      break;
    
    case 4061003520:
      digitalWrite(pin_ngencrit, LOW);
      IrReceiver.resume();
      break;
}
}
}
void maju() {
  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor4.setSpeed(pwm);
  motor1.run(FORWARD);
  motor3.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void mundur() {

  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor4.setSpeed(pwm);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void belok_kanan() {

  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor4.setSpeed(pwm);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}
void belok_kiri() {

  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor4.setSpeed(pwm);
  motor2.run(FORWARD);
  motor1.run(BACKWARD);
  motor4.run(FORWARD);
  motor3.run(BACKWARD);
}
void putar_kiri() {

  motor.setSpeed(pwm);
  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor2.run(FORWARD);
  motor1.run(FORWARD);
  motor4.run(BACKWARD);
  motor3.run(BACKWARD);
}
void putar_kanan() {

  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor4.setSpeed(pwm);
  motor2.run(BACKWARD);
  motor1.run(BACKWARD);
  motor4.run(FORWARD);
  motor3.run(FORWARD);
}
void moveRightForward() {

  motor.setSpeed(pwm);
  motor1.setSpeed(0);
  motor2.setSpeed(pwm);
  motor3.setSpeed(0);
  motor4.run(RELEASE);
  motor2.run(RELEASE);
  motor1.run(FORWARD);
  motor3.run(FORWARD);
}
void moveRightBackward() {

  motor1.setSpeed(pwm);
  motor2.setSpeed(0);
  motor3.setSpeed(pwm);
  motor4.setSpeed(0);
  motor1.run(RELEASE);
  motor3.run(RELEASE);
  motor2.run(BACKWARD);
  motor4.run(BACKWARD);

}
void moveLeftForward() {

  motor.setSpeed(0);
  motor1.setSpeed(pwm);
  motor2.setSpeed(0);
  motor3.setSpeed(pwm);
  motor3.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor4.run(FORWARD);
}
void moveLeftBackward() {

  motor1.setSpeed(pwm);
  motor2.setSpeed(0);
  motor3.setSpeed(pwm);
  motor4.setSpeed(0);
  motor3.run(RELEASE);
  motor2.run(RELEASE);
  motor1.run(BACKWARD);
  motor4.run(BACKWARD);
}
void berhenti() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
}


