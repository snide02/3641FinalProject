#include <Servo.h>
//Jacob's
Servo baseServo;
Servo wristServo;

int goal = 180; //keep between 180 and 0
bool ran = false;

//Jacob variables
int button1 = 7;
int button2 = 8;

int switchState1 = 0;
int switchState2 = 0;

/*
int sensorValue_B1;
float voltage_B1;
int sensorValue_B2;
float voltage_B2;
*/

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  baseServo.attach(5);
  wristServo.attach(6);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  
}

/*void loop(){
  //Serial.println(baseServo.read());
  if(!ran){
    Serial.println(baseServo.read());
    baseServo.write(90);
    ran = true;
    Serial.println(baseServo.read());
  }
}
*/

/*  Michael's loop
void loop() {
  // put your main code here, to run repeatedly:
  //if(!ran){
  //if(goal != baseServo.read()){
      //for(int pos = goal; pos >= baseServo.read();pos -=1){
        baseServo.write(goal/1.5);
        wristServo.write(180 - goal); 
        ran = true;
      //}
  //} 
}
*/

void loop()
{
  /*  
  sensorValue_B1 = analogRead(A1);
  sensorValue_B2 = analogRead(A2);
  
  voltage_B1 = sensorValue_B1 * (5.0 / 1023.0);
  voltage_B2 = sensorValue_B2 * (5.0 / 1023.0);
  */

  switchState1 = digitalRead(button1);
  switchState2 = digitalRead(button2);
  Serial.println(digitalRead(button1));
  if(switchState1 == HIGH)   //adding 5 degrees to baseServo if button 1 press
  {
    goal = goal + 5;  
    baseServo.write(goal/1.5);

    //delay(500);
  }

  if(switchState2 == HIGH)   //subtracting 5 degrees to baseServo if button 2 press
  {
    goal = goal - 5;  
    baseServo.write(goal/1.5);

    //delay(500);
  }
}
