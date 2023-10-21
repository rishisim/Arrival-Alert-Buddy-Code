/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.




    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  NOTE: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32


  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

// NEED TO REPLACE , TEMPLATE ID, NAME, AUTHCODE FROM DEVICE..AND WIFI //PASSWORD


/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
#define BLYNK_TEMPLATE_NAME         "TMPxxxxxx"
#define BLYNK_AUTH_TOKEN            "TMPxxxxxx"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


/* Fill in information about Wifi where the device will be used */
char ssid[] = "****";
char pass[] = "*******";

int led = 23;
BLYNK_WRITE(V0)
{
 if(param.asInt()==1){
   digitalWrite(led, HIGH);
 }
 else{
   digitalWrite(led, LOW);
 }
}


BLYNK_CONNECTED() {
 Blynk.syncVirtual(V0);
}


void setup() {
  // Debug console
  pinMode(led, OUTPUT); // Initialise digital pin led as an output pin  
  Serial.begin(9600);
  delay(100);


  // Add WiFi connection and auto-reconnect
  WiFi.begin(ssid, pass);
  WiFi.setAutoConnect(true);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}


void loop() {
  Blynk.run();
}
