float currentAngleZ;
float angleDiff;
float initialAngleZ;

MPU6050 mpu6050(Wire);

void gyrosetup() {
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  delay(500); 
}

bool Disable90Turn = 1;
bool Disable180Turn = 1;

void gyroloop() {

        mpu6050.update();
        currentAngleZ = mpu6050.getAngleZ();
        angleDiff = currentAngleZ - initialAngleZ;

        // Check if angleZ has crossed 90 or -90 degrees
        if (angleDiff >= 86 || angleDiff <= -86) {
            initialAngleZ = currentAngleZ;  // Reset the initial angle
            Disable90Turn = 0;
            Disable180Turn = 0;
            // Optionally, you can add other actions here when the condition is met
        }

        Serial1.print(" | A: ");
        Serial1.print(mpu6050.getAngleZ());
        Serial1.print(" | AD: ");
        Serial1.println(angleDiff);

}