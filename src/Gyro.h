float currentAngleZ;
float angleDiff;
float initialAngleZ;

MPU6050 mpu6050(Wire);

void gyrosetup() {
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
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

        mySerial.print("angle : ");
        mySerial.println(mpu6050.getAngleZ());
        mySerial.println(angleDiff);

}