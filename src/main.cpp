#include <Arduino.h>

HardwareSerial Serial1(PA10, PA9);

//Original libraries 
#include <Wire.h>
#include <VL53L0X.h>
#include <MPU6050_tockn.h>


//Local Head files

#include "Motor.h"
#include "TOF.h"
#include "Gyro.h"
#include "Encorder.h"
#include "EncoderTest.h"
#include "Turns.h"
#include "PID.h"

#define buzzer PB11

void setup() {
  motorDiver();
  //motorInterrupt();
  stbyHigh();
  Serial1.begin(9600);
  Encordersetup();

  Wire.begin();
  //Wire.setClock(400000);
  TOFSetUp();
  gyrosetup();

  pinMode(buzzer, OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(ENCLA), countLeftOut1, RISING);
  //attachInterrupt(digitalPinToInterrupt(ENCLB), countLeftOut1, RISING);
  //attachInterrupt(digitalPinToInterrupt(ENCRA), countRightOut1, RISING);
  //attachInterrupt(digitalPinToInterrupt(ENCRB), countRightOut1, RISING);
  //Gyrosetup();
  }
void buzz()
{
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
}
void loop() {
  //buzz();
    TOFRead();
    TOFPrint();
   // TOFInitialize();
    // gyroloop();
  //buzz();
  //delay(300);
   //forwardBase();
   //turnRight();
   //rightForwardBase();
   //reverseBase();
   //Encorderloop();
  //  turnNinetyRight();
   //LeftAboutTurn();
    // Encorderloop();
    // readBluetoothPID();
    // pidControlMotors();
}


//