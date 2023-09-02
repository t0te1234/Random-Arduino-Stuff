const int DIP1 = 7;
const int DIP2 = 6;
const int BUTTON = 5;
 
const int LED1 =  1;
const int LED2 =  2;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(DIP1, INPUT);
  pinMode(DIP2, INPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  static short int value;
  if (digitalRead(BUTTON) == 0){
    if((digitalRead(DIP1) == 1) && (digitalRead(DIP2) == 1)){
       value = !value;
    } 
  }
  
  digitalWrite(LED1, value);
  digitalWrite(LED2, !value);
  delay(300);
}
