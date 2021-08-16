#include "Keyboard.h"
#include "Mouse.h"

const int button1Pin = 4;
const int button2Pin = 5;
const int button3Pin = 6;

boolean button1PrevState = LOW;
boolean button2PrevState = LOW;
boolean button3PrevState = LOW;

boolean button1State = LOW;
boolean button2State = LOW;
boolean button3State = LOW;

char ctrlKey = KEY_LEFT_CTRL;

void setup() {
  delay(4000);
  
  Serial.begin(9600);
  Mouse.begin();
  Keyboard.begin();

  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
}           

void loop() {
  // put your main code here, to run repeatedly:

  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);

  if (button1State == HIGH && button1PrevState == LOW)
  {
    button1PrevState = HIGH;
    Mouse.move(-400, 0);
    delay(1000);
  }
  else if (button1State == LOW)
  {
    button1PrevState = LOW;
  }


  if (button2State == HIGH && button2PrevState == LOW)
  {
    button2PrevState = HIGH;
    Mouse.move(400, 0);
    delay(1000);
  }
  else if (button2State == LOW)
  {
    button2PrevState = LOW;
  }

  if (button3State == HIGH && button3PrevState == LOW)
  {
    button3PrevState = HIGH;
    Keyboard.press(ctrlKey);
    Keyboard.press('v');
    Keyboard.releaseAll();
    delay(1000);
  }
  else if (button3State == LOW)
  {
    button3PrevState = LOW;
  }
}
