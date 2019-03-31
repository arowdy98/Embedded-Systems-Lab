#include <Wire.h> //I2C Arduino Library

#define raddr 0x0D //I2C Address for The QMC5883
#define waddr 0x0D
float heading_in_degrees;

void setup(){
  
  Serial.begin(9600);
  Wire.begin();
  
  
  Wire.beginTransmission(waddr); //start talking
  Wire.write(0x0B); // Set the Register
  Wire.write(0x01); // Tell the QMC5883 to Continuously Measure
  Wire.endTransmission();

  Wire.beginTransmission(waddr); //start talking
  Wire.write(0x09); // Set the Register
  Wire.write(0x1D); // Tell the QMC5883 to Continuously Measure
  Wire.endTransmission();
}


void loop(){
  
  int x,y,z; //triple axis data

  //Tell the QMC what regist to begin writing data into
  Wire.beginTransmission(waddr);
  Wire.write(0x00); //start with register 3.
  Wire.endTransmission();
 
 //Read the data.. 2 bytes for each axis.. 6 total bytes
  Wire.requestFrom(raddr, 6);
  if(6<=Wire.available()){
    x = Wire.read()<<8; //MSB  x 
    x |= Wire.read(); //LSB  x
    z = Wire.read()<<8; //MSB  z
    z |= Wire.read(); //LSB z
    y = Wire.read()<<8; //MSB y
    y |= Wire.read(); //LSB y
  }
  heading_in_degrees = 180 * atan2(y,x)/PI;
  Serial.println(heading_in_degrees);
  // Show Values
//  Serial.print("X Value: ");
  Serial.println(x);
//  Serial.print("Y Value: ");
//  Serial.println(y);
//  Serial.print("Z Value: ");
//  Serial.println(z);
//  Serial.println();
  
  delay(100);
}
