#include <Servo.h>
#include <Ultrasonic.h>
#include "IRremote.h"

Servo ultraSonicServo;
int const in1 = 6;
int const in2 = 7;
int const in3 = 8;
int const in4 = 9;
int const ENRight = 5;
int const ENLeft = 11;
int const echoPin = A4;  
int const triggerPin = A5;
int servoPosition = 135;
int servoSpinDelay = 10;
bool willCollide = false;
long long lastServoSpin = millis();
bool servoSpinDirection = true;
int distanceAway = 0;
#define okIRButton 16712445
#define forwardIRButton 16736925
#define backIRButton 16754775
#define leftIRButton 16720605
#define rightIRButton 16761405
#define stopUnknown 3622325019
#define forwardUnknown 5316027
#define backUnknown 2747854299
#define leftUnknown 1386468383
#define rightUnknown 553536955
int IRReceiverPin = 12;
int long val = 0;
Ultrasonic ultrasonic(triggerPin,echoPin);
IRrecv IRReceiver(IRReceiverPin);
decode_results results;

void driveForward(){
  digitalWrite(ENRight,HIGH);
  digitalWrite(ENLeft,HIGH);
  digitalWrite(in1,HIGH); // in1 and in4 control the motors to move forward direction while in2 and in3 control the motors to move backwards
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void driveBackward(){
  digitalWrite(ENRight,HIGH);
  digitalWrite(ENLeft,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void driveRight(){
  analogWrite(ENRight,115);
  digitalWrite(ENLeft,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void driveLeft(){
  analogWrite(ENRight,115);
  digitalWrite(ENLeft,HIGH);  
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void driveStop(){
  digitalWrite(ENRight,LOW);
  digitalWrite(ENLeft,LOW);
}

void setup() {
  Serial.begin(9600);
  ultraSonicServo.attach(3);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENRight,OUTPUT);
  pinMode(ENLeft,OUTPUT);
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);
  digitalWrite(ENRight,HIGH);
  digitalWrite(ENLeft,HIGH);
  IRReceiver.enableIRIn();
  ultraSonicServo.write(90);
}

void loop() {
if((millis() - lastServoSpin) >= servoSpinDelay){
    if(servoSpinDirection == true){
      servoPosition--;
    }
    else{
      servoPosition++;
    }
    ultraSonicServo.write(servoPosition);

    if(ultraSonicServo.read() <= 45 or ultraSonicServo.read() >= 135){
       servoSpinDirection = !servoSpinDirection; 
      }
    distanceAway = ultrasonic.distanceRead();
    Serial.print(servoPosition);
    Serial.print(",");
    Serial.print(distanceAway);
    Serial.print(".");
    lastServoSpin = millis();
  }
  while(IRReceiver.decode(&results)){
    val = results.value;
    IRReceiver.resume();
    switch(val){
      case okIRButton: 
      case stopUnknown: driveStop(); break;
      case forwardIRButton: 
      case forwardUnknown: driveForward(); break;
      case backIRButton: 
      case backUnknown: driveBackward(); break;
      case leftIRButton: 
      case leftUnknown: driveLeft(); break;
      case rightIRButton: 
      case rightUnknown: driveRight(); break;
    }
  }
}
