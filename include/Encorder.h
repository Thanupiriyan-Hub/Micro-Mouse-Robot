#define ENCLA PB13 //encoder left A (interrupt pin)
#define ENCLB PB12 //encoder left B (interrupt pin)
#define ENCRA PB14 //encoder right A (interrupt pin)
#define ENCRB PB15 //encoder right B (interrupt pin)
/*
int leftEncoder;
int rightEncoder;
int encoderLeftCount;
int encoderRightCount;

void motorInterrupt()
{
    pinMode(ENCLA, INPUT);
    pinMode(ENCLB, INPUT);
    pinMode(ENCRA, INPUT);
    pinMode(ENCRB, INPUT);
}

void countENCLA()
{
    if (digitalRead(ENCLA) == HIGH && digitalRead(ENCLB) == LOW)
    {
        leftEncoder = leftEncoder + 1;
    }
    else if (digitalRead(ENCLA) == HIGH && digitalRead(ENCLB) == HIGH)
    {
        leftEncoder = leftEncoder - 1;
    }
}

void countENCLB()
{
    if (digitalRead(ENCLB) == HIGH && digitalRead(ENCLA) == HIGH)
    {
        leftEncoder = leftEncoder + 1;
    }
    else if (digitalRead(ENCLB) == HIGH && digitalRead(ENCLA) == LOW) 
    {
        leftEncoder = leftEncoder - 1;
    }
}

void countENCRA()
{
    if (digitalRead(ENCRA) == HIGH && digitalRead(ENCRB) == LOW)
    {
        rightEncoder = rightEncoder - 1;
    }
    else if (digitalRead(ENCRA) == HIGH && digitalRead(ENCRB) == HIGH)
    {
        rightEncoder = rightEncoder + 1;
    }
}

void countENCRB()
{
    if (digitalRead(ENCRB) == HIGH && digitalRead(ENCRA) == HIGH)
    {
        rightEncoder = rightEncoder - 1;
    }
    else if (digitalRead(ENCRB) == HIGH && digitalRead(ENCRA) == LOW)
    {
        rightEncoder = rightEncoder + 1;
    }
}
*/