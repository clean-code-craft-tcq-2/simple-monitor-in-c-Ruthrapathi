#include "batteryStateCheck.h"

int main() 
{
   float limitArray[] =   {0,45,20,80,0,0.8}; // Lower and Upper  Boundaries for all the 3 parametes  
	
   assert(batteryIsOk(20,40,0.5,limitArray));  // All status OK

   assert(!batteryIsOk(-1,45,0.6,limitArray));   // Low Error
   assert(!batteryIsOk(25,10,0.5,limitArray)); 
   assert(!batteryIsOk(25,65,-1,limitArray)); 
     
   assert(!batteryIsOk(50,45,0.6,limitArray)); //High Error
   assert(!batteryIsOk(25,85,0.5,limitArray)); 
   assert(!batteryIsOk(25,60,1,limitArray));
    
   assert(!batteryIsOk(1,45,0.6,limitArray)); //Low warning
   assert(!batteryIsOk(25,21,0.5,limitArray)); 
   assert(!batteryIsOk(25,60,0.01,limitArray));
    
   assert(!batteryIsOk(44,45,0.6,limitArray)); //High Warning
   assert(!batteryIsOk(25,77,0.5,limitArray)); 
   assert(!batteryIsOk(25,60,0.77,limitArray));		
}
