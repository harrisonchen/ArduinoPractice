//Multi
int ledOutputPIN = 11;
int brightness = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledOutputPIN, OUTPUT);
}

void loop()
{
  brightness = analogRead(A0);
  brightness = map(brightness, 0, 1023, 0, 10);
  analogWrite(11, brightness);
}
