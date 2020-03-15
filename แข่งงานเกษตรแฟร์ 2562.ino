#include<Servo.h>
#include<NewPing.h>

const int LeftMotorForward = 3; // 3
const int LeftMotorBackward = 2; // 2
const int RightMotorForward = 5; // 5
const int RightMotorBackward = 4; //4


#define trig_pin A1
#define echo_pin A2
#define maximun_distance 200
boolean goseForward = false;

int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximun_distance);  //sona

Servo servo_motor;

void setup() {
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  servo_motor.attach(11);
  servo_motor.write(90);

  delay(2000);
  distance == readPing();
  delay(100);
  distance == readPing();
  delay(100);
  distance == readPing();
  delay(100);
  distance == readPing();
  delay(100);   
}


void loop() {
  int distanceRight = 21;
  int distanceLeft = 21;
  delay(50);

  if(distance <= 21) {
    moveStop();
    delay(50);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookright();
    delay(400);
    distanceLeft = lookleft();
    delay(400);

  if(distance <= distanceRight&&distance >= distanceLeft) {
    turnRight();
    delay(1150);
    moveStop();
    }
  else if (distance <= distanceLeft&& distance >= distanceRight) {
    turnLeft();
    delay(1150);
    moveStop();
    }
   else if (distance <= distanceLeft&&distance <= distanceRight) {
      moveBackward();
    delay(2000);
    moveStop();
    delay(10000);
    }
  
  
  }
  else {
      moveForward();
    }
  distance = readPing();
}


int lookright() {
  servo_motor.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
  }
int lookleft() {
  servo_motor.write(180);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
  }
  
int readPing() {
  delay(50);
  int cm = sonar.ping_cm();
  if (cm==0) {
    cm = 250;
    
    }
    return cm;
  }
  
void moveStop() {
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward , LOW);
  digitalWrite(LeftMotorBackward, LOW);
  }

void moveForward() {
  if(!goseForward) {
    goseForward = true;

    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);

    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
    }
  }

void moveBackward() {
  goseForward = false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  }

void turnRight() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward,LOW);
  delay(100);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  } 

void turnLeft() {

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(100);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  
  }  
