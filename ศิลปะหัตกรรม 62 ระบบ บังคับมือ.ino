#include <ipst.h>  // IPST-SE Board
#include <PS2X_lib.h>           

int moterF = 50, motorR = 50 ,moterC = 100;
#define PS2_DAT        30                        // ต่อขา DATA    เข้ากับขาพอร์ต 16
#define PS2_CMD        29                        // ต่อขา COMMAND เข้ากับขาพอร์ต 17
#define PS2_SEL        28                        // ต่อขา SELECT  เข้ากับขาพอร์ต 18
#define PS2_CLK        27                        // ต่อขา CLOCK   เข้ากับขาพอร์ต 19

PS2X ps2x;                                       // ประกาศตัวแปรสำหรับจอยสติ๊ก PS2

void setup()
{
  delay(1000);                                   // หน่วงเวลา 1 วินาทีเพื่อรอให้บอร์ดพร้อมทำงาน
  glcdClear();                                   // เคลียร์ภาพทั้งหมดบนหน้าจอแสดงผล
  glcdMode(1);                                   // กำหนดให้หน้าจอแสดงผลเป็นแนวนอน
  setTextSize(2);                                // กำหนดขนาดตัวหนังสือ
    
  glcd(0, 0, "Connecting");                      // แสดงข้อความเพื่อแจ้งว่า กำลังเชื่อมต่อกับจอยสติ๊ก
      
  while(true)                                    // วนการทำงานเพื่อรอการเชื่อมต่อกับจอยสติ๊ก
  {
    // กำหนดขาเชื่อมต่อกับจอยสติ๊ก โดยมีการเก็บค่าที่ส่งกลับมาเป็น Integer เพื่อรู้ได้ว่า เชื่อมต่อได้หรือไม่
    int error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
  
    if(error == 0)                               // กรณีที่เชื่อมต่อได้ Error = 0
    {
      glcd(0, 0, "Let's Enjoy!");               // แสดงข้อความว่าเชื่อมต่อกับจอยสติ๊กเรียบร้อยแล้ว
      delay(1000);                               // หน่วงเวลา 1 วินาที
      glcdClear();                               // เคลียร์ภาพทั้งหมดบนหน้าจอแสดงผล
      break;                                     // ออกจาก while(true)
    } 
    delay(500);                                  // หน่วงเวลา 500 มิลลิวินาทีเพื่อรอการเชื่อมต่อครั้งต่อไปในกรณีที่เชื่อมต่อไม่สำเร็จ
  }
}

void loop()
{
  ps2x.read_gamepad(false, false);               // อ่านข้อมูลจากจอยสติ๊ก
  
  if(ps2x.Button(PSB_CIRCLE)){                     // ถ้าปุ่มวงกลมถูกกด
    ao();                    }  // แสดงข้อความว่า Circle บนหน้าจอ
  else if(ps2x.Button(PSB_CROSS)){                // ถ้าปุ่มกากบาทถูกกด
    servo(1,50);   }
  else if(ps2x.Button(PSB_SQUARE)) {              // ถ้าปุ่มสี่เหลี่ยมถูกกด
    servo(1,35);         }             // แสดงข้อความว่า Square บนหน้าจอ
  else if(ps2x.Button(PSB_TRIANGLE)) {            // ถ้าปุ่มสามเหลี่ยมถูกกด
    servo(1,120);           }           // แสดงข้อความว่า Triangle บนหน้าจอ
  else if(ps2x.Button(PSB_L1))         {          // ถ้าปุ่ม L1 ถูกกด
    servo(1,120);
    delay(100);}// แสดงข้อความว่า L1 บนหน้าจอ
  else if(ps2x.Button(PSB_L2)){                   // ถ้าปุ่ม L2 ถูกกด
    servo(1,70);
    delay(100);}
  else if(ps2x.Button(PSB_L3)){                   // ถ้าปุ่ม L3 ถูกกด
    glcd(1, 1, "L3      ");    }                  // แสดงข้อความว่า L3 บนหน้าจอ
  else if(ps2x.Button(PSB_R1))  {                 // ถ้าปุ่ม R1 ถูกกด
    servo(2,165); 
    delay(100);}                // แสดงข้อความว่า R1 บนหน้าจอ
  else if(ps2x.Button(PSB_R2))    {               // ถ้าปุ่ม R2 ถูกกด
    servo(2,105);
    delay(100);}              // แสดงข้อความว่า R2 บนหน้าจอ
  else if(ps2x.Button(PSB_R3))     {              // ถ้าปุ่ม R3 ถูกกด
    glcd(1, 1, "R3      ");         }             // แสดงข้อความว่า R3 บนหน้าจอ
  else if(ps2x.Button(PSB_START))    {            // ถ้าปุ่ม Start ถูกกด
    glcd(1, 1, "Start   ");           }           // แสดงข้อความว่า Start บนหน้าจอ
  else if(ps2x.Button(PSB_SELECT))     {          // ถ้าปุ่ม Select ถูกกด
    glcd(1, 1, "Select  ");             }         // แสดงข้อความว่า Select บนหน้าจอ
  else if(ps2x.Button(PSB_PAD_UP))               // ถ้าปุ่ม Up ถูกกด
    sr(moterC);                     // แสดงข้อความว่า Up บนหน้าจอ
  else if(ps2x.Button(PSB_PAD_DOWN))             // ถ้าปุ่ม Down ถูกกด
    sl(moterC);                     // แสดงข้อความว่า Down บนหน้าจอ
  else if(ps2x.Button(PSB_PAD_LEFT))             // ถ้าปุ่ม Left ถูกกด
    fd(moterC);                    // แสดงข้อความว่า Left บนหน้าจอ
  else if(ps2x.Button(PSB_PAD_RIGHT))            // ถ้าปุ่ม Right ถูกกด
    bk(moterC);                      // แสดงข้อความว่า Right บนหน้าจอ
  else                                           // ถ้าไม่มีปุ่มใดๆถูกกด
    ao();

   delay(50);                                     // หน่วงเวลา 50 มิลลิวินาที
}
