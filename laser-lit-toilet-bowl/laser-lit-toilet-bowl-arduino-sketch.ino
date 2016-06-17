/* 
 *-----
 * | THANKS TO THE FOLLOWING:
 * | @author: Kristian Gohlke / krigoo (_) gmail (_) com / http://krx.at
 * | @date:   3. September 2006 
 * |
 * | kr1 (cleft) 2006 
 * | released under a creative commons "Attribution-NonCommercial-ShareAlike 2.0" license
 * | http://creativecommons.org/licenses/by-nc-sa/2.0/de/
 *-----
 */

 
//Allow sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 30;        

//the time when the sensor outputs a low impulse
long unsigned int lowIn;         

//the amount of milliseconds the sensor has to be low 
//before we assume all motion has stopped
long unsigned int pause = 5000;  

boolean lockLow = true;
boolean takeLowTime;  

int pirPin = 3;    //the digital pin connected to the PIR sensor's output
int ledPin = 2;    //the digital pin connected to the laser VCC


void setup(){
  Serial.begin(9600);  //baud rate of 9600
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);

  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
  }


void loop(){

     if(digitalRead(pirPin) == HIGH){
       digitalWrite(ledPin, HIGH);               //turn on laser
       Serial.print("LASER ON for 60s.");        //print to serial on status
       delay(60000);                             //let laser stay on for 60s (or as desired)
       digitalWrite(ledPin, LOW);                //turn off laser
       Serial.print("LASER OFF indefinitely.");  //print to serial off status
      }
  }