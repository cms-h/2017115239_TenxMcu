#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
   F_clearWDT(); //清除看门狗
   //时钟初始化
   CLKCON = 0x03; // Clock div 1
   STPPCK = 0;
   STPFCK = 0;
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   SELFCK = 1;
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   // IO 模式初始化
   P1MODL = 0xa8; //输入
   P1_0 = 0;
   // IO 状态初始化
   F_ledOn();

 	 TH2 = (65536 - 3686) / 256;  //定时3.686ms,高八位
   RCP2H = TH2;  //捕捉高字节
   TL2 = (65536 - 3686) % 256; //定时3.686ms,低八位
   RCP2L = TL2;  //捕捉低字节

   TR2 = 1;
   ET2 = 1;
 	 EA = 1;
 } 
 //=============================================================================
 void VarsInit() {} 