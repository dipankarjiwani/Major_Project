

uint8_t trigPin1 = D2;
uint8_t echoPin1 = D1;

uint8_t trigPin2 = D5;
uint8_t echoPin2 = D6;
uint8_t ledpin1=D0;
uint8_t ledpin2=D3;
long duration;
int distance1,distance2;

//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "https://smartdrawer-ff798.firebaseio.com/"
#define FIREBASE_AUTH "WBZRGYbSF7LBXhyE0wmpFqe1PTDA0orwu4AHlCil"
#define WIFI_SSID "realme X"
#define WIFI_PASSWORD "12345678e"

//Define FirebaseESP8266 data object
FirebaseData firebaseData;

FirebaseJson json;

void printResult(FirebaseData &data);


void setup()
{
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(3000);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  

  
  String path = "/UltrasonicReading";
  if (Firebase.setDouble(firebaseData,path,2))
    {
      Serial.println("------------------------------------");
      Serial.println();
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }


// defines variables
void loop() {
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin1, HIGH);
distance1= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance1);
Firebase.setDouble(firebaseData,"/Ultrasonic1Reading",distance1);

digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin2, HIGH);
distance2= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance2);
Firebase.setDouble(firebaseData,"/Ultrasonic2Reading",distance2);

String a,b; 
Firebase.getString(firebaseData,"/drawer1led",a);
Firebase.getString(firebaseData,"/drawer2led",b);
Serial.println(a);
if (a=="ON")
    {
      digitalWrite(ledpin1, HIGH);
    }
else if (b=="ON")
    {
      digitalWrite(ledpin2,HIGH);
    }
else
  {
    digitalWrite(ledpin1, LOW);
    digitalWrite(ledpin2, LOW);
  }
}
