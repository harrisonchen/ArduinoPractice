int led = 11;
int ledTimer = 0;
int brightness = 0;
int val = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void ledBrightness(int val)
{
  if(val != 1){ledTimer = 0; brightness = 0;}
  if(val == 0){analogWrite(led, 0);}
  else if(val == 1){fade();}
  else if(val == 2){analogWrite(led, 40);}
  else if(val == 3){analogWrite(led, 70);}
  else if(val == 4){analogWrite(led, 100);}
  else if(val == 5){analogWrite(led, 130);}
  else if(val == 6){analogWrite(led, 160);}
  else if(val == 7){analogWrite(led, 190);}
  else if(val == 8){analogWrite(led, 220);}
  else if(val == 9){analogWrite(led, 250);}
}

void fade()
{
  if(ledTimer <= 10000)
  {
    if(ledTimer % 80 == 0)
    {
      brightness = brightness + 1;
    }
    analogWrite(led, brightness);
  }
  else if((ledTimer > 10000) && (ledTimer <= 20000))
  {
    if(ledTimer % 80 == 0)
    {
      brightness = brightness - 1;
    }
    analogWrite(led, brightness);
  }
  else
  {
    ledTimer = 0;
    brightness = 0;
  }
}

void loop()
{
  if(Serial.available())
  {
    val = Serial.read() - '0';
  }
  ledTimer++;
  ledBrightness(val);
}
