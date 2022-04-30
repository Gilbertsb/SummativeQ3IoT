// C++ code
//
#include <LiquidCrystal.h>

int photpin=2;
int relpin=3;                                     //Decralation
int sensvalue=0;
const int trigPin = 9;
const int echoPin = 10;
const int trigPin1 = 11;
const int echoPin1 = 12;
const int buzzPIN=13;

long duration;
float distanceCm, distanceInch;

long duration1;
float distanceCm1, distanceInch1;

const int rs = 8, en = 7, d4 = 6, d5 = 5, d6 = 4, d7 = 2; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  lcd.begin(16, 2); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(buzzPIN,OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{ 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm= duration*0.034/100;
  Serial.println("Sensor 1");
  Serial.print(duration);
  
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distanceCm1= duration1*0.034/100;
  Serial.println("Sensor 2");
  Serial.print(duration1);
           
  
  if(distanceCm <=1.5){  // IF condition to detect if distance is below 60 cm
    lcd.setCursor(0,0);        //Setting the cordinates of cursal R
    lcd.print("STRANGER IS");
    
    lcd.setCursor(0,1);        //Setting the cordinates of cursal R
    lcd.print("Right: ");
    lcd.print(distanceCm);  
    lcd.print("m"); //printing the value on LCD 
    digitalWrite(buzzPIN,HIGH); //Buzzing the PIEZO
    delay(1000);
  }
  
   else if(distanceCm1 <=1.5){  // IF condition to detect if distance is below 60 cm
    lcd.setCursor(0,0);        //Setting the cordinates of cursal R
    lcd.print("STRANGER IS");
    
    lcd.setCursor(0,1);        //Setting the cordinates of cursal R
    lcd.print("Left: ");
    lcd.print(distanceCm1);  
    lcd.print("m"); //printing the value on LCD 
    digitalWrite(buzzPIN,HIGH); //Buzzing the PIEZO
    delay(1000);
  }
  
   else{
     
     lcd.setCursor(0,0); //Setting the cordinates of cursal sensor L
     lcd.print("No Stranger");
     //lcd.print("Left:");
     //lcd.print(distanceCm1);  
     //lcd.print("m"); //printing the value on LCD          
 
     lcd.setCursor(0,1);        //Setting the cordinates of cursal R
     lcd.print("House is safe");
     //lcd.print("Right: ");
     //lcd.print(distanceCm);  
     //lcd.print("m"); //printing the value on LCD  
     digitalWrite(buzzPIN,LOW);     // Stoping the Piezo
  }
  
  delay(1000); // Delaying a little bit to improve simulation performance
   

}