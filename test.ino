#include "BTNLED.h"
#include "MOTOR.h"
#include "OLED.h"

#define ON 1
#define OFF 2

bool Running;

void setup()
{
  initGpio();
  Running = false;
}

void loop()
{
  show2();
  begin:
  if(btnPush(BTN2))
  {
    Running = true;
  }
  while(!Running) goto begin;

  delay(500);
  controlLed(LED2, ON);
  delay(500);
  controlLed(LED3, ON);
  delay(500);

  //for(int i = 0; i<5; i++)
  //{
  //  speedBothMotorTime(100,100,2500);
  //  delay(300);
  //  speedBothMotorTime(100,-100,800);
  //  delay(300);
  //}
  speedBothMotorTime(50,50,4000);
  delay(300);
  speedBothMotorTime(50,-50,1350);
  delay(300);

  speedBothMotorTime(50,50,4000);
  delay(300);
  speedBothMotorTime(50,-50,1500);
  delay(300);

  speedBothMotorTime(50,50,4000);
  delay(300);
  speedBothMotorTime(50,-50,1520);
  delay(300);

  speedBothMotorTime(50,50,4000);
  delay(300);
  speedBothMotorTime(50,-50,1500);
  delay(300);

  speedBothMotorTime(50,50,4000);
  delay(300);
  speedBothMotorTime(50,-50,1470);
  delay(300);


  speedBothMotor(0,0);
  Running = false;
  controlLed(LED2, OFF);
  controlLed(LED3, OFF);
}