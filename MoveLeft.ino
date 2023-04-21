#include <Servo.h>

Servo baseServo;
Servo wristServo;

int goal = 180; //keep between 180 and 0
bool ran = false;

//Jacob variables
int button1 = 7;
int button2 = 8;

int switchState1 = 0;
int switchState2 = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  baseServo.attach(5);
  wristServo.attach(6);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  
}

void loop()
{

  switchState1 = digitalRead(button1);
  switchState2 = digitalRead(button2);
  Serial.println(digitalRead(button1));
  if(switchState1 == HIGH)   //adding 5 degrees to baseServo if button 1 press
  {
    goal = goal + 5;  
    baseServo.write(goal/1.5);

  }

  if(switchState2 == HIGH)   //subtracting 5 degrees to baseServo if button 2 press
  {
    goal = goal - 5;  
    baseServo.write(goal/1.5);

  }
}
