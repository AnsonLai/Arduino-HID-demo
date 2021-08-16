#include <SoftwareSerial.h>
#include <Mouse.h>

char incomingByte = 0;
int x;
int y;
// TODO: More than just x and y state, will need to determine press, wheel, keyboard, etc.
char axis;

int aa_index;
int bb_index;
char aa[4];
char bb[4];

SoftwareSerial hc05(9,10);

void setup(){
  delay(500);
  Serial.begin(9600);
  hc05.begin(9600);
  Mouse.begin();
}

void loop(){
  if (hc05.available()){
    incomingByte = hc05.read();
//    Serial.write(incomingByte);
    if(incomingByte == 'x'){
      axis = 'x';
    }
    else if(incomingByte == 'y'){
      axis = 'y';
    }
    else if(incomingByte == 'z'){
      axis = 'n';
      int x1 = atoi(aa);
      int y1 = atoi(bb);
//      Serial.write("x");
//      Serial.print(x1);
//      Serial.print(aa);
//      Serial.write("y");
//      Serial.print(y1);
//      Serial.print(bb);
      for(int i = 0; i<30; i++){
        Mouse.move(-127, -127);
      }
      for(int j = x1/127; j>0; j--){
        Mouse.move(127, 0);
      }
      Mouse.move(x1%127, 0);
      for(int k = y1/127; k>0; k--){
        Mouse.move(0, 127);
      }
      Mouse.move(0, y1%127);
//      Mouse.move(x1, y1);
      memset(aa, 0, sizeof(aa));
      memset(bb, 0, sizeof(bb));
      aa_index = 0;
      bb_index = 0;
    }
    else {
      char ch1 = incomingByte;
      if (axis == 'x'){
        aa[aa_index] = ch1;
        aa_index = aa_index + 1;
      }
      else if (axis == 'y'){
        bb[bb_index] = ch1;
        bb_index = bb_index + 1;
      }
    }
  }
}
