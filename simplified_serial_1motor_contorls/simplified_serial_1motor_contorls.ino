#include <SyRenSimplified.h> //for the SyRen Motor Controller

SyRenSimplified Drive(Serial1); //<-TX1, pin 18 == 'Serial1'

int forward=127; //max int value to go forward
int stop=0; //int value for full stop
int reverse=-127; //max int value to go in reverse
int speed;
byte inbyte=0;


void setup() {
  Serial.begin(9600);
  Serial1.begin(9600); //baud rate is set to 9600 according to the dip switches (datasheet is on the drive)
  Serial.println("enter command:");
  speed=0;
}


void loop() {
  inbyte=Serial.read();
  if (inbyte=='w')
  {
    Serial.println("w");
    if(speed<=(117)) 
    {
      speed+=10;
    }
    Drive.motor(speed);
   //delay(2000);
  }
  if (inbyte=='s')
  {
    Serial.println("s");
    if (speed>=(-117)){
      speed-=10;
    }
  	Drive.motor(speed);
    //delay(2000);
  }
  if (inbyte=='d')
  {
    Serial.println("d");
    while (speed>0)
    {
      speed-=1;
      Drive.motor(speed);
      delay(20);
    }
    while (speed<0)
    {
      speed+=1;
      Drive.motor(speed);
      delay(20);
    }
    //Drive.motor(stop);
    //delay(2000);
  }
}
