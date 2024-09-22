float currentAngleZ;
float angleDiff;
float initialAngleZ;

MPU6050 mpu6050(Wire);

void gyrosetup() {
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  delay(500); 
}

void gyroloop() {

        mpu6050.update();
        currentAngleZ = mpu6050.getAngleZ();
        angleDiff = currentAngleZ - initialAngleZ;

        // Check if angleZ has crossed 90 or -90 degrees
        if (angleDiff >= 91 || angleDiff <= -91) {
            initialAngleZ = currentAngleZ;  // Reset the initial angle
            // Optionally, you can add other actions here when the condition is met
        }

        Serial1.print("angle : ");
        Serial1.println(mpu6050.getAngleZ());
        Serial1.println(angleDiff);

}