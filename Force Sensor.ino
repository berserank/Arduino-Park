// C++ code
//
#include <Adafruit_NeoPixel.h>
#define led_number 6
#define led_pin 8
int buzzer = 2;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(led_number,led_pin,NEO_GRB+NEO_KHZ800);  
float fsrReading;     
void setup()
{
  Serial.begin(9600);
  pixels.begin();
  
  pinMode(buzzer,OUTPUT);
}

void loop()
{
   pixels.clear();
   uint32_t a = pixels.Color(0,255,0);
   uint32_t b = pixels.Color(0,255,255);
   uint32_t c = pixels.Color(255,0,0);
    fsrReading = analogRead(A0);
    pixels.setPixelColor(0,a);
    
    float force = (fsrReading*6)/466;
  
    Serial.println(force);
   if (force ==0 ){
    pixels.clear();
    pixels.show();
    }
    if (force > 0 && force < 1) {
      pixels.setPixelColor(0,a);
      pixels.show();
    }
    if (force >= 1 && force < 2) {
      pixels.setPixelColor(0,a);
      pixels.setPixelColor(1,a);
      pixels.show();
    }
    if (force >=2 && force <3) {
      pixels.setPixelColor(0,a);
      pixels.setPixelColor(1,a);
      pixels.setPixelColor(2,b);
      pixels.show();
    }
    if (force >=3 && force <4) {
      pixels.setPixelColor(0,a);
      pixels.setPixelColor(1,a);
      pixels.setPixelColor(2,b);
      pixels.setPixelColor(3,b);
      pixels.show();
    }
    if (force >=4 && force <5) {
      pixels.setPixelColor(0,a);
      pixels.setPixelColor(1,a);
      pixels.setPixelColor(2,b);
      pixels.setPixelColor(3,b);
      pixels.setPixelColor(4,c);
      pixels.show();
    }
    if (force >=5 && force <6) {
      pixels.setPixelColor(0,a);
      pixels.setPixelColor(1,a);
      pixels.setPixelColor(2,b);
      pixels.setPixelColor(3,b);
      pixels.setPixelColor(4,c);
      pixels.setPixelColor(5,c);
      pixels.show();
    }
   if (force == 6){
      pixels.setPixelColor(0,a);
      pixels.setPixelColor(1,a);
      pixels.setPixelColor(2,b);
      pixels.setPixelColor(3,b);
      pixels.setPixelColor(4,c);
      pixels.setPixelColor(5,c);
      pixels.show();
      digitalWrite(2,HIGH);
      tone(buzzer,4000,200);
   }
    delay(100); // Delay a little bit to improve simulation performance
}