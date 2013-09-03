/*
Multi-Option Potentiometer
1) Off
2) One LED on
3) Two LED on
4) LED Pattern flash
*/

int ledSolarPIN = 9;
int ledOutputPIN = 10;
int ledOutputPIN2 = 11;
int optionState = 0;
int optionChoice = 0;
int option = 0;
int patternTimer = 0;
int brightness1 = 0;
int brightness2 = 0;
int solarPower = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledOutputPIN, OUTPUT);
  pinMode(ledOutputPIN2, OUTPUT);
  pinMode(ledSolarPIN, OUTPUT);
}

enum PotentStates{PotentOff, oneLed, twoLed, patternLed} PotentState;
void potentController()
{
  switch(PotentState)
  {
    case PotentOff:
    {
      if(optionChoice == 0)
      {
        PotentState = PotentOff;
        option = 0;
      }
      if(optionChoice > 0 && optionChoice <= 50)
      {
        PotentState = oneLed;
        option = 1;
      }
      else if(optionChoice > 50 && optionChoice <= 100)
      {
        PotentState = twoLed;
        option = 2;
      }
      else if(optionChoice > 100 && optionChoice <= 150)
      {
        PotentState = patternLed;
        option = 3;
      }
      break;
    }
    case oneLed:
    {
      if(optionChoice == 0)
      {
        PotentState = PotentOff;
        option = 0;
      }
      if(optionChoice > 0 && optionChoice <= 50)
      {
        PotentState = oneLed;
        option = 1;
      }
      else if(optionChoice > 50 && optionChoice <= 100)
      {
        PotentState = twoLed;
        option = 2;
      }
      else if(optionChoice > 100 && optionChoice <= 150)
      {
        PotentState = patternLed;
        option = 3;
      }
      break;
    }
    case twoLed:
    {
      if(optionChoice == 0)
      {
        PotentState = PotentOff;
        option = 0;
      }
      if(optionChoice > 0 && optionChoice <= 50)
      {
        PotentState = oneLed;
        option = 1;
      }
      else if(optionChoice > 50 && optionChoice <= 100)
      {
        PotentState = twoLed;
        option = 2;
      }
      else if(optionChoice > 100 && optionChoice <= 150)
      {
        PotentState = patternLed;
        option = 3;
      }
      break;
    }
    case patternLed:
    {
      if(optionChoice == 0)
      {
        PotentState = PotentOff;
        option = 0;
      }
      if(optionChoice > 0 && optionChoice <= 50)
      {
        PotentState = oneLed;
        option = 1;
      }
      else if(optionChoice > 50 && optionChoice <= 100)
      {
        PotentState = twoLed;
        option = 2;
      }
      else if(optionChoice > 100 && optionChoice <= 150)
      {
        PotentState = patternLed;
        option = 3;
      }
      break;
    }
    default:
    {
      PotentState = PotentOff;
      break;
    }
  }
}

enum oneLedStates{oneLedOff, oneLedOn} oneLedState;
void oneLedController()
{
  switch(oneLedState)
  {
    case oneLedOff:
    {
      if(option == 1)
      {
        oneLedState = oneLedOn;
        analogWrite(ledOutputPIN, 255);
      }
      break;
    }
    case oneLedOn:
    {
      analogWrite(ledOutputPIN, 255);
      analogWrite(ledOutputPIN2, 0);
      if(option != 1)
      {
        oneLedState = oneLedOff;
        analogWrite(ledOutputPIN, 0);
      }
      break;
    }
    default:
    {
      oneLedState = oneLedOff;
      break;
    }
  }
}

enum twoLedStates{twoLedOff, twoLedOn} twoLedState;
void twoLedController()
{
  switch(twoLedState)
  {
    case twoLedOff:
    {
      if(option == 2)
      {
        twoLedState = twoLedOn;
        analogWrite(ledOutputPIN, 255);
        analogWrite(ledOutputPIN2, 255);
      }
      break;
    }
    case twoLedOn:
    {
      analogWrite(ledOutputPIN, 255);
      analogWrite(ledOutputPIN2, 255);
      if(option != 2)
      {
        twoLedState = twoLedOff;
        analogWrite(ledOutputPIN, 0);
        analogWrite(ledOutputPIN2, 0);
      }
      break;
    }
    default:
    {
      twoLedState = twoLedOff;
      break;
    }
  }
}

