#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

const int buzzerPin = 7;  // Buzzer connected to Pin 7
const int alarmHour = 9;  // Set to match your test time
const int alarmMinute = 53; // Set to match your test time

void setup() {
  Serial.begin(9600);
  Wire.begin();

  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW); // Ensure buzzer is OFF at start

  if (!rtc.begin()) {
    Serial.println("RTC not found! Check wiring.");
    while (1);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now(); // Get current time from RTC

  // Display Time in Serial Monitor
  Serial.print("Current Time: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.print(now.second());
  Serial.println();

  // Check if it's time for the alarm
  if (now.hour() == alarmHour && now.minute() == alarmMinute && now.second() == 0) {
    Serial.println("ALARM! Buzzer ON!");
    tone(buzzerPin, 10000); // Generate sound at 1000 Hz
    delay(10000);  // Keep buzzer ON for 5 seconds
    noTone(buzzerPin);  // Turn OFF buzzer
    Serial.println("Buzzer OFF");
  }

  delay(1000); // Update every second
}
