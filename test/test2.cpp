#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_SPIDevice.h>
// #include "utility/Adafruit_MotorShield.h"

// 创建 Adafruit Motor Shield 对象
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// 获取电机对象
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);  // 使用电机4

void setup() {
  Serial.begin(9600);           // 初始化串口
  AFMS.begin();                 // 启动 Adafruit Motor Shield
  myMotor->setSpeed(128);       // 设置电机的速度
}

void loop() {
  // 正转
  Serial.println("Forward!");
  myMotor->run(FORWARD);
  delay(2000);  // 正转2秒

  // 停止
  
  myMotor->run(RELEASE);
  delay(1000);  // 停止1秒

  // 反转
  Serial.println("Release!");
  myMotor->run(BACKWARD);
  delay(2000);  // 反转2秒

  // 停止
  myMotor->run(RELEASE);
  delay(1000);  // 停止1秒
}
