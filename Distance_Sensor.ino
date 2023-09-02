#include <Servo.h>
Servo myservo1;
Servo myservo2;

int pir = 3;
int pirValue;
int LED = 2;

void setup()
{
  Serial.begin (9600);
  myservo1.attach (9);
  myservo1.write (90);
  myservo2.attach (10);
  myservo2.write (9);
  pinMode(LED, OUTPUT);
}

void loop()
{
  pirValue = digitalRead(pir);
  Serial.println (pirValue);
  
  if (pirValue == HIGH){
    digitalWrite(LED, HIGH);
    myservo1.write(0);
    myservo2.write(180);
  }
  else {
    digitalWrite(LED, LOW);
    myservo1.write(180);
    myservo2.write(0);
  }
  
}
