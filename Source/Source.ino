#define mySerial Serial1

#include <Wire.h>
#include <VL53L0X.h>

#define GPIO1 PA0         
#define GPIO2 PA1   

#define tofAddress1 29
#define tofAddress2 30

VL53L0X tof1;
VL53L0X tof2;

int measurement1 = 0;
int measurement2 = 0;

void setup() {
  mySerial.begin(9600);
  pinMode(GPIO1, OUTPUT);
  pinMode(GPIO2, OUTPUT);
  digitalWrite(GPIO1, LOW);
  digitalWrite(GPIO2, LOW);

  Wire.begin();

  digitalWrite(GPIO1, HIGH);
  delay(10);
  tof1.init();
  // Set the address for the first sensor
  tof1.setAddress(tofAddress1);
  // Start continuous measurement for the first sensor
  tof1.startContinuous();

  digitalWrite(GPIO2, HIGH);
  delay(10);
  tof2.init();
  // Set the address for the second sensor
  tof2.setAddress(tofAddress2);
  // Start continuous measurement for the second sensor
  tof2.startContinuous();
}

void loop() {
  measurement1 = tof1.readRangeContinuousMillimeters();
  measurement2 = tof2.readRangeContinuousMillimeters();

  mySerial.print("TOF1 : ");
  mySerial.println(measurement1);
  mySerial.print("TOF2 : ");
  mySerial.println(measurement2);
  
  if (tof1.timeoutOccurred()) {
    mySerial.println("TOF1 timeout!");
  }
  
  if (tof2.timeoutOccurred()) {
    mySerial.println("TOF2 timeout!");
  }
  
  delay(200);
}

