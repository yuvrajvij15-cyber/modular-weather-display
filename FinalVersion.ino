/ libraries used
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include <WiFi.h>
#include <WeatherLEDs.h>
// creating variables for each connection point for i/o devices
const int led1 = D3;
const int led2 = D5;
const int led3 = D6;
const int led4 = D8;
const int led5 = D10;
const int led6 = D12;
const int switch1 = D7;
//using custom led library to assign the pins
WeatherLEDs leds(led1,led2,led3,led4,led5,led6);
// defining variables for wifi / api access

//input your wifi and api variables used
const char* MYurl ="*****";
const char* ssid = "*****";
const char* password = "*****";
String description = "";
void setup() {
{
Serial.begin(115200);
WiFi.begin(ssid, password);
//using a while loop to see if connection is successful
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected.");
}
leds.begin();
//assigning pin for button
pinMode(switch1,INPUT_PULLUP);
}
// function to handle the retrieval of data from the api
void getHTML(const char* url) {
// checking wifi connection
if (WiFi.status() == WL_CONNECTED) {
HTTPClient http;
http.begin(url);
int httpCode = http.GET();
// checking if the HTTP website has text
if (httpCode > 0) {
String payload = http.getString();
JSONVar myObject = JSON.parse(payload);
myObject["weather"][0]["icon"];
description = (const char *)(myObject["weather"][0]["description"]); // obtaining weather description
//error handling
} else {
Serial.println("Error on HTTP request");
}
http.end();
} else {
Serial.println("Not connected to WiFi");
}
}
// custom function to make use of button
void buttoncontrol(){
// checks if button is pressed and turns all leds on if it does
if (digitalRead(switch1 == HIGH)){
Serial.println("pressed");
leds.allOn();
delay(1000);
}
//turns off led if button is released
else{
leds.allOff();
}
}
// main loop
void loop() {
buttoncontrol(); // calls button control function
getHTML(MYurl); // calls html function
leds.display(description); // uses custom library to turn on an led based on description
delay(1000); // waits 1 second before running again
}
