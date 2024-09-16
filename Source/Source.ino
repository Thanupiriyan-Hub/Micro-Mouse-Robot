#define mySerial Serial1

//Original libraries 
#include <Wire.h>
#include <VL53L0X.h>

//Local Head files
#include "Motor.h"
#include "TOF.h"

void setup() {
  mySerial.begin(9600);
  Wire.begin();
  TOFSetUp();
}

void loop() {
  TOFRead();
  TOFPrint();
  delay(300);
}

