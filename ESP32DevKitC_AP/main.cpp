/*** MY CHANNEL ***
If you can, please support me on my Youtube's channel:

    www.youtube.com/@TheElectricTHINK

by hitting like, share and subscribe's buttons to my videos.

*/

/*** LICENSE ***

Copyright 2023 @ElectricalThinking29

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

/*** DISCRIPTION ***
  This is the program for ESP32-DevKitC board of my "second" 
  Measure-distance-using-RSSI project.
*/

#include <Arduino.h> // If you use Arduino IDE or something else, delete this line
#include <WiFi.h>

#define LED_BUILTIN 2

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);

  // Cài đặt AP với SSID và mật khẩu
  WiFi.softAP("ESP32_AP", "12345678");

  // Cài đặt mức công suất đầu ra cố định 
  WiFi.setTxPower(WIFI_POWER_19_5dBm);

  Serial.println("AP đã được cài đặt!");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
