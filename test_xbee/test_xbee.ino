#include <string.h>
#include <Servo.h>

Servo left_motor;
char input[10];
int LM_S = 1500;
int RM_S = 1500;

void setup() {
  Serial.begin(38400);
  Serial.setTimeout(3);
 // left_motor.attach(9);
  pinMode(9, OUTPUT);
  //left_motor.write(130);
}

void loop() {
  if(Serial.available()) {
    readSerial();
  }

  pwm();
  //left_motor.write(map(LM_S, 1000, 2000, 0, 179));
  
}

void readSerial() {
  String data = "";
  char start = ' ';
  while(start != 's') {
    delay(1);
    start = Serial.read();
  }

  data = Serial.readString();
  data.toCharArray(input, 10);
  pwm();

  char *a, *b;
  a = strtok_r(input, ";e", &b);

  data = a;
  LM_S = data.toInt();
  data = b;
  RM_S = data.toInt(); 
 // LM_S = constrain(LM_S, 1000, 2000);
// Serial.println(LM_S);
}

void pwm() {
  digitalWrite(9, HIGH);
  delayMicroseconds(LM_S);
  digitalWrite(9, LOW);
  delayMicroseconds(2000 - LM_S);

}

