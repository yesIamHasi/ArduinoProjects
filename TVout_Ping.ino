#include <TVout.h>
#include <fontALL.h>
/* 
 * This program prints distance from Ping sensor
 * to TV using TVout library.
 * Board: Arduino UNO AT MEGA328
 * Author: S.Haseeb
 */

TVout TV;
unsigned char x,y;


void setup()  {
  TV.begin(PAL);  
  TV.select_font(font8x8);
  Serial.begin(9600);
  pinMode(5, OUTPUT);// GND of ping sensor
  pinMode(2, OUTPUT);// +5v of ping sensor
  digitalWrite(2,HIGH);
  digitalWrite(5,LOW);
  pinMode(3, OUTPUT);// Trigger Pin
  pinMode(4, INPUT); // Echo Pin
}

void loop() {
  x=0;
  y=0;
  long duration;
  
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);

  duration = pulseIn(4, HIGH) / 29 / 2;
  
  TV.clear_screen();
  TV.print(10, 10,"You are ");
  TV.print(duration);
  TV.print(" cm");
  TV.println(" \naway from me.");
  delay(10000);
  TV.clear_screen();

  
 
}
