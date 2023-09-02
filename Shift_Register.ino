/*
 * Shift Register
 * Description
 * Version: Mar 22 2023
 * Adaptation: Bobby Yan
 * A shift register program that flickers 8 LEDs in a certain pattern
 */

//Declare variables
const int LATCH_PIN = 5;
const int CLOCK_PIN = 6 ;
const int DATA_PIN = 4;
int pinNum = 0;
int orientation = -1;

//Set all the pins of the chip to OUTPUT
void setup() {
  Serial.begin(9600);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT); 
  pinMode(CLOCK_PIN, OUTPUT);
}

//Start of program
void loop(){

  //If the pin number reaches either end of the LEDs
  if(pinNum == 0||pinNum == 7){
    //Flip the orientation
    orientation = orientation * -1;
  }

  //Increment pinNum by the current orientation
  pinNum = pinNum + orientation;


  //Light the selected LED
  lightLED(pinNum);
  delay(100);
}

//A fuction that a pin number and lights that pin
void lightLED(int x){

  //Runs through each value through 0-7
  for (int i = 0; i < 8; i++){
    digitalWrite(DATA_PIN, LOW);

    //If the value matches the pin number
    if (i == x){
      //Write HIGH to the next LED
      digitalWrite(DATA_PIN, HIGH);
    }

    //Move the queue
    digitalWrite(CLOCK_PIN, HIGH);
    digitalWrite(CLOCK_PIN, LOW);
  }

  //Updates the LEDs
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);
}
