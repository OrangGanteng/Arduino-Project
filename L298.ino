const int ena = 3;
const int in1 = 4;
const int in2 = 5;
const int in3 = 6;
const int in4 = 7;
const int enb = 9;

void setup(){
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}
void loop(){
    analogWrite(ena, 200);
    analogWrite(enb, 200);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
}
