// C++ code
//
void setup()
{
  pinMode(8,INPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop()
{ 
   Serial.println("INPUT");
   Serial.println(analogRead(A1));
   Serial.println("OUTPUT");
   Serial.println(analogRead(A0));
   Serial.println(digitalRead(8));
   int a = digitalRead(8);
   if (a == HIGH){
    digitalWrite(12,HIGH);
   }else {
     digitalWrite(12,LOW);
   }
  delay(100);
}