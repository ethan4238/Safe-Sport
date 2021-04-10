#include "Wire.h"  // Arduino Wire library
#include "I2Cdev.h"  //bibliothèque I2Cdev à installer
#include "MPU6050.h" //bibliothèque MPU6050 à installer
//AD0 low = 0x68 (default for InvenSense evaluation board)
//AD0 high = 0x69
MPU6050 mpu6050;
 
int16_t ax, ay, az;  //mesures brutes

 
void setup() {
  Wire.begin();  // bus I2C
  Serial.begin(9600); // liaison série
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB (LEONARDO)
  }
  mpu6050.initialize();  // initialize device
}
 
void loop() {

  
  int g;
  
  mpu6050.getAcceleration(&ax, &ay, &az);

g = sqrt(ax^2+ay^2+az^2);
 
  // Affichage accel x/y/z
 /*     Serial.print("a/g:\t");
  Serial.print(ax); 
  Serial.print("\t");
  Serial.print(ay); 
  Serial.print("\t");
  Serial.print(az); 
  Serial.print("\t");
  Serial.println("\t");   */
  Serial.print("g =  ");
  Serial.println(g);
  
  delay(500);  
}
