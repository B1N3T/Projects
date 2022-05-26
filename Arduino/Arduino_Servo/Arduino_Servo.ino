// Include the Servo library 
#include <Servo.h>
 
// Declare the Servo pin 
int servoPin = 3;
 
// Create a servo object 
Servo Servo1;
int color = 1;

void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
}
void loop(){
  
   // Make servo go to 0 degrees 
   Servo1.write(140); 
   delay(1000);
   if(color == 1)
   {
      // Make servo go to 90 degrees 
      Servo1.write(38); 
      delay(1000); 
   }
}
