#define GPIO1 PA0         
#define GPIO2 PA1          
#define GPIO3 PA5
#define GPIO4 PA6
#define GPIO5 PA4   

#define tofAddress1 29
#define tofAddress2 30
#define tofAddress3 31
#define tofAddress4 32
#define tofAddress5 33

VL53L0X tof1;
VL53L0X tof2;
VL53L0X tof3;
VL53L0X tof4;
VL53L0X tof5;

float tof[5];

void TOFSetUp(){
  pinMode(GPIO1, OUTPUT);
  pinMode(GPIO2, OUTPUT);
  pinMode(GPIO3, OUTPUT);
  pinMode(GPIO4, OUTPUT);
  pinMode(GPIO5, OUTPUT);
  digitalWrite(GPIO1, LOW);
  digitalWrite(GPIO2, LOW);
  digitalWrite(GPIO3, LOW);
  digitalWrite(GPIO4, LOW);
  digitalWrite(GPIO5, LOW);

  digitalWrite(GPIO1, HIGH);
  delay(10);
  tof1.init();
  tof1.setTimeout(10);
  // Set the address for the first sensor
  tof1.setAddress(tofAddress1);
  // Start continuous measurement for the first sensor
  tof1.startContinuous();
/*
  digitalWrite(GPIO2, HIGH);
  delay(10);
  tof2.init();
  tof2.setTimeout(10);
  // Set the address for the second sensor
  tof2.setAddress(tofAddress2);
  // Start continuous measurement for the second sensor
  tof2.startContinuous();
*/
  digitalWrite(GPIO3, HIGH);
  delay(10);
  tof3.init();
  // Set the address for the first sensor
  tof3.setAddress(tofAddress3);
  // Start continuous measurement for the first sensor
  tof4.startContinuous();
/*
  digitalWrite(GPIO4, HIGH);
  delay(10);
  tof4.init();
  // Set the address for the second sensor
  tof4.setAddress(tofAddress4);
  // Start continuous measurement for the second sensor
  tof4.startContinuous();
*/
  digitalWrite(GPIO5, HIGH);
  delay(10);
  tof5.init();
  // Set the address for the second sensor
  tof5.setAddress(tofAddress5);
  // Start continuous measurement for the second sensor
  tof5.startContinuous();
}

void TOFRead(){
  tof[0] = tof1.readRangeSingleMillimeters();
 // tof[1] = tof2.readRangeSingleMillimeters();
  tof[2] = tof3.readRangeSingleMillimeters();
 // tof[3] = tof4.readRangeSingleMillimeters();
  tof[4] = tof5.readRangeSingleMillimeters();
}

void TOFPrint(){
  Serial1.print("TOF0 : ");
  Serial1.println(tof[0]);
  //Serial1.print("TOF1 : ");
  //Serial1.println(tof[1]);
  Serial1.print("TOF2 : ");
  Serial1.println(tof[2]);
 // Serial1.print("TOF3 : ");
 // Serial1.println(tof[3]);
  Serial1.print("TOF4 : ");
  Serial1.println(tof[4]);
}