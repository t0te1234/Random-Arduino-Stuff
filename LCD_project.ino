/*
 * LCD Project
 * Version: June 13 2023
 * Author: Bobby Yan
 * Description
 * A LCD display that displays and shifts the letters B, O, Y.
 * Can cycle through the name BOBBY
 */

//Define buttons
#define UP 8
#define DOWN 10
#define LEFT 11
#define RIGHT 9
#define SELECT 12

//Arrays for the rows and each of the characters 
int rows[] = {1, 2 ,4 ,8, 16, 32, 64, 128};
int letterB[] = {131, 187, 187, 135, 135, 187, 187, 131};
int letterO[] = {195, 189, 126 , 126 , 126 , 126 , 189, 195};
int letterY[] = {231, 231, 231, 231, 231, 219, 189, 126};
int nameBobby[] = {131, 187, 187, 135, 135, 187, 187, 131, 195, 189, 126, 126 , 126 , 126 , 189, 195, 131, 187, 187, 135, 135, 187, 187, 131, 131, 187, 187, 135, 135, 187, 187, 131, 231, 231, 231, 231, 231, 219, 189, 126};

//Variables to count the iterations through the program
int count = 0;
//Used as a "timer" to stop the letters when scrolling
int letterDelay = 0;

//Setup the program
void setup(){
  DDRF = B11111111; //col
  DDRK = B11111111; //row

  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(SELECT, INPUT_PULLUP);
  
  Serial.begin(9600);
}

//Main loop
void loop(){

  //If the LCD is currently displaying a whole letter (count % 8 = 0) 
  //Start counting the letterDelay to 20
  //Now the count varible will not change for the next 20 iterations of the program (The LCD keeps the current image)
  if (count % 8 == 0 && letterDelay != 20){
    letterDelay++;

  //Else count++ and reset count to 0 if it hits 40
  //Resetting count stops it from counting to too high a number
  } else {
    letterDelay = 0;
    if (count == 40){
      count = 0;
    }
    count++;
  }

  //If the up button is pressed
  if (!digitalRead(UP)){
    //Draw and scroll B
    drawB();
    
  //If the down button is pressed
  } else if (!digitalRead(DOWN)){
    //Draw and scroll O
    drawO();
    
  //If the right button is pressed
  } else if (!digitalRead(RIGHT)){
    //Draw and scroll Y
    drawY();
    
  //If the left button is pressed
  } else if (!digitalRead(LEFT)){
    //Draw and scroll BOBBY
    drawName();
    
  //If the select button is pressed
  } else if (!digitalRead(SELECT)){
    //Clear the screen
    PORTK = B11111111;
    PORTF = B11111111;
    
  //If nothing is pressed
  } else {
    //Fill the screen
    PORTK = B11111111;
    PORTF = B00000000;
  }
}

//A function to draw and scroll the letter B on the LCD
void drawB(){
  //Iterate through the row array row by row
  for (int i = 0; i < 8; i++){
    //To prevent bleeding in the LCD
    PORTK = B00000000;
    PORTF = B11111111;
    //Edit a row
    PORTK = rows[i];
    //Draw on the row one value in the chosen letter's array
    PORTF = letterB[(i + count) % 8];
    delay(2);
  }
  
}

//A function to draw and scroll the letter O on the LCD
void drawO(){
  for (int i = 0; i < 8; i++){
    PORTK = B00000000;
    PORTF = B11111111;
    PORTK = rows[i];
    PORTF = letterO[(i + count) % 8];
    delay(2);
   }
}

//A function to draw and scroll the letter Y on the LCD
void drawY(){
  for (int i = 0; i < 8; i++){
    PORTK = B00000000;
    PORTF = B11111111;
    PORTK = rows[i];
    PORTF = letterY[(i + count) % 8];
    delay(2);
  }
}

//A function to draw and scroll the name Bobby on the LCD
void drawName(){
  for (int i = 0; i < 8; i++){
    PORTK = B00000000;
    PORTF = B11111111;
    PORTK = rows[i];
    PORTF = nameBobby[(i + count) % 40];
    delay(2);
  }
}
