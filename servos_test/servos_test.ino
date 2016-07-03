#include <Servo.h> 
 
Servo servo_lr;
Servo servo_rr;
Servo servo_lf;
Servo servo_rf;

 
int pos = 0;    // variable to store the servo position 
int pos_min = 20, pos_max = 160; 

int del = 30;
int dt = 1;

void setup() 
{ 
  
  servo_lr.attach(3);  // attaches the servo on pin 9 to the servo object 
  servo_rr.attach(4);  // attaches the servo on pin 9 to the servo object 
  servo_lf.attach(5);  // attaches the servo on pin 9 to the servo object 
  servo_rf.attach(6);  // attaches the servo on pin 9 to the servo object 

} 

void loop1() {
  servo_lr.write(pos_max);
  servo_rr.write(pos_max);
  servo_lf.write(pos_min);
  servo_rf.write(pos_min);
  
  delay(1000);
    
  servo_lr.write(pos_min);
  servo_rr.write(pos_min);
  servo_lf.write(pos_max);
  servo_rf.write(pos_max);

  delay(1000);
  
}

void loop() 
{ 
  for(pos = pos_min; pos < pos_max; pos += dt)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo_lr.write(pos);
    servo_rr.write(pos);
    servo_lf.write(180-pos);
    servo_rf.write(180-pos);
    delay(del);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = pos_max; pos>=pos_min+1; pos-=dt)     // goes from 180 degrees to 0 degrees 
  {                                
    servo_lr.write(pos);
    servo_rr.write(pos);
    servo_lf.write(180-pos);
    servo_rf.write(180-pos);
    delay(del);                       // waits 15ms for the servo to reach the position 
  } 
} 
