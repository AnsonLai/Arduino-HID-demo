#include "Keyboard.h"
#include "Mouse.h"

// To be more convincing, change the Arduino board name to something like a Logitech Mouse in the boards.txt file
// C:\Program Files (x86)\Arduino\hardware\arduino\avr\boards.txt

int direction = 8;

void setup() {
  delay(2000);
  
  Serial.begin(9600);
  Mouse.begin();
  Keyboard.begin();
}           

void loop() {
  // put your main code here, to run repeatedly:
  int rand_walk = random(0, 1000);
  
  if (rand_walk < 993) {
    if (direction == 0) {
      Mouse.move(1, 0);
    }
    else if (direction == 1) {
      Mouse.move(0, 1);
    }
    else if (direction == 2) {
      Mouse.move(-1, 0);
    }
    else if (direction == 3) {
      Mouse.move(0, -1);
    }
    else if (direction == 4) {
      Mouse.move(1, 1);
    }
    else if (direction == 5) {
      Mouse.move(-1, -1);
    }
    else if (direction == 6) {
      Mouse.move(1, -1);
    }
    else if (direction == 7) {
      Mouse.move(-1, 1);
    }
    else {
      Mouse.move(0, 0);
    }
  }
  else if (rand_walk < 1000) {
    direction = random(0,20);
  }
}
