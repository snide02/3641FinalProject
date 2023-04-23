AccelStepper stepper(AccelStepper::DRIVER, 12, 11);  //StepPin D12 and DirPin D11

Servo baseServo;
Servo wristServo;

int left = 180; //keep between 180 and 0
int right = 0;
float goal;
bool ran = false;
int test = 360;

//Jacob variables
int button1 = 7;
int button2 = 8;
int button3 = 4;
int button4 = 2;

int switchState1 = 0;
int switchState2 = 0;
int switchState3 = 0;
int switchState4 = 0;


void setup() {
  Serial.begin(9600);
  
  baseServo.attach(5);
  wristServo.attach(6);
  goal = baseServo.read()/1.5;

  Serial.println(goal);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);

  //stepper setup
  stepper.setMaxSpeed(4000);
  stepper.setSpeed(4000);  //5 ROTATIONS PER SECOND. One full rotation = 800 steps = 200 steps * 4 (MS1=0, MS2=1, MS3=0)
  //we set (MS1=0, MS2=0, MS3=1)
}

void loop()
{
  switchState1 = digitalRead(button1);
  switchState2 = digitalRead(button2);
  switchState3 = digitalRead(button3);
  switchState4 = digitalRead(button4);
  
  if(switchState1 == HIGH && goal < left)   //adding 5 degrees to baseServo if button 1 press
  {
    goal = goal + 0.01;  
    baseServo.write(goal/1.5);
    wristServo.write(goal);
    if(goal < 90)
      stepper.setSpeed(2000);
    if(goal > 90)
       stepper.setSpeed(-2000); 
    stepper.runSpeed();
  }

  if(switchState2 == HIGH && goal > right)   //subtracting 5 degrees to baseServo if button 2 press
  {
    goal = goal - 0.01;  
    baseServo.write(goal/1.5);
    wristServo.write(goal);
    if(goal < 90)
      stepper.setSpeed(-2000);
    if(goal > 90)
       stepper.setSpeed(2000);
     stepper.runSpeed();
  }

  if(switchState3 == HIGH){
     stepper.setSpeed(4000); 
     stepper.runSpeed();  
  }
  if(switchState4 == HIGH){
    stepper.setSpeed(-4000); 
    stepper.runSpeed();
  }
}
