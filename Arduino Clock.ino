/*
This is a clock+ stopwatch+ alarm
Make sure all slide switches are off before starting for proper working
Instructions for alarm:
1.Make sure stop watch switches are off.
2.Slide "Alarm ON/OFF" switch to set the alarm
3.Use the 2 push buttons to change the time
4.Slide the "Confirm Alarm" switch to go back to viewing time but with alarm on this time
Instructions for Stop-Watch:
1.Slide the "Stopwatch Mode ON/OFF" to turn stop watch on
2.To freeze the stop watch use the slide switch just above that,you can unfreeze by sliding the same switch off.
*/
#include <LiquidCrystal.h>
//Its a 24 hour clock.So peace.
//Set initial Time here.
void freeze_time(int*hours, int*minutes,int *seconds);
 int hours=10;
 int minutes=30;
 int seconds=00;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//stop watch time
 int stop_hours=0;
 int stop_minutes=0;
 int stop_seconds=0;
//alarm time
int alarm_hours=0;
int alarm_minutes=0;
int alarm_seconds =0;


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.println("Time");
  pinMode(9,OUTPUT);
}
void read_alarm(int*h,int*m){
  lcd.setCursor(0,0);
  freeze_time(h,m,&alarm_seconds);
  lcd.setCursor(0,1);
  lcd.print("Set Alarm");
  if (digitalRead(A0)==HIGH) {
    (*h)++;
    if ((*h)==24){
     *h = 0; 
    }
    freeze_time(h,m,&alarm_seconds);
  }
  if (digitalRead(A1) == HIGH){
    (*m)++;
    if (*m == 60){
      *m = 0;
    }
    freeze_time(h,m,&alarm_seconds);
  }
  
}

void freeze_time(int*hours, int*minutes,int *seconds){
lcd.setCursor(0,0);
 if(*hours<10)
 {
   lcd.print("0");
 }
 lcd.print(*hours);
 lcd.print(":");
 if(*minutes<10)
 {
   lcd.print("0");
 }
 lcd.print(*minutes);
 lcd.print(":");
 if(*seconds<10){
   lcd.print("0");
 }
 lcd.print(*seconds);

}
void print_time( int*hours, int*minutes,int *seconds){
 lcd.setCursor(0,0);
 if(*hours<10)
 {
   lcd.print("0");
 }
 lcd.print(*hours);
 lcd.print(":");
 if(*minutes<10)
 {
   lcd.print("0");
 }
 lcd.print(*minutes);
 lcd.print(":");
 if(*seconds<10){
   lcd.print("0");
 }
 lcd.print(*seconds);
 lcd.setCursor(0,1);
 delay(1000);
 
 (*seconds)++;
 if(*seconds==60){
  *seconds=0;
  *minutes=*minutes+1;
 }
 if(*minutes==60)
 {
  *minutes=0;
  *hours=*hours+1;
 }
 if(*hours==24)
 {
  *hours=0;
 }
}
void loop() {
  

 
 if (digitalRead(7)==HIGH){
  if(digitalRead(8)==HIGH){
     freeze_time(&stop_hours,&stop_minutes,&stop_seconds);
  }else{ 
  print_time(&stop_hours,&stop_minutes,&stop_seconds);
  }
  lcd.setCursor(0,1);
  lcd.println("Stopwatch");
  
 }else if (digitalRead(10)==HIGH ){
   
     if (digitalRead(13) == HIGH){
     lcd.clear();
     lcd.setCursor(0,1);
     lcd.println("Time");
     print_time(&hours,&minutes,&seconds);
    }else{
     read_alarm(&alarm_hours,&alarm_minutes); 
    }
 } 
  else{
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.println("Time");
  
  print_time(&hours,&minutes,&seconds);
 
 } 
 if (digitalRead(13) == HIGH){
    if ((alarm_hours == hours) && (alarm_minutes == minutes)) {
      digitalWrite(9,HIGH);
      tone(9,4000,500);
     }
   }

}