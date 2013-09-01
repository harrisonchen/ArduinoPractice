//First Program

int buttonInput = 7;
int ledOutput = 12;
int startLed;

void setup()
{
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
       digitalWrite(ledOutput, LOW);
       break;
     }
     case ledOff:
     {
       if(startLed == 1)
       {
         ledState = ledOn;
         digitalWrite(ledOutput, HIGH);
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
  ledFlash();
  delay(100);
}
