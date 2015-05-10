/**************************************************
Written Saturday, March 28, 2014 by Michael Jonas

Project was completed with Colin Cooke and Ingrid Roorda
at Hack Western over one weekend. I was responsible for
electronics prototyping and Arduino code.

This program allows the Arduino Uno to act as a switch 
to a home applicance fan. The Arduino is connected to
a relay module and fed data via COM port. The data
being sent is processed on a PC in Processing and origin
of the data is the Muse headband. Thus, one can turn the fan
on and off by concentrating and thinking about turning
the fan on. 
***********************************************/



//digital pin to transistor's gate on relay module
const int controlPin = 8;
int notConc = 67;
int conc = 66;

void setup(){
  
  //set controlPin to be an OUTPUT pin
  pinMode(controlPin, OUTPUT);
  
  //keeps the relay closed
  digitalWrite(controlPin, LOW);
}

void loop(){
  while(Serial.available() > 0){
    
    if(Serial.read() == nonConc){
      
      //if message received is not concentrated, voltage applied to gate is low
      digitalWrite(controlPin, LOW);
    }
    
    //if message received is concentrated, voltage applied to gate is high thus closing the switch and allowing fan to turn on
    else if(Serial.read() == conc){
      digitalWrite(controlPin, HIGH);
    }
  }
}
  
  
