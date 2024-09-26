// #include <Arduino.h>
// #include "TOF.h" // Assuming you have your ToF sensor library
// #include "Motor.h"



// PID constants
float Kp = 1.0, Ki = 0.1, Kd = 0.05;

// Target distance and tolerance
const float targetDistance = 100.0;
const float tolerance = 3.0;

// PID variables for left and right motors
float errorL, errorR;
float integralL = 0, integralR = 0;
float prevErrorL = 0, prevErrorR = 0;
long lastTime = 0;


// PID control function for both motors
void pidControlMotors() {
    // Read ToF sensor values
    float leftDistance = tof[0];
    float rightDistance = tof[1];

    // Calculate time delta
    long currentTime = millis();
    float deltaTime = (currentTime - lastTime) / 1000.0;

    errorL = targetDistance - leftDistance;
    errorR = targetDistance - rightDistance;
    float PoutL = Kp * errorL;
    integralL += errorL * deltaTime;
    float IoutL = Ki * integralL;
    float derivativeL = (errorL - prevErrorL) / deltaTime;
    float DoutL = Kd * derivativeL; 

    float PoutR = Kp * errorR;
    integralR += errorR * deltaTime;
    float IoutR = Ki * integralR;
    float derivativeR = (errorR - prevErrorR) / deltaTime;
    float DoutR = Kd * derivativeR;
    if(leftDistance<200 && rightDistance<200){
        if(errorL>errorR){
                leftPwm = constrain(leftBase + (PoutL + IoutL + DoutL), 0, 40);
                rightPwm = constrain(leftBase - (PoutL + IoutL + DoutL), 0, 40);
        }
        else{
            rightPwm = constrain(rightBase + (PoutR + IoutR + DoutR), 0, 40);
            leftPwm = constrain(rightBase - (PoutR + IoutR + DoutR), 0, 40);
        }
    }
    else if(leftDistance<200 || rightDistance<200){

    if(leftDistance<200 && rightDistance>200){
        //right no walls but move forward code
      if(errorL>0){
        //move to right
        leftPwm = constrain(leftBase + (PoutL + IoutL + DoutL), 0, 40);
        rightPwm = constrain(leftBase - (PoutL + IoutL + DoutL), 0, 40);
    }
    else if(errorL<0){
        //move to left
        leftPwm = constrain(leftBase - (PoutL + IoutL + DoutL), 0, 40);
        rightPwm = constrain(leftBase + (PoutL + IoutL + DoutL), 0, 40);
    }
    else{
        //error 0
        leftPwm = constrain(leftBase + (PoutL + IoutL + DoutL), 0, 40);
        rightPwm = constrain(leftBase + (PoutL + IoutL + DoutL), 0, 40);
    }

    }
    else if(rightDistance<200 && leftDistance>200){
        //left no walls but move forward code

        if(errorR>0){
            //move to left
            rightPwm = constrain(rightBase + (PoutR + IoutR + DoutR), 0, 40);
            leftPwm = constrain(rightBase - (PoutR + IoutR + DoutR), 0, 40);
    }
        else if(errorR<0){
            //move to right
            rightPwm = constrain(rightBase - (PoutR + IoutR + DoutR), 0, 40);
            leftPwm = constrain(rightBase + (PoutR + IoutR + DoutR), 0, 40); 
    }

    }
    }
    else{
    // no walls zero error, can't calculate error using tof
    errorL = 0;
    errorR = 0;
    }

    // Update motor control
    forward();
    
    // Store previous errors
    prevErrorL = errorL;
    prevErrorR = errorR;

    // Update last time
    lastTime = currentTime;
}

