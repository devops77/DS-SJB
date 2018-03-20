
#include <Adafruit_NeoPixel.h>

/*
* Utility functions to help debugging running code.
*/

#ifndef DEBUGUTILS_H
#define DEBUGUTILS_H


#define DEBUG_PRINT(str)        \
   Serial.print(millis());     \
   Serial.print(": ");         \
   Serial.print(__PRETTY_FUNCTION__); \
   Serial.print(' ');          \
   Serial.print(__FILE__);     \
   Serial.print(':');          \
   Serial.print(__LINE__);     \
   Serial.print(' ');          \
   Serial.println(str);

#endif

#define PIN 8

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_GRB + NEO_KHZ800);

int i =0;

void setup() {
  // put your setup code here, to run once:
 // initialize digital pin LED_BUILTIN as an output
 Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  // set up nep pixel
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  DEBUG_PRINT("High");
  for (int i=0; i<50; i++)
  {
    strip.setPixelColor(i, int(random(0,255)), int(random(0,255)), int(random(0,255)) );
  }
  strip.show();
  delay(1000);                       // wait for a second
 
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  DEBUG_PRINT("Low");
  for (int i=0; i<50; i++)
  {
    strip.setPixelColor(i, int(random(0,255)), int(random(0,255)), int(random(0,255)) );
  }
  strip.setPixelColor(0, int(255), int(0), int(0));
  strip.show();
  delay(1000);
 
}


