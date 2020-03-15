#include <ipst.h>  // 
char control;
void setup() {
  OK(); 
  servo(2,125);
  servo(1,19);
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() {
    //check();

  control=Serial1.read();
  if (control=='B') {
     fd(100);
    }
 else if (control=='C') {
    tl(100);
    }
 else if(control=='D') {
    tr(100);
    }
 else if(control=='E') {
    bk(100);
    }
 else if (control=='A') {
  servo(1,72);
  delay(500);
  servo(2,79);
  delay(500);
  servo(1,19);
  delay(500);
  servo(2,125);
      Serial1.end();
  Serial1.begin(9600);
  }
  else if (control=='G') {
    servo(2,79);
    delay(500);
    servo(1,72);
    delay(500);
    servo(2,125);
    delay(500);
    servo(1,19);
    Serial1.end();
    Serial1.begin(9600);
    }
    
      
      
 
 else { 
      ao();
      
      
      
      }
Serial.print(control);
}

void check () {
  int a; // 2สุง 125 ต่ำ 79  1คีบ 19 อ้า 72
  a=knob(300);
  servo(1,a);
  glcd(1,1,"knob =    %d  ",a);
  }
