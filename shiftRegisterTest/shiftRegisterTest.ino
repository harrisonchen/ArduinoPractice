int dataPin = 2;
int latchPin = 3;
int clockPin = 4;
int clearPin = 5;
//int time = 10;

int serialInput = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(clearPin, OUTPUT);
}

void shiftVal(int val)
{
  digitalWrite(latchPin, LOW);
  digitalWrite(clearPin, LOW);
  digitalWrite(clearPin, HIGH);
  //shiftOut(dataPin, clockPin, bitOrder, value);
  shiftOut(dataPin, clockPin, MSBFIRST, val);
  digitalWrite(latchPin, HIGH);
}

void updateLed()
{
  serialInput = Serial.read() - '0';
  Serial.println(serialInput);
  if(serialInput == 0)
  {
    shiftVal(0x00);
  }
  else if(serialInput == 1)
  {
    shiftVal(0x01);
  }
  else if(serialInput == 2)
  {
    shiftVal(0x02);
  }
  else if(serialInput == 3)
  {
    shiftVal(0x04);
  }
  else if(serialInput == 4)
  {
    shiftVal(0x08);
  }
  else if(serialInput == 5)
  {
    shiftVal(0x10);
  }
  else if(serialInput == 6)
  {
    shiftVal(0x20);
  }
  else if(serialInput == 7)
  {
    shiftVal(0x40);
  }
  else if(serialInput == 8)
  {
    shiftVal(0x80);
  }
  else if(serialInput == 9)
  {
    shiftVal(0xAA);
  }
}

void loop()
{
  if(Serial.available())
  {
    updateLed();
  }
}
