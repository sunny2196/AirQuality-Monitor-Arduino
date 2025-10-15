Smart Indoor Air Quality Monitor 🚦
A real-time, affordable indoor air quality monitor using Arduino and C — LCD display, RGB LED, buzzer alerts, and cloud-ready code.

🚀 Overview
Indoor air pollution is a significant problem—but accessible, affordable monitoring is missing for most homes/offices. This project leverages Arduino + procedural C to deliver a modular, low-cost, professional solution supporting both hardware and simulation.

PPM air quality readings (sensor or potentiometer)

Color-coded alerts: Green (Good), Yellow/Blue (Moderate), Red (Poor/Danger)

Buzzer for critical levels

LCD output and manual-check button

Tinkercad simulation for virtual demo

Open hardware and open source

📸 Demo / Circuit
🛠️ Features
Real-time Air Quality Measurement

Multi-level Alerts: Visual (RGB), Audio (buzzer), LCD status

Manual check: User button to instantly update readings

Portable and extendable: Easy to add IoT cloud, logging, mobile notifications

Documentation Included: Report, BOM, code, and simulation instructions

⚡ Quick Start
1. Hardware/Simulation Requirements
Arduino Uno R3

MQ135 Gas Sensor or Potentiometer (for simulation)

RGB LED + 3x 220Ω resistors

16x2 LCD display + potentiometer

Buzzer, pushbutton, breadboard, jumper wires

2. Building the Circuit
See images/circuit-diagram.jpg for full wiring.
In Tinkercad, use a potentiometer as analog input to simulate the gas sensor.

3. Code Upload
Open air_quality_monitor.ino

Upload to Arduino (or paste into Tinkercad Code)

Start simulation / power on

🖥️ How It Works
Green: Air quality is good

Yellow/Blue: Moderate, caution (mixture on RGB)

Red & Buzzer: Poor/dangerous, take action

PPM (parts per million) estimated from sensor or potentiometer analog value

Press button for instant manual reading

📊 Results
LCD shows [PPM: value] [Status: GOOD/MODERATE/POOR/DANGER!]

RGB LED changes color based on threshold

Buzzer sounds for dangerous air quality

System is modular and easy for further extension or educational demos

📚 Documentation
Project Report PDF

Bill of Materials (BOM)

Sample code with comments

Simulation Instructions

Screenshots/Step Photos

🌱 Applications
Smart home air quality

Schools and STEM education labs

Condition monitoring for offices/classrooms

DIY/Prototyping for startups and IoT projects

💡 Future Roadmap
Add WiFi/IoT connectivity for cloud/data logging

Multi-sensor support (temperature, humidity, CO2)

Android/iOS notification integration

Compact PCB version

👨‍💻 Contributing
Contributions, pull requests, and forks welcome! See CONTRIBUTING.md.

📢 Contact & Credits
Created by K Mounesh
Email: kaliyugiheart@gmail.com
University: Amrita Vishwa Vidyapeetham, Nagercoil
Video Link: https://drive.google.com/file/d/1wh1Ux5vF5jtgeIOV-C2YZmSn5ClbKjZr/view?usp=drive_link

Images, report, and code © 2025
