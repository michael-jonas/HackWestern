/**********************************************************
Written Saturday, March 28, 2014 by Michael Jonas

Project was completed with Colin Cooke and Ingrid Roorda
at Hack Western over one weekend. I was responsible for
electronics prototyping and Arduino code. The project
was to control a fan with a Muse headbang and Myo armband.

This program allows the Arduino Uno to control the 
rotation/oscillation of a home appliance fan. The
Arduino is connected to two servos mounted to the side
of the fan. The data being sent is processed on a PC 
in Processing and the origin of the data is the 
Myo armband. Thus, one can rotate the fan by
initiating different gestures with the Myo
***********************************************************/



#include <Servo.h>


int servoOnePin = 2; //digital pin connected to servoOne control terminal
int servoTwoPin = 4; //digital pin connected to servoTwo control terminal

//declare servo objects
Servo servoOne;
Servo servoTwo;

//set default angle of servos
float baseTurnOne = 90;
float baseTurnTwo = 90;

//turn increment/decrement for servo
float n = 0.1;

//integers corresponding to the messages sent from the computer
int waveOut = 51;
int waveIn = 50;
int fist = 52;

void setup() {
 servoOne.attach(servoOnePin); //servo control attached to pin servoOnePin (2)
 servoTwo.attach(servoTwoPin); //servo control attached to pin servoTwoPin (4)
 servoOne.write(baseTurnO); //set servo to midpoint
 servoTwo.write(90); //set servo to midpoint


}

void loop() {
 
 while(Serial.available() > 0){
 //resets the servos to center position
 if(Serial.read()== fist){ //fist
   servoOne.write(90); //set servo to midpoint
   servoTwo.write(90); //set servo to midpoint
 }
 
 if(Serial.read()== waveIn){ 
     //will execute the code while the data coming is still waveIn and while the servos have not reached their maximum/minimum positions (0 and 180)
     do{
       
     //sets baseTurn variables to the most recent position that the servo was at
     baseTurnOne = servoOne.read();  
     baseTurnTwo = servoTwo.read();
     
     //rotates servos to turn fan, incrementing/decrementing the position 
     servoOne.write(baseTurnOne - n);
     servoTwo.write(baseTurnTwo + n); 
 
     }while(Serial.read()== waveIn && (baseTurnOne - n) > 0 && (baseTurnTwo + n) < 180 );
   }
   
   else if(Serial.read() == waveOut){ 
     //will execute the code while the data coming is still waveIn and while the servos have not reached their maximum/minimum positions (0 and 180)
     do{
       
     //sets baseTurn variables to the most recent position that the servo was at
     baseTurnOne = servoOne.read();  
     baseTurnTwo = servoTwo.read();
     
     //rotates servos to turn fan, incrementing/decrementing the position
     servoOne.write(baseTurnOne + n); 
     servoTwo.write(baseTurnTwo - n); 
     
     }while((Serial.read() == waveOut) && ((baseTurnOne + n) > 0) && ((baseTurnTwo - n) < 180) );
    }
  }
}







//need to convert time of gesture to 
