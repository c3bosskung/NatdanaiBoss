#include <gp2d120.h>
#include<ATX2.h>
byte CtWX;
int CWX,x=0;
int A_H_L , A_H_R , LeftW , LeftB , RightW , RightB;
int motorFD , motorSL , motorSR , motorBK , motorLB; 
int delayLB , delayAO , delayBK , plusL , plusR; 
int motorLBL , motorLBR;
#define AL analog(5) //L
#define AR analog(6) //R
void setup ()
{
 OK();
 glcdClear();
 glcd(1,0,"Manual");
 servo(1,9);
 servo(2,53);
 setup_analog_program();
 setup_drive();
 glcdClear();
 Serial1.begin(9600);
}
void loop () 
{
  //check_WX(); 
    control_WX();
  //check_analog();
}

void check_WX(){
  while(1){
  while(Serial1.available()>0)
  glcd(2,0,"HEX = 0x%h    ",CWX);
  }
}

void control_WX(){
  while(Serial1.available()>0)
  CtWX=Serial1.read();
  if(CtWX==0x10)
  {
  BK(60); // ÀÍÂËÅÑ§
  }
  else if(CtWX==0x20){
  SR(60); //àÅÕéÂÇ¢ÇÒ
  }
  else if(CtWX==0x40){
  SL(60); //àÅÕéÂÇ«éÒÂ
  }
  else if(CtWX==0x80){
  FD(60); //à´Ô¹Ë¹éÒ
  }
  else if(CtWX==0x01){
  servo(1,75);
  }
  else if(CtWX==0x08){
  servo(1,9);
  }
  else if(CtWX==0x04) {
  servo(2,0);
  }
  else if (CtWX==0x02) {
  servo(2,51);
  }
  else if (CtWX==0xff){
    select_mode_auto();
    x++;
  }
  else{
  AO();
  }
}

void check_knob(){
    servo(2,knob(200));
    glcd(2,1,"servo = %d    ",knob(200));
}

void check_analog() {

  glcd(1,1,"AL = %d   ",AL);
//  glcd(2,1,"AL2 = %d    ",AL2);
  glcd(3,1,"AR = %d   ",AR);
 // glcd(4,1,"AR2 = %d    ",AR2);
  
  }
    
void setup_analog_program() {
      //«éÒÂ
      LeftW = 227; // áÊ§¢ÒÇ«éÒÂ
      LeftB = 710;  //áÊ§à¢ÕÂÇ«éÒÂ
      //¢ÇÒ 
      RightW = 204;  //áÊ§¢ÒÇ¢ÇÒ
      RightB = 562;  //áÊ§à¢ÕÂÇ¢ÇÒ
      //àÊÃÔÁ¤èÒ
      plusL = 0;
      plusR = 0;
        //ÃÇÁ¤èÒ
        A_H_L = ((LeftW + LeftB + plusL)/2);
        A_H_R = ((RightW + RightB + plusR)/2);
          //áÊ´§¤èÒ
          glcd(1,1,"Left =  %d  ",A_H_L);
          glcd(2,1,"Right = %d  ",A_H_R); 

}

void select_mode_auto(){
       glcdClear();
       glcd(1,0,"Auto Mode");
       if (x=1) {
         FD(60);
         delay(2000);
         AO();
         BK(60);
         delay(2000);
         
        }

        if (CtWX==0xff);  {
          glcdClear();
          control_WX();
          }
      }
   

void setup_drive(){
  
  //Ë¹éÒ
  motorFD = 100;
  //«éÒÂ
  motorSL =  100;
  //¢ÇÒ
  motorSR = 100;
     //WHILE
     //Ë¹éÒ
     motorLBL = 80;
     //¢ÇÒ
     motorLBR = 80;
      
     motorLB = 100;
     delayLB = 150;
     
     delayAO = 150;

     motorBK = 100;
     delayBK = 150;
  }

 void drive_linear(){

    //àÊé¹µÃ§
    if(AL >= A_H_L && AR >= A_H_R){FD(motorFD);}
      //«éÒÂ
      else if(AL <= A_H_L && AR >= A_H_R){SL(motorSL);}
        //¢ÇÒ
        else if(AL >= A_H_L && AR <= A_H_R){SR(motorSR);}
          //ËÅÑ§
          else if(AL <= A_H_L && AR <= A_H_R){BK(motorBK);}
          
  }

void LBF() { //¢éÒ§Ë¹éÒ
  while(1){
    if(AL >= A_H_L && AR >= A_H_R){
      AO();        delay(delayAO);
      FD(motorLB); delay(delayLB);
       break;
     
    }
    //àÊé¹µÃ§
    else if(AL <= A_H_L && AR <= A_H_R){FD(motorFD);}
    //«éÒÂ
    else if(AL >= A_H_L && AR <= A_H_R){SL(motorSL);}
    //¢ÇÒ
    else if(AL <= A_H_L && AR >= A_H_R){SR(motorSR);}
    
  }
}

void LBR(){ //¢ÇÒ
  while(1){
    if(AL >= A_H_L && AR >= A_H_R){
      AO();        delay(delayAO);
      FD(motorLB); delay(delayLB);
        while(AR > A_H_R){SR(motorLBR);}
        while(AR < A_H_R){SR(motorLBR);}
       break;
     
    }
    //àÊé¹µÃ§
    else if(AL <= A_H_L && AR <= A_H_R){FD(motorFD);}
    //«éÒÂ
    else if(AL >= A_H_L && AR <= A_H_R){SL(motorSL);}
    //¢ÇÒ
    else if(AL <= A_H_L && AR >= A_H_R){SR(motorSR);}
    
  }
}

void LBL(){ //«éÒÂ
  while(1){
    if(AL >= A_H_L && AR >= A_H_R){
      AO();        delay(delayAO);
      FD(motorLB); delay(delayLB);
        while(AL > A_H_L){SL(motorLBL);}
        while(AL < A_H_L){SL(motorLBL);}
       break;
     
    }
    //àÊé¹µÃ§
    else if(AL <= A_H_L && AR <= A_H_R){FD(motorFD);}
    //«éÒÂ
    else if(AL >= A_H_L && AR <= A_H_R){SL(motorSL);}
    //¢ÇÒ
    else if(AL <= A_H_L && AR >= A_H_R){SR(motorSR);}
    
  }
}

void LBR180(){ // ¡ÅÑºËÅÑ§ËÑ¹
  while(1){
    if(AL >= A_H_L && AR >= A_H_R){
      AO();        delay(delayAO);
      FD(motorLB); delay(delayLB);
        while(AR > A_H_R){SR(motorLBR);}
        while(AR < A_H_R){SR(motorLBR);}
        while(AR > A_H_R){SR(motorLBR);}
        while(AR < A_H_R){SR(motorLBR);}
        BK(motorBK); delay(delayBK);
       break;
     
    }
    //àÊé¹µÃ§
    else if(AL <= A_H_L && AR <= A_H_R){FD(motorFD);}
    //«éÒÂ
    else if(AL >= A_H_L && AR <= A_H_R){SL(motorSL);}
    //¢ÇÒ
    else if(AL <= A_H_L && AR >= A_H_R){SR(motorSR);}
    
  }
}




