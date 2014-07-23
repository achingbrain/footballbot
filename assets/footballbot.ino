const byte MOTOR_SPEED = 0xF0;
const byte MOTOR_DIRECTION = 0xF1;
const byte DIGITAL_WRITE = 0xF2;

void setup()
{
  Serial.begin(9600);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  if(Serial.available() == 3) {
    digitalWrite(13, HIGH);

    byte command = Serial.read();
    byte pin = Serial.read();
    byte value = Serial.read();

    if(command == MOTOR_SPEED) {
      analogWrite(pin, value);
    } else if(command == MOTOR_DIRECTION || command == DIGITAL_WRITE) {
      digitalWrite(pin, value);
    }
  }
}
