
#define GPIO1 PA0        
#define GPIO2 PA1          
#define GPIO3 PA5
#define GPIO4 PA6
#define GPIO5 PA4   

#define tofAddress1 0x30
#define tofAddress2 0x31
#define tofAddress3 0x32
#define tofAddress4 0x33
#define tofAddress5 0x34

VL53L0X tof1;
VL53L0X tof2;
VL53L0X tof3;
VL53L0X tof4;
VL53L0X tof5;

int tof[5];

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
  delay(50);
  tof1.setTimeout(50);
  tof1.init(); 
  tof1.setAddress(tofAddress1);
  tof1.startContinuous();

  digitalWrite(GPIO2, HIGH);
  delay(50);
  tof2.setTimeout(50);
  tof2.init();
  tof2.setAddress(tofAddress2);
  tof2.startContinuous();

  digitalWrite(GPIO3, HIGH);
  delay(50);
  tof3.setTimeout(50);
  tof3.init();
  tof3.setAddress(tofAddress3);
  tof3.startContinuous();

  digitalWrite(GPIO4, HIGH);
  delay(50);
  tof4.setTimeout(50);
  tof4.init();
  tof4.setAddress(tofAddress4);
  tof4.startContinuous();

  digitalWrite(GPIO5, HIGH);
  delay(50);
  tof5.setTimeout(50);
  tof5.init();
  tof5.setAddress(tofAddress5);
  tof5.startContinuous();
}

void TOFRead(){
  tof[0] = tof1.readRangeContinuousMillimeters();
  tof[1] = tof2.readRangeContinuousMillimeters();
  tof[2] = tof3.readRangeContinuousMillimeters();
  tof[3] = tof4.readRangeContinuousMillimeters();
  tof[4] = tof5.readRangeContinuousMillimeters();
}

void TOFPrint(){
  Serial1.print("T0: ");
  Serial1.print(tof[0]);
  Serial1.print(" | T1: ");
  Serial1.print(tof[1]);
  Serial1.print(" | T2: ");
  Serial1.print(tof[2]);
  Serial1.print(" | T3 : ");
  Serial1.print(tof[3]);
  Serial1.print(" | T4: ");
  Serial1.println(tof[4]);
}
