/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 28 May 2015
 by Michael C. Miller
 modified 8 Nov 2013
 by Scott Fitzgerald

 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo rightEar;
Servo leftEar;
Servo nose;

void setup() 
{ 
  rightEar.attach(D5);
  leftEar.attach(D6);
  nose.attach(D7);
  Serial.begin(115200);
} 

void noseAction()
{
  nose.write(20);
  delay(250);
  nose.write(90);
  delay(250);
}

void moveLeftEar()
{
  leftEar.write(90);
  delay(1000);
  leftEar.write(140);
  delay(2000);
  leftEar.write(40);
  delay(4000);
  leftEar.write(90);
  delay(2000);
}

void moveLeftEarAndNose()
{
  leftEar.write(90);
  delay(1000);
  leftEar.write(140);
  delay(2000);
  noseAction();
  noseAction();
  leftEar.write(40);
  delay(4000);
  leftEar.write(90);
  delay(2000);
  noseAction();
  noseAction();
}

void moveRightEar()
{
  rightEar.write(90);
  delay(1000);
  rightEar.write(60);
  delay(3000);
  rightEar.write(90);
  delay(1000);
}

void moveBothEars()
{
  rightEar.write(90);
  leftEar.write(90);
  delay(1000);
  rightEar.write(50);
  leftEar.write(130);
  delay(3000);
  rightEar.write(110);
  leftEar.write(50);
  delay(3000);
  rightEar.write(90);
  leftEar.write(90);
  delay(1000);
}

void doNothing() 
{
  delay(5000);
}

void (*myfunctions[])() = {moveRightEar,moveLeftEar,noseAction,doNothing,moveBothEars,moveLeftEarAndNose,noseAction};

void loop() 
{ 

  int i = random(0, 7);
  Serial.println(i);
  myfunctions[i]();
  
  /*moveRightEar();
  moveLeftEar();
  noseAction();
  noseAction();
  doNothing();
  moveBothEars();*/
} 

/*void sweep()
{
  int pos;

  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}*/
