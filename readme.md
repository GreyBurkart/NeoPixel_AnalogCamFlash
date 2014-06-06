# Analog-style camera flash

Very simple, gets job done when a practical lightbulb flash won't work. The simple code emulates a traditional flashbulb which has a warmer color mixture and a flashtrail as the lamp filament cools down. LEDs simply blinking on-off aren't convincing. Point an Adafruit NeoPixel ring backwards towards reflector, press button, flash! Kitbashed together over a lunch break.

### Bill of Materials

* 1x Prop case looking like an 1930's press camera
* 1x 5V Adafruit Trinket (ATtiny85) or similar microcontroller
* 1x Power supply (I used a 9V) with appropriate leads for supplying power to the microcontroller board and LEDs
* 1x small momentary button/tactile switch (N.O.)
* 1x 10k Ohm resistor
* 1x Adafruit 16-NeoPixel ring
* 2 4+ socket female headers for easy Trinket removal
* 1x Protoboard
* 1x Mounting screw, washer, and standoff set for protoboard
* Plenty of tape
* Stranded-core hookup wire (I used 22 AWG)

### Third-Party Libraries
* Adafruit's NeoPixel library
* If using the Adafruit Trinket, you'll need their customized Arduino IDE for upload

2014-05 gmb