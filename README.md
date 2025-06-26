# 💊 Smart Medicine Reminder Box

An Arduino-based smart pillbox system designed to remind patients or elderly individuals to take their medicine on time using buzzers, LEDs, and a real-time clock (RTC). Perfect for healthcare automation projects.

---

## 📦 Features

- ⏰ Real-time medicine reminders using a DS3231 RTC module  
- 🔔 Audible alerts via buzzer at scheduled times  
- 💡 LED indicators for each pill compartment  
- 🧠 Push-button acknowledgment to reset reminders  
- 🔋 USB or battery-powered for portability  

---

## 🧰 Components Used

| Emoji | Component                | Qty | Notes                                  |
|:-----:|--------------------------|:---:|----------------------------------------|
| 🔌    | Arduino Uno or Nano      | 1   | 5 V logic, 16 MHz                      |
| 🕒    | DS3231 RTC Module        | 1   | Accurate real-time clock               |
| 🔔    | Active Buzzer            | 1   | 5 V buzzer                             |
| 💡    | LEDs                     | 3–4 | One per compartment                    |
| 🔘    | Push Buttons             | 3–4 | Momentary, for acknowledgment          |
| 📏    | Resistors (220 Ω)        | As needed | For LED current limiting          |
| 🌉    | Jumper Wires & Breadboard| Set | For prototyping                        |
| 📦    | Pill Box Enclosure       | 1   | Custom or off-the-shelf                |

---

## 🔌 Wiring Overview

- **RTC (DS3231)**  
  - SDA → A4 (Uno) or D4 (Nano)  
  - SCL → A5 (Uno) or D5 (Nano)  
- **Buzzer** → D6  
- **LEDs** → D7, D8, D9, D10 (one per compartment)  
- **Buttons** → D2, D3, D4, D5 (use `INPUT_PULLUP` or external pull-downs)  
- **Power** → 5 V and GND shared among all modules  

> Ensure all grounds (RTC, Arduino, buzzer, LEDs) are common.

---

## 💡 How It Works

1. **Schedule Setup**  
   - Define pill times in the code (e.g. 09:00, 14:00, 20:00).  
2. **Time Tracking**  
   - The DS3231 RTC maintains accurate time even when powered off.  
3. **Alert Trigger**  
   - When the current time matches a scheduled dose:  
     - Buzzer sounds and corresponding LED lights.  
4. **Acknowledgment**  
   - Press the associated button to turn off LED and buzzer.  
   - Code prevents re-triggering for that interval.

---



