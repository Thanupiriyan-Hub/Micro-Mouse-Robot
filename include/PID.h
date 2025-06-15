// #include <Arduino.h>
// #include "TOF.h" // Assuming you have your ToF sensor library
// #include "Motor.h"



// PID constants
float Kp = 1.0, Ki = 0.0, Kd = 2;
#define BT_SERIAL Serial1
// Target distance and tolerance
const float targetDistanceL = 106.0;
const float targetDistanceR = 96.0;
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
    float rightDistance = tof[4];

    // Calculate time delta
    long currentTime = millis();
    float deltaTime = (currentTime - lastTime) / 1000.0;

    errorL = targetDistanceL - leftDistance;
    errorR = targetDistanceR - rightDistance;
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
    
    if(((-5 < errorL)&& (errorL< 5)) || ((-5 < errorR) && (errorR< 5) )){
        errorL = 0;
        errorR = 0;
        // Serial1.println(errorL);
    }
    if(errorL==errorR){
        leftPwm =0;
        leftPwm =0;
    }
        else if(errorL>errorR){
                leftPwm = constrain((PoutL + IoutL + DoutL), 0, 55);
                rightPwm = constrain(-(PoutL + IoutL + DoutL), 0, 55);
        }
        else{
            rightPwm = constrain((PoutR + IoutR + DoutR), 0, 55);
            leftPwm = constrain(-(PoutR + IoutR + DoutR), 0, 55);
        }
    }
    else if(leftDistance<200 || rightDistance<200){
    if(((-5 < errorL)&& (errorL< 5)) || ((-5 < errorR) && (errorR< 5) )){
        errorL = 0;
        errorR = 0;
        // Serial1.println(errorL);
    }
    if(errorL==errorR){
        leftPwm =0;
        leftPwm =0;
    }
    if(leftDistance<200 && rightDistance>200){
        //right no walls but move forward code
      if(errorL>0){
        //move to right
        leftPwm = constrain((PoutL + IoutL + DoutL), 0, 55);
        rightPwm = constrain(-(PoutL + IoutL + DoutL), 0, 55);
    }
    else if(errorL<0){
        //move to left
        leftPwm = constrain(-(PoutL + IoutL + DoutL), 0, 55);
        rightPwm = constrain((PoutL + IoutL + DoutL), 0, 55);
    }
    else{
        //error 0
        leftPwm = 0;
        rightPwm = 0;
    }

    }
    else if(rightDistance<200 && leftDistance>200){
        //left no walls but move forward code

        if(errorR>0){
            //move to left
            rightPwm = constrain((PoutR + IoutR + DoutR), 0, 55);
            leftPwm = constrain(-(PoutR + IoutR + DoutR), 0, 55);
    }
        else if(errorR<0){
            //move to right
            rightPwm = constrain(-(PoutR + IoutR + DoutR), 0, 55);
            leftPwm = constrain((PoutR + IoutR + DoutR), 0, 55); 
    }
        else{
        //error 0
        leftPwm = 0;
        rightPwm = 0;
    }

    }
    }
    else{
    // no walls zero error, can't calculate error using tof
brake();
    }

    // Update motor control
    Serial1.print("Left Pwm : ");
    Serial1.print(leftPwm);
    Serial1.print("  || Right Pwm :  ");
    Serial1.println(rightPwm);
    // Serial1.print("Left Distance :  ");
    // Serial1.print(leftDistance);
    // Serial1.print("  || Right Distance :  ");
    // Serial1.println(rightDistance);
    Serial1.print("Left error :  ");
    Serial1.print(errorL);
    Serial1.print("Right error :  ");
    Serial1.println(errorR);
    Serial1.print("   KP: ");
    Serial1.print(Kp);
    Serial1.print(" KD: ");
    Serial1.print(Kd);
    Serial1.print("   KI: ");
    Serial1.println(Ki);
    forward();
    
    // Store previous errors
    prevErrorL = errorL;
    prevErrorR = errorR;

    // Update last time
    lastTime = currentTime;
}
void readBluetoothPID() {
    if (BT_SERIAL.available()) {
        char command = BT_SERIAL.read();
        Serial1.print("BT available: ");
        BT_SERIAL.println(command);

        switch (command) {
            case 'p': // Adjust Kp
                Kp = BT_SERIAL.parseFloat();
                BT_SERIAL.print("Kp updated: ");
                BT_SERIAL.println(Kp);
                break;
            case 'i': // Adjust Ki
                Ki = BT_SERIAL.parseFloat();
                BT_SERIAL.print("Ki updated: ");
                BT_SERIAL.println(Ki);
                break;
            case 'd': // Adjust Kd
                Kd = BT_SERIAL.parseFloat();
                BT_SERIAL.print("Kd updated: ");
                BT_SERIAL.println(Kd);
                break;
            default:
                BT_SERIAL.println("Unknown command. Use 'P', 'I', or 'D' to adjust PID.");
                break;
        }
    }
}
