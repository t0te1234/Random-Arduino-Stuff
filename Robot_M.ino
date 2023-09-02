#include <Servo.h>
Servo servoRight;
Servo servoLeft;

void setup()
{
  servoLeft.attach(13);
  servoRight.attach(12);

}

void loop()
{
  for (int i = 1; i <= 95; i++) {
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(20);

  }


  for (int i = 1; i < 50; i++) {
    servoLeft.writeMicroseconds(1600);
    servoRight.writeMicroseconds(1600);
    delay(20);
  }


  for (int i = 1; i <= 135; i++) {
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(20);
  }

  for (int i = 1; i <= 37; i++) {
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1300);
    delay(20);
  }


  for (int i = 1; i <= 126; i++) {
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(20);
  }

  for (int i = 1; i <= 50; i++) {
    servoLeft.writeMicroseconds(1600);
    servoRight.writeMicroseconds(1600);
    delay(20);
  }

  for (int i = 1; i <= 97; i++) {
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(20);
  }


  //Go backwards
  
  for (int i = 1; i <= 195; i++) {
    servoLeft.writeMicroseconds(1600);
    servoRight.writeMicroseconds(1600);
    delay(20);
  }


  for (int i = 1; i <= 100; i++) {
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(20);
  }

  for (int i = 1; i < 50; i++) {
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1300);
    delay(20);
  }


  for (int i = 1; i <= 130; i++) {
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(20);
  }
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(20);
  for (int i = 1; i <= 35; i++) {
    servoLeft.writeMicroseconds(1600);
    servoRight.writeMicroseconds(1600);
    delay(20);
  }
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(20);

  for (int i = 1; i <= 123; i++) {
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(20);
  }
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(20);
  for (int i = 1; i <= 45; i++) {
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1300);
    delay(20);
  }
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(20);
  for (int i = 1; i <= 97; i++) {
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(20);
  }
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(20);


  servoLeft.detach();
  servoRight.detach();
}
