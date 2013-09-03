int photoResistor = 0;
int solarPower = 0;
int led = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  solarPower = analogRead(photoResistor);
  solarPower = constrain(solarPower, 70, 575);
  solarPower = map(solarPower, 70, 575, 255, 0);
  analogWrite(led, solarPower);
}
