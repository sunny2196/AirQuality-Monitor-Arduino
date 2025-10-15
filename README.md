#  Smart Indoor Air Quality Monitoring System using Arduino

This project is a real-time indoor air quality (IAQ) monitoring system developed using an Arduino Uno and programmed in C. It integrates a gas sensor, an LCD display, and an RGB LED to provide multi-stage visual and audible alerts based on air quality. The entire system is simulated in the Tinkercad Circuits environment.

---

### ✨ Features

- **Real-Time Monitoring:** Continuously reads data from the MQ135 gas sensor.
- **Live Data Display:** Shows the current air quality in Parts Per Million (PPM) on a 16x2 LCD screen.
- **Multi-Stage Visual Alerts:** An RGB LED provides instant, color-coded status updates:
  - 🟢 **Green:** Good
  - 🔵 **Blue:** Moderate
  - 🔴 **Red:** Poor / Danger
- **Audible Alarm:** A buzzer sounds an alarm when air quality reaches critical levels.
- **Manual Override:** A pushbutton allows for immediate, on-demand sensor readings.

---

### 🛠️ Hardware & Tech Stack

- **Microcontroller:** Arduino Uno R3
- **Sensor:** MQ135 Gas Sensor
- **Display:** 16x2 LCD Display
- **Outputs:** RGB LED, Active Buzzer
- **Programming Language:** C (in Arduino IDE)
- **Simulation Environment:** Autodesk Tinkercad

---

### 🔌 Circuit Diagram

Here is the final circuit diagram for the project.

![Circuit Diagram](https://drive.google.com/file/d/1-T_g8cTJkF_gVju2XdckPLAPNu9xFjB-/view?usp=sharing)

---

### 🚀 How to Use

1.  Open the project in [Autodesk Tinkercad](https://drive.google.com/file/d/1wh1Ux5vF5jtgeIOV-C2YZmSn5ClbKjZr/view?usp=drive_link).
2.  Start the simulation.
3.  Click on the MQ135 gas sensor to bring up the simulation interface.
4.  Move the "gas cloud" or slider to change the gas concentration and observe the system's response on the LCD, LED, and buzzer.

---
