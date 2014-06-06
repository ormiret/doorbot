const int lockPin = 2;
const int ledPin = 19;
const long timeOut = 10000;


char command;
int lockState = LOW;
unsigned long opened;

void setup() {
  pinMode(lockPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(lockPin, lockState);
  digitalWrite(ledPin, lockState);
  Serial.begin(9600);
}


void loop() {
  if(Serial.available() > 0) {
    if(Serial.read() == 'u') {
      lockState = HIGH;
      digitalWrite(lockPin, lockState);
      digitalWrite(ledPin, lockState);
      opened = millis();
    }
  }
  if (lockState== HIGH && (millis()-opened) > timeOut) {
    lockState = LOW;
    digitalWrite(lockPin, lockState);
    digitalWrite(ledPin, lockState);
  }
}

