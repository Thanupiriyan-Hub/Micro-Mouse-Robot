#define PWMA PB8    //motor driver pins
#define AIN2 PA12
#define AIN1 PA7
#define STBY PA8
#define BIN1 PB1
#define BIN2 PB0
#define PWMB PB9

void motorDiver(){
    pinMode(PWMA, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(STBY, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMB, OUTPUT);

}

int leftBase =200;
int rightBase = 200;
int leftPwm ;
int rightPwm ;

void stbyHigh()
{
    digitalWrite(STBY, HIGH);
}

void stbyLow()
{
    digitalWrite(STBY, LOW);
}

void leftForward()
{
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
}

void leftReverse()
{
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
}

void leftBrake()
{
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, HIGH);
}

void leftForwardBase()
{
    stbyHigh();
    leftForward();
    analogWrite(PWMA, leftBase);
}

void leftReverseBase()
{
    stbyHigh();
    leftReverse();
    analogWrite(PWMA, leftBase);
}

void rightForward()
{
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
}

void rightReverse()
{
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
}

void rightBrake()
{
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, HIGH);
}

void rightForwardBase()
{
    stbyHigh();
    rightForward();
    analogWrite(PWMB, rightBase);
}

void rightReverseBase()
{
    stbyHigh();
    rightReverse();
    analogWrite(PWMB, rightBase);
}

void writePwm()
{
    analogWrite(PWMA, leftBase+leftPwm);
    analogWrite(PWMB, rightBase+rightPwm);
}

void writeBasePwm()
{
    analogWrite(PWMA, leftBase);
    analogWrite(PWMB, rightBase);
}

void forward()
{
    stbyHigh();
    leftForward();
    rightForward();
    writePwm();
    // Serial1.print("Motor left pwm");
    // Serial1.print(leftBase+leftPwm);
    // Serial1.print("  Motor right pwm");
    // Serial1.println(rightBase+rightPwm);
}

void reverse()
{
    stbyHigh();
    leftReverse();
    rightReverse();
    writePwm();
}

void brake()
{
    stbyHigh();
    leftBrake();
    rightBrake();
    delay(75);
}

void brakeNo()
{
    stbyHigh();
    leftBrake();
    rightBrake();
    //delay(100);
}

void forwardBase()
{
    stbyHigh();
    leftForward();
    rightForward();
    writeBasePwm();
}

void reverseBase()
{
    stbyHigh();
    leftReverse();
    rightReverse();
    writeBasePwm();
}

void turnRight()
{
    stbyHigh();
    leftForward();
    rightReverse();
    writeBasePwm();
}

void turnLeft()
{
    stbyHigh();
    leftReverse();
    rightForward();
    writeBasePwm();
}
