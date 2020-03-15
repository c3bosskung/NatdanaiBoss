  #include <ipst.h>
#include "ipst_gp2d120_lib.h"
int L,R,P=500;
void setup () {
 OK();
 servo(1,137);
 servo(2,100);
 fd(50);
 FFFb();
 RRR();
 box();
 LLL();
 unbox();
 ao();

 
 
 
 
 
 }                                          
void loop() {
//checkled();
//check_knob();
     
}
void FFFb(){
        while(1){
                L=analog(3); R=analog(6);
                if (L<P&&R<P){ //ดำคู่
                  ao(); delay(500);
                       fd(80);
                       while(analog(3)>P){fd(85);}
                       while(analog(6)<P){fd(85);}
                        break;
                }
                else if(L>P&&R>P){fd(85);}
                else if(L<P&&R>P){sl(40);}
                else if(L>P&&R<P){sr(40);}
        }
}

void FFFw(){
        while(1){
                L=analog(3); R=analog(6);
                if (L>P&&R>P){ //ขาวคู่
                  delay(500);

                       while(analog(3)>P){fd(85);}
                       while(analog(6)<P){fd(85);}
                        break;
                }
                else if(L>P&&R>P){fd(85);}
                else if(L<P&&R>P){sl(40);}
                else if(L>P&&R<P){sr(40);}
        }
}
void LLL(){
        while(1){
                L=analog(3); R=analog(6);
                if (L<P&&R<P){
                      ao(); delay(250); fd(50); delay(300);
                        while(analog(3)<P){sl(50);}
                        while(analog(3)>P){sl(50);}
                        
                        break;
                }
                else if(L>P&&R>P){fd(85);}
                else if(L<P&&R>P){sl(40);}
                else if(L>P&&R<P){sr(40);}
        }
}



void RRR() {
        while(1){
                L=analog(3); R=analog(6); 
                if (L<P&&R<P){
                       ao(); delay(250); fd(50); delay(300);
                        while(analog(6)>P){sr(50);}    
                        while(analog(6)<P){sr(50);}                        
                        break;
                }
                else if(L>P&&R>P){fd(85);}
                else if(L<P&&R>P){sl(40);}
                else if(L>P&&R<P){sr(40);}
        }
}

void box () {
   int dis;
   while(1){ L=analog(3); R=analog(6); 
   dis=getdist(0); 
   if (dis<=5) {
             
                        ao();
                        delay(500);
                        servo(1,95);
                        delay(500);
                        servo(2,166);
                        delay(500);
                        servo(1,150);
                        delay(500);
                        servo(2,88);
                        ao();          
                        delay(500);
                        fd(50);
                        while(analog(3)>P||analog(6)>P);   
                        ao();       
                        delay(500);
                        bk(50);
                        delay(90);
                        ao();  
                        while(analog(6)<P){sr(50);}
                        while(analog(6)>P){sr(50);}
                        break;
                
                }
                else if(L>P&&R>P){fd(85);}
                else if(L<P&&R>P){sl(40);}
                else if(L>P&&R<P){sr(40);}
        }
   }
 void unbox() {
    while(1){ L=analog(3); R=analog(6); 
   if (L<P&&R<P){
                        ao();
                        fd(50);
                        delay(250);
                        ao();
                        delay(500);
                        servo(2,166);
                        delay(500);
                        servo(1,95);
                        delay(500);
                        servo(2,88);
                        delay(500);
                        servo(1,150);
                        delay(500); 
                        ao();       
                        delay(500);
                        bk(50);
                        delay(150);
                        ao();
                        while(analog(6)<P){sr(50);}
                        while(analog(6)>P){sr(50);}
                   
                           while(analog(6)<P){sr(50);}
                        while(analog(6)>P){sr(50);}
                   

                        break;
                
                }
                else if(L>P&&R>P){fd(85);}
                else if(L<P&&R>P){sl(40);}
                else if(L>P&&R<P){sr(40);}
        }
   
 }

void FH () {
        while(1){
                L=analog(3); R=analog(6); 
                if (L<P&&R<P){
                        while(analog(6)<P){sr(50);}
                        while(analog(6)>P){sr(50);}
                        ao();
                        break;
                }
                       

}
}
 
 
void checkled(){
  
while(1){
  
glcd(1,1,"LED_l =  %d     ",analog(3));
glcd(2,1,"LED_r =  %d     ",analog(6));
glcd(3,1,"dis =    %d     ",getdist(0));
}

}

void check_knob() {
  int x; // 1 อ้าสุด 95 คีบ 150 2 สูง 88 ต่ำ 166
  
  x=knob(190); 
  servo(1,x);
  glcd(1,0,"  %d  ",x);
 
}

  



