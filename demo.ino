#include "Keyboard.h"
#include "Mouse.h"

void setup() {
  // put your code here, to run once:
  delay(4000);
  
  Serial.begin(9600);
  Mouse.begin();
  Keyboard.begin();

  Mouse.move(0, 9000);
  Mouse.move(0, -9000);

  Mouse.move(0, -400);
  Mouse.move(400, 0);
  Mouse.move(0, 400);
  Mouse.click(MOUSE_LEFT);
  Mouse.click(MOUSE_LEFT);
  Keyboard.write('u');

}

void loop() {
  // put your main code here, to run repeatedly:

}
