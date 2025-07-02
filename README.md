🩺 Smart Wireless Blood Pressure & Heart Rate Monitoring System
This project demonstrates a portable, wireless health monitoring system using an ESP32 microcontroller and the MAX30102 pulse sensor. It measures heart rate in real-time and transmits the data to a mobile device via Bluetooth for live visualization. Powered by 3× 3.7V lithium-ion batteries and regulated through an LM2596 buck converter, this low-cost, battery-operated device is ideal for home healthcare, remote patient monitoring, and wearable health tech applications.

✅ Features
💓 Heartbeat detection using MAX30102 (IR sensor)

📲 Live heart rate display on mobile phone via Bluetooth

🔋 Battery powered (3 × 3.7V cells) with LM2596 voltage regulation

📊 Real-time data output in Timestamp(ms), BPM CSV format

🔌 Dual switch-controlled power flow for safety and energy efficiency

🛠️ Components Used
ESP32 Dev Board

MAX30102 Pulse Oximeter Sensor

LM2596 Buck Converter

3 × 3.7V Li-ion Batteries

2 x Power Control Switches

Jumper Wires, Sockets, etc.

🔁 Data Flow
arduino
Copy
Edit
MAX30102 → I2C → ESP32 → Bluetooth Serial → Mobile Terminal
🧠 Software Stack
Arduino IDE

MAX30105 & heartRate libraries

BluetoothSerial library for ESP32

📷 Live Demo
(Add images or video links here if available)

📦 Output Format Example
scss
Copy
Edit
Timestamp(ms),BPM
54200,76
54320,75
54440,77
📚 Future Scope
Add SpO2 and body temperature integration

Mobile app dashboard via Wi-Fi or MQTT

Automatic emergency alerts on abnormal vitals

