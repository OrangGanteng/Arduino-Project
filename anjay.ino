#include <Servo.h>
#include <IRremote.hpp>
#include <AFMotor.h>

Servo myservo;

#define IR_RECEIVE_PIN 6

AF_DCMotor motor(1);
AF_DCMotor motor1(2);
AF_DCMotor motor2(3);
AF_DCMotor motor3(4);

int pwm = 100;

const int kode_maju = ;
const int kode_mundur = ;
const int kode_belok_kanan = ;
const int kode_belok_kiri = ;
const int kode_berhenti = ;

const int kode_servo_buka = ;
const int kode_servo_tutup = ;
const int kode_servo_buka_pelan = ;
const int kode_servo_tutup_pelan = ;

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN);
  myservo.attach(9);
  Serial.begin(9600);
}
void loop() {
  const int hasil_ir = IrReceiver.decodedIRData.decodedRawData;
  Serial.println(hasil_ir);
  switch(IrReceiver.decodeIRData.decodedRawData) {
    case kode_maju:
      maju();
      IrReceiver.resume();
      break;
    case kode_mundur:
      mundur();
      IrReceiver.resume();
      break;
    case kode_belok_kanan:
      belok_kanan();
      IrReceiver.resume();
      break;
    case kode_belok_kiri:
      belok_kiri();
      IrReceiver.resume();
      break;
    case kode_berhenti:
      berhenti();
      IrReceiver.resume();
      break;
    case 
    }
}

void maju() {
  motor.setSpeed(pwm);
  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor1.run(FORWARD);
  motor.run(FORWARD);
  motor3.run(FORWARD);
  motor2.run(FORWARD);
}
void mundur() {

  motor.setSpeed(pwm);
  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor1.run(BACKWARD);
  motor.run(BACKWARD);
  motor3.run(BACKWARD);
  motor2.run(BACKWARD);
}
void belok_kanan() {

  motor.setSpeed(pwm);
  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor1.run(BACKWARD);
  motor.run(FORWARD);
  motor3.run(BACKWARD);
  motor2.run(FORWARD);
}
void belok_kiri() {

  motor.setSpeed(pwm);
  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor1.run(FORWARD);
  motor.run(BACKWARD);
  motor3.run(FORWARD);
  motor2.run(BACKWARD);
}
void putar_kiri() {

  motor.setSpeed(pwm);
  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor1.run(FORWARD);
  motor.run(FORWARD);
  motor3.run(BACKWARD);
  motor2.run(BACKWARD);
}
void putar_kanan() {

  motor.setSpeed(pwm);
  motor1.setSpeed(pwm);
  motor2.setSpeed(pwm);
  motor3.setSpeed(pwm);
  motor1.run(BACKWARD);
  motor.run(BACKWARD);
  motor3.run(FORWARD);
  motor2.run(FORWARD);
}
void moveRightForward() {

  motor.setSpeed(pwm);
  motor1.setSpeed(0);
  motor2.setSpeed(pwm);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor1.run(RELEASE);
  motor.run(FORWARD);
  motor2.run(FORWARD);
}
void moveRightBackward() {

  motor1.setSpeed(pwm);
  motor.setSpeed(0);
  motor3.setSpeed(pwm);
  motor2.setSpeed(0);
  motor.run(RELEASE);
  motor2.run(RELEASE);
  motor1.run(BACKWARD);
  motor3.run(BACKWARD);

}
void moveLeftForward() {

  motor.setSpeed(0);
  motor1.setSpeed(pwm);
  motor2.setSpeed(0);
  motor3.setSpeed(pwm);
  motor2.run(RELEASE);
  motor.run(RELEASE);
  motor1.run(FORWARD);
  motor3.run(FORWARD);
}
void moveLeftBackward() {

  motor.setSpeed(pwm);
  motor1.setSpeed(0);
  motor2.setSpeed(pwm);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor1.run(RELEASE);
  motor.run(BACKWARD);
  motor2.run(BACKWARD);
}
void berhenti() {
  motor.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor.setSpeed(0);
}
