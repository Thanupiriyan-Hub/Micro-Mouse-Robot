#include <Arduino.h>

HardwaremySerial mySerial(PA10, PA9);

//Original libraries 
#include <Wire.h>
#include <VL53L0X.h>
#include <MPU6050_tockn.h>


//Local Head files
//#include "mpu6500.h"
#include "Motor.h"
#include "TOF.h"
//#include "MGyro.h"
#include "Gyro.h"
#include "Encorder.h"
#include "EncoderTest.h"

#define buzzer PB11

void setup() {
  motorDiver();
  //motorInterrupt();
  stbyHigh();
 mySerial.begin(9600);
  Encordersetup();

  //Wire.begin();
  //Wire.setClock(400000);
  //TOFSetUp();
  gyrosetup();

  pinMode(buzzer, OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(ENCLA), countLeftOut1, RISING);
  //attachInterrupt(digitalPinToInterrupt(ENCLB), countLeftOut1, RISING);
  //attachInterrupt(digitalPinToInterrupt(ENCRA), countRightOut1, RISING);
  //attachInterrupt(digitalPinToInterrupt(ENCRB), countRightOut1, RISING);
  //Gyrosetup();
  }

void loop() {
  //TOFRead();
  //TOFPrint();
  //Gyroloop();
  gyroloop();
  //buzz();
  //delay(300);
   //forwardBase();
   //turnRight();
   rightForwardBase();
   //reverseBase();
   Encorderloop();
}
void buzz()
{
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
}

//