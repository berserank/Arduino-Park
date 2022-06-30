/***********************************
 I  have mentioned a part of code as comments 
 because I want to use that as per condition in the question,
 but that would just bring up some errors or have a delay or
 cant measure the speed for a long lime,but it can work for higher speeds.

 The code written in comments counts time taken for one revolution and uses that to calculate speed.
 Whereas code not in comments uses time taken for one pulse and uses that to calculate speed.
 Latter can have errors if signal isnt filtered properly.
 Hence Signal filtering is must before calculation
**************************/

#define ClockPin 2 
#define DataPin 4 
#define number_of_pulses 400//MAX pulses on Optical Encoder per revolution,can be changed with encoder model
float Multiplier = (60*1000000)/number_of_pulses;// Here its 150000
volatile long EncoderCounter=0;
//volatile long pEncoderCounter;[Variable for code written as comments]
volatile float SpeedInRPM = 0;
long Counter;
float Speed;
//Setting up LCD 
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 8, d6 = 3, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
static uint32_t lTime = 0;//Setting initial ltime to 0
void Arise(){ 
    
    uint32_t cTime; // Current Time
    cTime = micros(); // Store the time for RPM Calculations
    int32_t dTime; // Delt in time

// Encoder Code
    bool DataPinVal = digitalRead(DataPin);
    if (DataPinVal == HIGH){
        EncoderCounter++;
      } else {
        EncoderCounter--;
      }
/* while ((EncoderCounter - pEncoderCounter) != 400) {
      if (DataPinVal == HIGH){
        EncoderCounter++;//If I am using this part,I wont use the above part
      } else {
        EncoderCounter--;
      }
    
    }
    pEncoderCounter = EncoderCounter
    */

// calculate the difference of time between 2 rising edges

    dTime = cTime - lTime; 
    lTime = cTime;
    
    SpeedInRPM = Multiplier / ((DataPinVal) ? dTime: (-1 * dTime));//Calculating Speed in both positive and negative directions
    // SpeedInRPM =(Multiplier * 400)/ ((DataPinVal) ? dTime: (-1 * dTime));[for using the code written in comments]
}

void setup() {
  Serial.begin(115200); //115200
  lcd.begin(16, 2);
  pinMode(ClockPin, INPUT);  
  pinMode(DataPin, INPUT);
  lcd.print("Speed in RPM is");
  attachInterrupt(0,Arise,RISING);
}

void loop() {

  noInterrupts (); 
  Counter = EncoderCounter;
  Speed = SpeedInRPM;
  interrupts ();
  lcd.setCursor(0, 1); 
  lcd.print(Speed);
// delaying for better performance
  delay(10);
  
}