enum patternLedStates{patternOff, pattern1, pattern2, pattern3, pattern4, pattern5,
                       pattern6, pattern7, pattern8, pattern9} patternLedState;
void patternLedController()
{
  if(option != 3)
  {
    patternLedState = patternOff;
  }
  else
  {
    patternTimer++;
  }
  switch(patternLedState)
  {
    case patternOff:
    {
      brightness1 = 0;
      brightness2 = 0;
      patternTimer = 0;
      if(option == 3)
      {
        patternLedState = pattern1;
      }
      break;
    }
    case pattern1:
    {
      if(patternTimer < 5000)
      {
        if(patternTimer % 20 == 0)
        {
          brightness1 += 1;
        }
        analogWrite(ledOutputPIN, brightness1);
        analogWrite(ledOutputPIN2, 0);
      }
      else
      {
        patternLedState = pattern2;
        patternTimer = 0;
      }
      break;
    }
    case pattern2:
    {
      if(patternTimer < 5000)
      {
        if(patternTimer % 20 == 0)
        {
          brightness2 += 1;
        }
        analogWrite(ledOutputPIN, brightness1);
        analogWrite(ledOutputPIN2, brightness2);
      }
      else
      {
        patternLedState = pattern3;
        patternTimer = 0;
        brightness1 = 0;
        brightness2 = 0;
      }
      break;
    }
    case pattern3:
    {
      if(patternTimer < 5000)
      {
        if(patternTimer % 20 == 0)
        {
          brightness1 += 1;
          brightness2 += 1;
        }
        analogWrite(ledOutputPIN, brightness1);
        analogWrite(ledOutputPIN2, brightness2);
      }
      else
      {
        patternLedState = pattern4;
        patternTimer = 0;
        brightness1 = 0;
        brightness2 = 0;
      }
      break;
    }
    case pattern4:
    {
      if(patternTimer < 5000)
      {
        if(patternTimer % 20 == 0)
        {
          brightness1 += 1;
          brightness2 += 1;
        }
        analogWrite(ledOutputPIN, brightness1);
        analogWrite(ledOutputPIN2, brightness2);
      }
      else
      {
        patternLedState = pattern5;
        patternTimer = 0;
        brightness1 = 0;
        brightness2 = 0;
      }
      break;
    }
    case pattern5:
    {
      if(patternTimer < 5000)
      {
        if(patternTimer % 20 == 0)
        {
          brightness1 += 1;
          brightness2 += 1;
        }
        analogWrite(ledOutputPIN, brightness1);
        analogWrite(ledOutputPIN2, brightness2);
      }
      else
      {
        patternLedState = pattern6;
        patternTimer = 0;
      }
      break;
    }
    case pattern6:
    {
      if(patternTimer < 5000)
      {
        if(patternTimer % 20 == 0)
        {
          brightness2 -= 1;
        }
        analogWrite(ledOutputPIN, brightness1);
        analogWrite(ledOutputPIN2, brightness2);
      }
      else
      {
        patternLedState = pattern7;
        patternTimer = 0;
      }
      break;
    }
    case pattern7:
    {
      if(patternTimer < 5000)
      {
        if(patternTimer % 20 == 0)
        {
          brightness1 -= 1;
        }
        analogWrite(ledOutputPIN, brightness1);
        analogWrite(ledOutputPIN2, brightness2);
      }
      else
      {
        patternLedState = pattern1;
        patternTimer = 0;
      }
      break;
    }
    case pattern8:
    {
      break;
    }
    case pattern9:
    {
      break;
    }
    default:
    {
      patternLedState = patternOff;
      break;
    }
  }
}

void solarLedController()
{
  solarPower = analogRead(A1);
  solarPower = map(solarPower, 0, 1023, 0, 255);
  analogWrite(ledSolarPIN, solarPower);
}

void loop()
{
  optionChoice = analogRead(A0);
  optionChoice = map(optionChoice, 0, 1023, 0, 150);
  potentController();
  oneLedController();
  twoLedController();
  patternLedController();
  solarLedController();
}
