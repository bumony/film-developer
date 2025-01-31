#include <Arduino.h>

#include "header.h"

const int motorPin1 = 3;  // 控制正转的引脚
const int motorPin2 = 4;  // 控制反转的引脚
const int pwmPin = 5;     // 控制电机速度的PWM引脚

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ccw(255, 1000); // 逆时针转1秒
  stop(1000);
  cw(128, 1000);  // 顺时针转1秒
  stop(1000);
}

// put function definitions here:
void ccw(int speed,int time) {
  analogWrite(pwmPin, speed);  // 调节为需要的速度，范围0-255
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(time); //毫秒值
}

void cw(int speed,int time) {
  analogWrite(pwmPin, speed);  // 调节为需要的速度，范围0-255
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(time); //毫秒值
}

void stop(int time) {
  analogWrite(pwmPin, 0);  // 停止
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(time); //毫秒值
}