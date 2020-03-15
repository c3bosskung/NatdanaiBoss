#include <ATX2.h>	// ATX2 Board

#define a1 analog(0)
#define a2 analog(1)
#define a3 analog(2)
#define a4 analog(3)
#define a5 analog(4)


int ref = 500;
int motorspeed;
int basespeed = 100;
int maxspeed = 100;
int rightmotor , leftmotor;

//PID
int kp = 25;
int ki = 0;
int kd = 0;
int error = 0;
int preError = 0;
int sum_error;

void setup() {
  
}
 
    
void loop() {

}

bool W(int w) {
    if(w>=ref) {
        return true;
      }
     else  {
        return false;
      }
  }

bool B(int b) {
    if(b<ref) {
        return true;
      }
     else  {
        return false;
      }
  }  

void T1 () {

    if ( W(a1) && W(a2) && W(a3) && W(a4) && B(a5) ) {
      error = 4;
      }
     else if ( W(a1) && W(a2) && W(a3) && B(a4) && B(a5) ) {
      error = 3;
      }
     else if ( W(a1) && W(a2) && W(a3) && B(a4) && W(a5) ) {
      error = 2;
      }
     else if ( W(a1) && W(a2) && B(a3) && B(a4) && W(a5) ) {
      error = 1;
      }
     else if ( W(a1) && W(a2) && B(a3) && W(a4) && W(a5) ) {
      error = 0;
      }
     else if ( W(a1) && B(a2) && B(a3) && W(a4) && W(a5) ) {
      error = -1;
      }
     else if ( W(a1) && B(a2) && W(a3) && W(a4) && W(a5) ) {
      error = -2;
      }
     else if ( B(a1) && B(a2) && W(a3) && W(a4) && W(a5) ) {
      error = -3;
      }
     else if ( B(a1) && W(a2) && W(a3) && W(a4) && W(a5) ) {
      error = -4;
      }

     //ขาว
     else if ( W(a1) && W(a2) && W(a3) && W(a4) && W(a5) ) {
      error = preError;
      }
      
    
    error = preError;
    sum_error += error;
  
    motorspeed = kp*error + kd*(error-preError) + ki*(sum_error);
    rightmotor = basespeed - motorspeed;
    leftmotor = basespeed + motorspeed;

    if(rightmotor>100) { rightmotor = maxspeed; }
    if(leftmotor>100) { leftmotor = maxspeed; }

    
    motor(1,rightmotor);
    motor(2,leftmotor);
    sleep(33);
  }
