#include <Adafruit_NeoPixel.h>

#define SensorPin A5
#define LE_PIN 4
#define LED_COUNT 70

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LE_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
	// put your setup code here to run once:
	pinMode(SensorPin, INPUT);
	pinMode(LE_PIN, OUTPUT);
	strip.begin();
}

void loop() {
	//put your main code here, to run repeatedly:
	int sensorValue = digitalRead(SensorPin);
	if(sensorValue == HIGH){
		colorWipe(strip.Color(255,   0,   0)     , 50); // Red
		colorWipe(strip.Color(  0, 255,   0)     , 50); // Green
		colorWipe(strip.Color(  0,   0, 255)     , 50); // Blue
		colorWipe(strip.Color(  0,   0,   0, 255), 50); // True white (not RGB white)		
	}
	else{
		strip.fill(strip.Color(128, 0, 200), 0, 70);
		strip.show();
	}
	
}
// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}