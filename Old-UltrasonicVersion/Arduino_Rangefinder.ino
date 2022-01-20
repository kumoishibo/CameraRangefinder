
/*
Arduino Sketch for rangefinding and displaying to a 7segment.

Library for SR04: from Elegoo SR04 kit https://www.elegoo.com/
Library for TM1637: from Avishay Orpaz https://github.com/avishorp/TM1637
*/


#include "SR04.h"
#define TRIG_PIN 15
#define ECHO_PIN 14
#include <TM1637Display.h>

#define CLK SCL
#define DIO SDA

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
TM1637Display display(CLK, DIO);

void setup() {
   delay(1000);
}

void loop() {
  display.setBrightness(15);
   a=sr04.Distance();
   if (a>400) a=0; //If distance over 4m, show as "0"
   display.showNumberDec(a, false); // Expect: ___0
   delay(200); //200ms delay 
}
