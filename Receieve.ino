const int DR = 2;
const int DA = 3;
int data;

void setup() {
  // put your setup code here, to run once:
  DDRA = B00000000;
  pinMode(DR, INPUT_PULLUP);
  pinMode(DA, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (digitalRead(DR)==HIGH){}    // wait for DR to be pulled down
  data = PINA;                              // input data from PORTA
  Serial.println(data);                     // send data to the serial monitor
  digitalWrite(DA, LOW);          // pull down DA
  while (digitalRead(DR)==LOW){}     // wait for DR to be released
  digitalWrite(DA, HIGH);         // release DA
}
