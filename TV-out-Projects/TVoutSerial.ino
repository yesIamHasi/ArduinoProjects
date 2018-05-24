#include <TVout.h>
#include <fontALL.h>

/*
 * Program for printing directly to TV from Serial Port
 * using TVout library.
 * Board: Arduino UNO AT MEGA328
 * Author: S.Haseeb
 */

TVout TV;
unsigned char x,y;
char DATA[100];

void setup()  {
  x=0;
  y=0;
  TV.begin(PAL);  
  TV.select_font(font6x8);
  Serial.begin(9600);
}

void loop() {
  TV.clear_screen();
  x=0;
  y=0;
  while (Serial.available()>0){
    Serial.readString().toCharArray(DATA, 100);
  }
  TV.println(DATA);
  TV.delay(1000);
  TV.clear_screen();
}
