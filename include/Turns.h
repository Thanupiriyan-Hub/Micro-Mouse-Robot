
void turnNinetyRight()
{
   while(angleDiff>-85 && Disable90Turn==1){
    gyroloop();
    turnRight();
  }
  brakeNo();
  delay(75);
  stbyLow();
}

void turnNinetyLeft()
{
  while(angleDiff<85 && Disable90Turn==1){
    gyroloop();
    turnLeft();
  }
  brakeNo();
  delay(75);
  stbyLow();
}

void rightAboutTurn()
{
   while(angleDiff>-85 && Disable90Turn==1){
    gyroloop();
    turnRight();
    Disable180Turn=1;
  } 
  brakeNo();
  delay(75);
  //stbyLow();
  while(angleDiff>-85 && Disable180Turn==1){
    gyroloop();
    turnRight();
  } 
  brakeNo();
  delay(75);
  stbyLow();
}

void LeftAboutTurn()
{
   while(angleDiff<85 && Disable90Turn==1){
    gyroloop();
    turnLeft();
    Disable180Turn=1;
  } 
  brakeNo();
  delay(75);
  //stbyLow();
  while(angleDiff<85 && Disable180Turn==1){
    gyroloop();
    turnLeft();
  } 
  brakeNo();
  delay(75);
  stbyLow();
}