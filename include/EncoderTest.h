volatile int posiL = 0; //possion increment left encoder
volatile int posiR = 0; //possion increment right encoder

void readEncoderL(){
  int bL = digitalRead(ENCLB);//left encoder pin b
  if(bL > 0){
    posiL++;
  }
  else{
    posiL--;
  }
}
void readEncoderR(){
  int bR = digitalRead(ENCRB);//right encoder pin b
  if(bR > 0){
    posiR++;
  }
  else{
    posiR--;
  }
}
void Encordersetup() {
  pinMode(ENCLA,INPUT);
  pinMode(ENCLB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCLA),readEncoderL,RISING);

  pinMode(ENCRA,INPUT);
  pinMode(ENCRB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCRA),readEncoderR,RISING);
}

void Encorderloop() {
// Read the position
  int posL = 0; 
  int posR = 0; 
  noInterrupts(); // disable interrupts temporarily while reading
  posL = posiL;
  posR = posiR;
  interrupts(); // turn interrupts back on
  Serial1.print("Possion Left : ");
  Serial1.print(posL);
  Serial1.print("Possion Right : ");
  Serial1.println(posR);
}