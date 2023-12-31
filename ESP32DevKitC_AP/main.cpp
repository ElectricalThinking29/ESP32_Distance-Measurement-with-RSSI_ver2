#include <Arduino.h>
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
