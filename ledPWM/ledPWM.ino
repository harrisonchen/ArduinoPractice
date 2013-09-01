//First Program

int ledAdjustInput = 7;
int buttonInput = 8;
int ledOutput = 11;
int startLed = 25;
int ledLevel = 0;

void setup()
{
  pinMode(ledAdjustInput, INPUT);
  pinMode(buttonInput, INPUT);
  pinMode(ledOutput, OUTPUT);
}

boolean debounce()
{
  boolean current = digitalRead(buttonInput);
  if(!current)
  {
    delay(10);
    current = digitalRead(buttonInput);
  }
  return current;
}

enum buttonStates{buttonOn, buttonOff} buttonState;
void buttonRead()
{
  switch(buttonState)
  {
    case -1:
    {
      buttonState = buttonOff;
      break;
    }
    case buttonOn:
    {
      if(debounce() == LOW)
      {
        buttonState = buttonOff;
      }
      break;
    }
    case buttonOff:
    {
      if(debounce() == HIGH)
      {
        buttonState = buttonOn;
        startLed = (~startLed)&0x01;
      }
      break;
    }
    default:
    {
      buttonState = buttonOff;
      break;
    }
  }
}

enum ledAdjustStates{ledStay, ledAdjOn, ledAdjOff} ledAdjustState;
void adjustLedLevel()
{
  switch(ledAdjustState)
  {
    case ledStay:
    {
      if(digitalRead(ledAdjustInput) == HIGH)
      {
        ledAdjustState = ledAdjOn;
      }
      break;
    } 
    case ledAdjOn:
    {
      if(ledLevel > 256)
      {
        ledLevel = 25;
      }
      ledLevel += 50;
      if(digitalRead(ledAdjustInput) == LOW)
      {
        ledAdjustState = ledStay;
      }
      break;
    }
    case ledAdjOff:
    {
      break;
    }
    default:
    {
      ledAdjustState = ledStay;
    }
  }
}

enum ledStates{ledOn, ledOff} ledState;
void ledFlash()
{
  switch(ledState)
  {
     case -1:
     {
       ledState = ledOff;
       break;
     }
     case ledOn:
     {
       ledState = ledOff;
       analogWrite(ledOutput, LOW);
       break;
     }
     case ledOff:
     {
       if(startLed == 1)
       {
         ledState = ledOn;
         analogWrite(ledOutput, ledLevel);
       }
       break;
     }
     default:
     {
       ledState = ledOff;
       break;
     }
  }
}

void loop()
{
  buttonRead();
  adjustLedLevel();
  ledFlash();
  delay(100);
}
