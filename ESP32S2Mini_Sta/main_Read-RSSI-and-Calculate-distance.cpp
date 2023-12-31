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
  This is the Reading-RSSI-&-Calculate-distance program for ESP32-DevKitC 
  board of my "second" Measure-distance-using-RSSI project.
*/

#include <Arduino.h> // If you are using Arduino IDE, delete this line
#include <WiFi.h>
#include <cmath> // Add library for pow function
#define SAMPLES 100

float measuredPower = -59.812; // dBm
int n = 1.7343;

void setup()
{
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.begin(115200);

  // Kết nối đến AP
  WiFi.begin("ESP32_AP", "12345678");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Đang kết nối...");
  }

  Serial.println("Đã kết nối!");
}

void loop()
{
  digitalWrite(BUILTIN_LED, HIGH);

  long rssiSum = 0;
  long rssiMax = LONG_MIN;
  long rssiMin = LONG_MAX;

  for (int i = 0; i < SAMPLES; i++)
  {
    long rssi = WiFi.RSSI();
    rssiSum += rssi;
    delay(10);
  }

  float rssiAvg = (float)rssiSum / SAMPLES;
  double distanceAvg = pow(10.0, (measuredPower - rssiAvg) / (10 * n));

  Serial.println("==========================================");
  Serial.println("RSSI trung bình | Khoảng cách trung bình");
  Serial.print(rssiAvg);
  Serial.print(" dBm        ");
  Serial.print(distanceAvg, 4);
  Serial.println(" m");
  Serial.print(">Distance(m):");
  Serial.println(distanceAvg);
  delay(1);

  digitalWrite(BUILTIN_LED, LOW);
}
