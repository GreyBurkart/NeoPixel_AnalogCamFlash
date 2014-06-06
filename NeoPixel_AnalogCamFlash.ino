/*
 * ANALOG CAMERA FLASH (for theatrical prop)
 * 2014-05 gmb
 * 
 * MATERIALS:
 * - 5V Adafruit Trinket!
 * - 9V power supply > BAT/GND
 * - Pin 0 > NeoPixel DataIN
 * - 5V > NeoPixel PWR
 * - NeoPixel GND > GND
 * - 5V > Momentary Button ...> Pin 2 // ...> 10kohm > GND (as voltage divider)
 *
 * 
*/


// SETUP YOUR PIXELS AND PINS HERE
#define NUMPIX 16  // Match to your NeoPixel strip
#define FLASH 0  // DataIn pin
#define TRIGGER 2  // Button pin



// OK, NOW CODE BEGINS
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIX, FLASH, NEO_GRB + NEO_KHZ800);


void setup() {
  // Serial.begin(9600);  // Debugging option for ATMega
  strip.begin();
  strip.show();  // Initialize all pixels to 'off'

  pinMode(TRIGGER, INPUT_PULLUP);
  // digitalWrite(TRIGGER, HIGH);  // Uncomment if the trigger button doesn't work for some reason

}


void loop() {
  
  // Get state of trigger button
  int state = digitalRead(TRIGGER);
  // Serial.println(state);  // Debugging option for ATMega
  if(state == LOW) {  // If button is pressed (LOW), run flashMe
    flashMe();
  }
  else {  // If button is not pressed (HIGH), turn off pixels
    for(int pix = 0; pix < NUMPIX; pix ++){
      strip.setPixelColor(pix, 0, 0, 0);
    }
    strip.show();
  }
  delay(50);  
}



// FLASH SEQUENCE
void flashMe() {
  // Flash In
  for(int inValue = 0; inValue < 255; inValue ++){
    for(int pix = 0; pix < NUMPIX; pix ++){
      strip.setPixelColor(pix, inValue, inValue, (inValue/5));  // Initial color mix
    }
    strip.show();
    delayMicroseconds(25);  // Slightly better than "instant on"
  }

  // Flash Out
  for(int outValue = 255; outValue > 0; outValue --){
    for(int pix = 0; pix < NUMPIX; pix ++){
    strip.setPixelColor(pix, outValue, outValue, outValue/5);  // Fadeout color mix
    }
    strip.show();
    delayMicroseconds(4000);  // Fade-out tail time
  }

}


