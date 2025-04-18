# 🌬️ Air Quality Monitoring System 🌡️

## 📝 Project Overview

Welcome to the **Air Quality Monitoring System!** 🎉  
This IoT-powered project uses an **ESP8266 NodeMCU** to monitor:

- 🌡️ Temperature  
- 💧 Humidity  
- 🏭 Air Quality  

**Real-time data is sent to:**

- 📱 **Blynk** for live visualization  
- 📊 **ThingSpeak** for data logging  
- 📩 **Telegram** for instant alerts when thresholds are crossed

Stay informed about your environment and take action when conditions turn unfavorable! 🚨

---

## ✨ Features

- 🌟 Real-time tracking of temperature, humidity, and air quality  
- 📱 View data instantly on the **Blynk mobile app**  
- 📈 Log and analyze historical data on **ThingSpeak**  
- 🔔 Get **Telegram alerts** for extreme conditions (e.g., high temperature, humidity, or poor air quality)  
- ⚙️ Customizable thresholds for alerts  
- 📡 WiFi-enabled with ESP8266 for seamless connectivity  

---

## 🛠️ Hardware Requirements

To build this project, you'll need:

- 🖥️ ESP8266 NodeMCU  
- 🌡️ DHT11 Temperature & Humidity Sensor  
- 🏭 MQ135 Air Quality Sensor  
- 🔌 Jumper Wires  
- 🍞 Breadboard (optional)  
- 🔋 USB Cable for programming and power  

---

## 💻 Software Requirements

- 🖌️ **Arduino IDE**
- 📦 **ESP8266 Board Support**  
  Add via Boards Manager:  
  `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
  
- 📚 **Libraries:**
  - `Blynk` (for IoT integration)
  - `ESP8266WiFi` (for WiFi connectivity)
  - `WiFiClientSecure` (for secure connections)
  - `UniversalTelegramBot` (for Telegram alerts)
  - `DHT` sensor library (for DHT11)

---

## 🚀 Installation Guide

### 1. Set Up the Hardware 🛠️

- Connect the DHT11 sensor to **pin D2**
- Connect the MQ135 sensor to **analog pin A0**
- Ensure proper **3.3V/5V** and **GND** connections

### 2. Configure the Software 💾

- Install the **Arduino IDE**
- Add ESP8266 board support to Arduino IDE
- Install the required libraries via the Library Manager:
  - `Blynk`
  - `ESP8266WiFi`
  - `WiFiClientSecure`
  - `UniversalTelegramBot`
  - `DHT`

### 3. Customize the Code ✍️

- Clone or download this repository
- Open `Air_Quality_Monitoring_System.ino` in Arduino IDE
- Update the following:
  - 📡 WiFi credentials: `ssid`, `password`
  - 🔑 Blynk credentials: `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, `BLYNK_AUTH_TOKEN`
  - 🤖 Telegram: `BOTtoken`, `CHAT_ID`
  - 📊 ThingSpeak: `apiKey`
  - ⚠️ Thresholds (optional): `tempThreshold`, `humidThreshold`, `airQualityThreshold`

### 4. Upload the Code 🚀

- Connect the NodeMCU via USB
- Select **NodeMCU 1.0 (ESP-12E Module)** and correct port
- Click **Upload** to flash the code

---

## 📱 How to Use

1. 🔌 Power up the NodeMCU
2. 📡 The system connects to WiFi and starts collecting sensor data
3. 📊 Monitor data in real-time:
   - Open **Blynk App** to view:
     - 🌡️ Temperature → `V0`
     - 💧 Humidity → `V1`
     - 🏭 Air Quality → `V2`
   - Visit **ThingSpeak** to see logged data (`fields 1`, `2`, `3`)
4. 🔔 Receive **Telegram Alerts** when:
   - 🌡️ Temperature > `28°C`
   - 💧 Humidity > `75%`
   - 🏭 Air Quality Index > `100`

🖥️ Use the **Serial Monitor** at `115200 baud` for debugging and logs

---

## 📂 Project Structure


📚 Ensure required libraries are installed in Arduino IDE

---

## 🤝 Contributing

We love contributions! 💖  
To contribute:

1. 🍴 Fork the repository  
2. 🌿 Create a new branch:  
   `git checkout -b feature-branch`
3. ✍️ Make changes and commit:  
   `git commit -m "Add feature"`
4. 🚀 Push to the branch:  
   `git push origin feature-branch`
5. 📬 Submit a Pull Request

Please keep code clean, commented, and consistent with the existing style 🙌

---

## 📜 License

This project is licensed under the **MIT License**.  
See the [LICENSE](LICENSE) file for details. 📄

---

## 📩 Contact

Got questions or ideas? Reach out! 🚀

- Open an issue on GitHub 🐛  


---

## 🙌 Acknowledgments

Big thanks to:

- **Blynk** for an awesome IoT platform 🌐  
- **ThingSpeak** for data logging 📊  
- **UniversalTelegramBot** for Telegram magic 🤖  

---

🌟 **Happy Monitoring!** 🌟
