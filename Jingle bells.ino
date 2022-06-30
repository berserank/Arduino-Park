#include <Adafruit_NeoPixel.h>

int LEDPIN = 2;
int NUMPIXELS = 12;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  pinMode(8, OUTPUT);
  pixels.begin(); 
}

void loop()
{
  digitalWrite(8,HIGH);
  delay(500); 
  
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      tone(8, 659, 200 ) ;
      pixels.setPixelColor(2, pixels.Color(255,0,0));
      pixels.setPixelColor(3, pixels.Color(255,0,0));
      pixels.setPixelColor(5, pixels.Color(255,255,0));
      pixels.setPixelColor(7, pixels.Color(0,255,0));
      pixels.setPixelColor(10, pixels.Color(0,255,0));
      pixels.setPixelColor(0, pixels.Color(255,255,0));
      pixels.show();
      delay(200); 
      pixels.clear();
      pixels.show();
      noTone(8);
      
      delay(200); 
    }
   
    delay(400); 
  }
  tone(8, 659, 200); 
  pixels.setPixelColor(0, pixels.Color(255,0,255));
  pixels.setPixelColor(1, pixels.Color(255,0,0));
  pixels.show();
  
  delay(400); 
  tone(8, 784, 200); 
  pixels.setPixelColor(0, pixels.Color(255,0,255));
  pixels.setPixelColor(1, pixels.Color(255,0,0));
  pixels.setPixelColor(2, pixels.Color(255,0,255));
  pixels.setPixelColor(3, pixels.Color(255,0,0));
  pixels.show();
  delay(400); 
  tone(8, 523, 400); 
  pixels.setPixelColor(0, pixels.Color(255,0,255));
  pixels.setPixelColor(1, pixels.Color(255,0,0));
  pixels.setPixelColor(2, pixels.Color(255,0,255));
  pixels.setPixelColor(3, pixels.Color(255,0,0));
  pixels.setPixelColor(4, pixels.Color(255,0,255));
  pixels.setPixelColor(5, pixels.Color(255,0,0));
  pixels.show();
  delay(600); 
  tone(8, 587, 100); 
  pixels.setPixelColor(0, pixels.Color(255,0,255));
  pixels.setPixelColor(1, pixels.Color(255,0,0));
  pixels.setPixelColor(2, pixels.Color(255,0,255));
  pixels.setPixelColor(3, pixels.Color(255,0,0));
  pixels.setPixelColor(4, pixels.Color(255,0,255));
  pixels.setPixelColor(5, pixels.Color(255,0,0));
  pixels.setPixelColor(6, pixels.Color(255,0,255));
  pixels.setPixelColor(7, pixels.Color(255,0,0));
  pixels.show();
  delay(200); 
  tone(8, 659, 200);
  pixels.setPixelColor(0, pixels.Color(255,0,255));
  pixels.setPixelColor(1, pixels.Color(255,0,0));
  pixels.setPixelColor(2, pixels.Color(255,0,255));
  pixels.setPixelColor(3, pixels.Color(255,0,0));
  pixels.setPixelColor(4, pixels.Color(255,0,255));
  pixels.setPixelColor(5, pixels.Color(255,0,0));
  pixels.setPixelColor(6, pixels.Color(255,0,255));
  pixels.setPixelColor(7, pixels.Color(255,0,0));
  pixels.setPixelColor(8, pixels.Color(255,0,255));
  pixels.setPixelColor(9, pixels.Color(255,0,0));
  pixels.setPixelColor(10, pixels.Color(255,0,255));
  pixels.setPixelColor(11, pixels.Color(255,0,0));
  pixels.show();
  delay(750); 
  pixels.clear();
  pixels.show();
  delay(750);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      tone(8, 659, 200);
      pixels.setPixelColor(2, pixels.Color(255,0,0));
      pixels.setPixelColor(3, pixels.Color(255,0,0));
      pixels.setPixelColor(5, pixels.Color(255,255,0));
      pixels.setPixelColor(7, pixels.Color(0,255,0));
      pixels.setPixelColor(10, pixels.Color(0,255,0));
      pixels.setPixelColor(0, pixels.Color(255,255,0));
      pixels.show();
      delay(200); 
      noTone(8);
      pixels.clear();
      pixels.show();
      delay(200); 
    }
    delay(400); 
  }
  for (int i = 0; i < 4; ++i) {
    tone(8, 784, 200);
    pixels.setPixelColor(3*i,pixels.Color(255,0,0));
    pixels.setPixelColor(3*i+1,pixels.Color(0,255,0));
    pixels.setPixelColor(3*i+2,pixels.Color(0,0,255)); 
    pixels.show();
    delay(200); 
    noTone(8);
    pixels.clear();
    pixels.show();                     
    delay(200); 
  }
  tone(8, 784, 600);  
  for(int i =0;i<6;i++){
    pixels.setPixelColor(2*i, pixels.Color(255,0,255));
    pixels.setPixelColor(2*i+1, pixels.Color(0,255,255));
  }
  pixels.show();
  delay(200); 
  noTone(8);
  delay(200); 
  delay(20000); 
}