#include <NTPClient.h>
// change next line to use with another board/shield
#include <ESP8266WiFi.h>
//#include <WiFi.h> // for WiFi shield
//#include <WiFi101.h> // for WiFi 101 shield or MKR1000
#include <WiFiUdp.h>
#include <Metro.h>

char latchPin = D3;
char clockPin = D2;
char dataPin = D5;
char Digit1 = D4;
char Digit2 = D7;
char Digit3 = D1;
char Digit4 = D6;
int numbers[] = {0x7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0x7B};
byte blackout = 0x00;
int dt = 1;
int mt = 1;
Metro metro0 = Metro(mt);

const char *ssid     = "ashokhome";
const char *password = "A7D0A5E8CA";

unsigned long theDay = 2015560800;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup(){
  Serial.begin(115200);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(Digit1,OUTPUT);
  pinMode(Digit2,OUTPUT);
  pinMode(Digit3,OUTPUT);
  pinMode(Digit4,OUTPUT);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,B00000001);
  digitalWrite(latchPin, HIGH);
  
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    digitalWrite(Digit1,LOW);
    digitalWrite(Digit2,HIGH);
    digitalWrite(Digit3,HIGH);
    digitalWrite(Digit4,HIGH);
    delay(250);
    digitalWrite(Digit1,HIGH);
    digitalWrite(Digit2,LOW);
    digitalWrite(Digit3,HIGH);
    digitalWrite(Digit4,HIGH);
    delay(250);
    Serial.print ( "." );
    digitalWrite(Digit1,HIGH);
    digitalWrite(Digit2,HIGH);
    digitalWrite(Digit3,LOW);
    digitalWrite(Digit4,HIGH);
    delay(250);
    digitalWrite(Digit1,HIGH);
    digitalWrite(Digit2,HIGH);
    digitalWrite(Digit3,HIGH);
    digitalWrite(Digit4,LOW);
    delay(250);
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();
  unsigned long date = timeClient.getEpochTime();
  int days = (theDay-date)/86400;
  int num = days + 1;
  int first = num/1000;
  int second = num/100 - first*10;
  int third = num/10 - first*100 - second*10;
  int fourth = num - first*1000 - second*100 - third*10;
  
if (metro0.check()) {
  digitalWrite(Digit1,LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,numbers[first]);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(Digit1,HIGH);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,blackout);
  digitalWrite(latchPin, HIGH);
  digitalWrite(Digit2,LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,numbers[second]);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(Digit2,HIGH);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,blackout);
  digitalWrite(latchPin, HIGH);
  digitalWrite(Digit3,LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,numbers[third]);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(Digit3,HIGH);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,blackout);
  digitalWrite(latchPin, HIGH);
  digitalWrite(Digit4,LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,numbers[fourth]);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(Digit4,HIGH);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,blackout);
  digitalWrite(latchPin, HIGH);
  
}
  
}
