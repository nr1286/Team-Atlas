#include <SyRenSimplified.h> //for the SyRen Motor Controller

SyRenSimplified Drive(Serial1); //<-TX1, pin 18 == 'Serial1'

static int forward=127; //max int value to go forward
static int stop //int value for full stop
static int reverse=-127; //max int value to go in reverse

void setup() {
  Serial1.begin(9600); //baud rate is set to 9600 according to the dip switches (datasheet is on the drive)
}


void loop() {
  Drive.motor(forward);//go forward
  delay(100);
  Drive.motor(stop)//stop
  delay(100);
  Drive.motor(reverse)//go backwards
  dealay(100);
  Drive.motor(stop)//end
}
