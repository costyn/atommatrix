#include <stdint.h>
#include <Arduino.h>
#include "MPU6886.h"
#include <PrintEx.h>

static MPU6886 mpu;
PrintEx serial = Serial;

void setup(void)
{
    Serial.begin(115200);
    mpu.Init();

    mpu.CalibrateGyro(10);
}

void loop(void)
{
    // float x, y, z;
    float pitch,roll,yaw;

    // mpu.getAccelData(&x, &y, &z);
    mpu.getAhrsData(&pitch, &roll, &yaw);

    // Serial.printf("accel: %.6f\t %.6f\t %.6f\n", &x, &y, &z);
    serial.printf("pitch: %.6f\t roll %.6f\t yaw %.6f\n", pitch, roll, yaw);
    // int activityLevel = round( (abs( x )  + abs( y )  + abs( z )) / 3 );

    // if( activityLevel > 3 ) {
    //   Serial.println("Rolling!");
    // }
    //   Serial.print("Activity ");
    //   Serial.println(activityLevel);

      delay(100);

}
