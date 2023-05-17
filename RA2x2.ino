// Robotic arm 2x2

// Libraries
#include <Servo.h>
#include<Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Global Variables
#define numOfValsRec 5
#define digitsPerValRec 1
int receivedarray[numOfValsRec];
int stringLength=numOfValsRec*digitsPerValRec+1;
int counter=0;
bool counterStart=false;
char recievedString[5];

// PWM Setup
Adafruit_PWMServoDriver root = Adafruit_PWMServoDriver(0x40);
uint8_t servonum = 0;

#define servo1 0 //base
#define servo2 1 //elbow
#define servo3 2 // gripper
#define servo4 3 // shoulder


void setup() {

  Serial.begin(9600);
  root.begin();

  //SETTING THE FREQUENCY OF THE PWM SERVO DRIVER
  root.setPWMFreq(60);

}

// Receiving data from python script as string 
// of format("$xy")[x is ranging from 1-4, y is either 1 or 0] then converting x and y to int 
// and puting it in a array

void receiveData() {
  while(Serial.available()){
    char c = Serial.read();
    if (c=='$'){
      counterStart = true;

    }
    if (counterStart){
      
       if (counter<stringLength){
     receivedarray[counter]=int(c);
     counter++;
       }
       else{
        counter=0;
        counterStart=false;
       }
    }
  
  }
}
void loop() {
  receiveData();
  // Check with serial monitor
  // Serial.println(receivedarray[1]);     
  // Serial.println(receivedarray[2]);     
  if (receivedarray[1]==49){
      // For location A
      root.setPWM(servo1,0,125);
      root.setPWM(servo2,0,350);
      root.setPWM(servo4,0,125);
      delay(500);
  }
  else if (receivedarray[1]==50){
      // For location B
      root.setPWM(servo1,0,575);
      root.setPWM(servo2,0,350);
      root.setPWM(servo4,0,125);
      delay(500);
  }
  else if (receivedarray[1]==51){
      // For location C
      root.setPWM(servo1,0,125);
      root.setPWM(servo2,0,300);
      root.setPWM(servo4,0,275);
      delay(500);
  }
  else if (receivedarray[1]==52){
      // For location D
      root.setPWM(servo1,0,575);
      root.setPWM(servo2,0,300);
      root.setPWM(servo4,0,275);
      delay(500);
  }
  
  if (receivedarray[2]==49){
      // Gripper Open
      root.setPWM(servo3,0,175);
      delay(500);
  }
  else{
      // Gripper Close
      root.setPWM(servo3,0,237.5);   
  delay(500);
  }
  // Resetting the array
  receivedarray[0]=0;
  receivedarray[1]=0;
}