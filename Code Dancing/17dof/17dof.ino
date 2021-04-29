#include <Servo.h>
Servo myservo; // create servo object to control a servo
    // a maximum of eight servo objects can be created
    Servo myservo2;
int pos = 0; // variable to store the servo position
void setup()
{
 myservo.attach(9); // attaches the servo on pin 9 to the servo object
 myservo2.attach(10); // attaches the servo on pin 9 to the servo object
}
void loop()
{
 for(pos = 0; pos < 180; pos += 1) // goes from 0 degrees to 180 degrees
 {         // in steps of 1 degree
 myservo.write(pos);    // tell servo to go to position in
 myservo2.write(pos);
          // variable 'pos'
 delay(10);      // waits 15ms for the servo to reach
          // the position
 }
 for(pos = 180; pos > 1 ; pos -= 1) // goes from 0 degrees to 180 degrees
 {         // in steps of 1 degree
 myservo.write(pos);    // tell servo to go to position in
 myservo2.write(pos);
          // variable 'pos'
 delay(10);      // waits 15ms for the servo to reach
          // the position
 }
// for(pos = 180; pos>=1; pos-=1)  // goes from 180 degrees to 0 degrees
// {       
// myservo2.write(pos);    // tell servo to go to position in
//          // variable 'pos'
// delay(25);      // waits 15ms for the servo to reach
//          // the position
// }
}