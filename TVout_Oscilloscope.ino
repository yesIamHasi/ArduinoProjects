#include <TVout.h>
#include <fontALL.h>

/* Program for graphing voltage from A0
 * in TV.
 * Board: Arduino UNO (AT-MEGA 328)
 * PIN Config: Default
 * Author: S.Haseeb
 */

TVout TV;
unsigned char x,y;


void setup()  {
  x=1;
  y=0;
  TV.begin(PAL);  
  TV.select_font(font8x8);
  TV.println("Oscilloscope");
  x=0;
}

void loop() {
  if (x == 126){
    x = 0;
    TV.clear_screen();
    TV.println("Oscilloscope");
  }
  // To make the values smaller so that they 
  // appear on low resolution TV
  y=analogRead(A0)/6;
  TV.set_pixel(x, y, 1);
  
  delay(10);
}
