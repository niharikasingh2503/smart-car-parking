#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int sensora1 = 6;
const int sensora2 = 7;
const int sensora3 = 8;
const int sensora4 = 9;
int Gas = 13;

#include <SoftwareSerial.h>

SoftwareSerial sim800l(0, 1); // RX,TX for Arduino and for the module it's TXD RXD, they should be inverted

#define button1 10 //Button pin, on the other pin it's wired with GND


bool button_State; //Button state
int b1 = 100;
int pc = 20;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 4);
  // Print a message to the LCD.
  //pinMode(sensora, INPUT);
  
  lcd.print("  PARKING SLOTS");

  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(Gas , INPUT);

  pinMode(button1, INPUT_PULLUP); //The button is always on HIGH level, when pressed it goes LOW
  Serial.begin(9600);   
  delay(1000);
  
  
}

void loop() {

  
  

 


  if(digitalRead(Gas) == HIGH){
    //lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  FIRE!!        ");
    lcd.setCursor(0,1);
    lcd.print("Please Exit ->");
    lcd.setCursor(0,2);
    lcd.print("               ");
    lcd.setCursor(0,3);
    lcd.print("               ");
    
   }
  else
  Sensor1();

  button_State = digitalRead(button1);   //We are constantly reading the button State
 
  if (button_State == LOW) {            //And if it's pressed
    
    Serial.println("Button pressed");
       //Shows this message on the serial monitor
    delay(200);                         //Small delay to avoid detecting the button press many times
    
    SendSMS();                          //And this function is called

 }
 /*
  if (sim800l.available()){            //Displays on the serial monitor if there's a communication from the module
    Serial.write(sim800l.read()); 
  } */

}

  


  void Sensor1(){

  lcd.setCursor(0, 0);
  lcd.print("  PARKING SLOTS");
  lcd.setCursor(0, 2);
  lcd.print("SLT1:");
  lcd.setCursor(8, 2);
  lcd.print("SLT2:");
  lcd.setCursor(0, 3);
  lcd.print("SLT3:");
  lcd.setCursor(8, 3);
  lcd.print("SLT4:");
int statusSensor1 = digitalRead (sensora1);
int statusSensor2 = digitalRead (sensora2);
int statusSensor3 = digitalRead (sensora3);
int statusSensor4 = digitalRead (sensora4);
  int x = 0;
  if (statusSensor1 == 1){
    //digitalWrite(LED1, HIGH); // LED HIGH
    lcd.setCursor(5,2);
    lcd.print(" O ");
    
    //lcd.setCursor(1,1);
    //lcd.print(" The LED IS ON  ");
  }
  
  else
  {
    //digitalWrite(LED1, LOW); // LED LOW
    lcd.setCursor(5,2);
    lcd.print(" V ");
    x++ ;
    led1();
    //lcd.setCursor(0,1);
    //lcd.print(" The LED IS OFF  ");
 
  }

  if (statusSensor2 == 1){
    //digitalWrite(LED1, HIGH); // LED HIGH
    lcd.setCursor(13,2);
    lcd.print(" O ");
    //lcd.setCursor(1,1);
    //lcd.print(" The LED IS ON  ");
  }
  
  else
  {
    //digitalWrite(LED1, LOW); // LED LOW
    lcd.setCursor(13,2);
    lcd.print(" V ");
    x++;
    led2();
    //lcd.setCursor(0,1);
    //lcd.print(" The LED IS OFF  ");
 
  }

  if (statusSensor3 == 1){
    //digitalWrite(LED1, HIGH); // LED HIGH
    lcd.setCursor(5,3);
    lcd.print(" O ");
    //lcd.setCursor(1,1);
    //lcd.print(" The LED IS ON  ");
  }
  
  else
  {
    //digitalWrite(LED1, LOW); // LED LOW
    lcd.setCursor(5,3);
    lcd.print(" V ");
    x++;
    led3();
    //lcd.setCursor(0,1);
    //lcd.print(" The LED IS OFF  ");
 
  }
  
  if (statusSensor4 == 1){
    //digitalWrite(LED1, HIGH); // LED HIGH
    lcd.setCursor(13,3);
    lcd.print(" O ");
    //lcd.setCursor(1,1);
    //lcd.print(" The LED IS ON  ");
  }
  
  else
  {
    //digitalWrite(LED1, LOW); // LED LOW
    lcd.setCursor(13,3);
    lcd.print(" V ");
    x++;
    led4();
    //lcd.setCursor(0,1);
    //lcd.print(" The LED IS OFF  ");
  
 
  }
  lcd.setCursor(0,1);
  lcd.print("VACANT : ");
  lcd.print(x);
  lcd.print("      ");

}


void led1(){
int statusSensor1 = digitalRead (sensora1);
if (statusSensor1 == 0){
  digitalWrite(A0,HIGH);
}
else
digitalWrite(A0,LOW);
}

void led2(){
int statusSensor2 = digitalRead (sensora2);
if (statusSensor2 == 0){
  digitalWrite(A1,HIGH);
}
else
digitalWrite(A1,LOW);
}

void led3(){
int statusSensor3 = digitalRead (sensora3);
if (statusSensor3 == 0){
  digitalWrite(A2,HIGH);
}
else
digitalWrite(A2,LOW);
}

void led4(){
int statusSensor4 = digitalRead (sensora4);
if (statusSensor4 == 0){
  digitalWrite(A3,HIGH);
}
else
digitalWrite(A3,LOW);
}

void SendSMS()
{
  
  Serial.println("Rakesh");
  int bal = b1 - pc;
  Serial.print("balance= ");
//   Serial.print("\t");
  Serial.println(bal);
  Serial.println("parked on 13/04/2022 at 10:00");
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  /*sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+919354936861\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  sim800l.print("SIM800l is working");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();*/
  Serial.println("Text Sent.");
  
  delay(500);
}

