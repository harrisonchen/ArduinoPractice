int jStickX = A0;
int jStickY = A1;
int jStickButton = 8;
int xVal = 0;
int yVal = 0;
int buttonPushed = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(jStickButton, INPUT);
}

void loop()
{
  xVal = analogRead(jStickX);
  yVal = analogRead(jStickY);
  if(digitalRead(jStickButton) == HIGH)
  {
    buttonPushed = 0;
  }
  else
  {
    buttonPushed = 1;
  }
  Serial.print(xVal);
  Serial.print('\t');
  Serial.print(yVal);
  Serial.print('\t');
  Serial.println(buttonPushed);
  delay(100);
}
