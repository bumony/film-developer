#include <AFMotor.h>
#include <Adafruit_SPIDevice.h>
#include <Wire.h>
#include <Arduino.h>
#include "header.h"


AF_DCMotor motor(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor.setSpeed(128);
 
  motor.run(RELEASE);
}

void loop() {
  Serial.println("Forward!");
  ccw(95, 2000); // 逆时针
  Serial.println("Stop!");
  stop(1000);
  Serial.println("Backward!");
  cw(95, 2000);  // 顺时针
  Serial.println("Stop!");
  stop(1000);

}

void ccw(int speed,int time) {
  motor.setSpeed(speed);  // 调节为需要的速度，范围0-255
  motor.run(FORWARD);
  delay(time); //毫秒值
}

void cw(int speed,int time) {
  motor.setSpeed(speed);  // 调节为需要的速度，范围0-255
  motor.run(BACKWARD);
  delay(time); //毫秒值
}

void stop(int time) {
  motor.setSpeed(0);  // 停止
  motor.run(RELEASE);
  delay(time); //毫秒值
}