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
  This is the Reading-RSSI program for ESP32-S2 Mini board of my "second" 
  Measure-distance-using-RSSI project
*/

#include <Arduino.h> // If you are using Arduino IDE, delete this line
#include <WiFi.h>

#define SAMPLES 100

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.begin(115200);

  // Kết nối đến AP
  WiFi.begin("ESP32_AP", "12345678");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Đang kết nối...");
  }

  Serial.println("Đã kết nối!");
}

void loop() {
  digitalWrite(BUILTIN_LED, HIGH);

  long rssiSum = 0;
  long rssiMax = LONG_MIN;
  long rssiMin = LONG_MAX;

  for (int i = 0; i < SAMPLES; i++) {
    long rssi = WiFi.RSSI();
    rssiSum += rssi;
    rssiMax = max(rssiMax, rssi);
    rssiMin = min(rssiMin, rssi);
    delay(10);
  }

  float rssiAvg = (float) rssiSum / SAMPLES;

  Serial.println("================================================");
  Serial.println("RSSI nhỏ nhất | RSSI trung bình | RSSI lớn nhất ");
  Serial.print(rssiMin);
  Serial.print(" dBm       ");
  Serial.print(rssiAvg);
  Serial.print(" dBm       ");
  Serial.print(rssiMax);
  Serial.println(" dBm");
  Serial.print(">RSSIAvg:");
  Serial.println(rssiAvg);
  delay(1);

  digitalWrite(BUILTIN_LED, LOW);
}


