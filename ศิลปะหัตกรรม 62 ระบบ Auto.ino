#include <ipst.h>
#include <gp2d120.h>

#define L analog(26)
#define R analog(27)

void setup(){
  servo(0,110);
  servo(1,50);
  servo(2,95);
  OK(); 
  
   if (dis >= 5) {
      beep(17);
      delay(1000);
      beep(17);
      delay(1000);
      beep(17);
      delay(1000);   //เตือน 3 วิ
      
      servo(2,48);
      delay(1000);
      bk(50);
      delay(100); // คีบแล้วถอยหลัง
      
      RRR();
      FFF();
      Fgreen();
      FFF();
      RRR();
      RRR();
      FFF();
      LLL180();  //ภารกิจ
      
      bk(50);
      delay(1000);
      servo(1,128);
      delay(500);
      servo(0,23);
      delay(2000);
      servo(2,95);
      delay(500);  //วางประป๋อง
    } 
  
}
  
  
void loop() { }

void stop1() {
      while(1){
        if (L<405&&R<410){
            ao(); 
            break;
        }
        else if(L>405&&R>410){fd(40);}
        else if(L<405&&R>410){tl(40);}
        else if(L>405&&R<410){tr(40);}
    }  
  }

void FFF(){
    while(1){
        if (L<405&&R<410){
            fd(70);delay(100);
            break;
        }
        else if(L>405&&R>410){fd(30);}
        else if(L<405&&R>410){tl(30);}
        else if(L>405&&R<410){tr(30);}
    }
}

 
void RRR(){
    while(1){
        if (L<405&&R<410){
            fd(30);delay(100);
            while(analog(27)>405){tr(30);}
            while(analog(27)<405){tr(30);}
            while(analog(27)>405){tr(30);}
            break;
        }
        else if(L>405&&R>410){fd(30);}
        else if(L<405&&R>410){tl(30);}
        else if(L>405&&R<410){tr(30);}
    }
}

void LLL(){
    while(1){
        if (L<405&&R<410){
            fd(40);delay(100);
            while(analog(25)>410){tl(30);}
            while(analog(25)<410){tl(30);}
            while(analog(25)>410){tr(30);}
            break;
        }
        else if(L>405&&R>410){fd(30);}
        else if(L<405&&R>410){tl(30);}
        else if(L>405&&R<410){tr(30);}
    }
}

void L180(){
    while(1){
        if (L<405&&R<410){
            fd(40);delay(100);
            while(L>405){tl(40);}
            while(L<405){tl(40);}
            while(L>405){tl(40);}
            while(L<405){tl(40);}
            break;
        }
        else if(L>405&&R>410){fd(40);}
        else if(L<405&&R>410){tl(40);}
        else if(L>405&&R<410){tr(40);}
    }
}

void Fgreen() {
      while(1){
        if (L<405&&R<410){
            fd2(20,20);
            break;
        }
        else {
          fd2(20,20);
        }
    }  
  }
