# Air-Quality-Monitoring
An IoT-based Air Quality Monitoring System using NodeMCU ESP8266. It tracks temperature, humidity (DHT11), and air quality (MQ135), sending real-time data to Blynk and ThingSpeak, with Telegram alerts for threshold breaches. Ideal for remote environmental monitoring and alerting.


Absolutely! Here's a well-structured `README.md` file for your GitHub repository:

---

```markdown
# 🌍 Air Quality Monitoring System using NodeMCU (ESP8266)

An IoT-based Air Quality Monitoring System built with NodeMCU (ESP8266). It reads real-time environmental data using DHT11 (Temperature & Humidity) and MQ135 (Air Quality) sensors, and integrates with Blynk, ThingSpeak, and Telegram to log data and send alerts.

---

## 📦 Features

- 🌡️ Real-time temperature and humidity monitoring
- 🏭 Air quality sensing using MQ135 sensor
- 📲 Live data dashboard on Blynk app
- ☁️ Cloud data logging via ThingSpeak
- 📩 Telegram alerts for threshold breaches (Temp, Humidity, Air Quality)
- ⚠️ Customizable thresholds and notifications

---

## 🛠️ Hardware Requirements

- NodeMCU ESP8266
- DHT11 Temperature & Humidity Sensor
- MQ135 Air Quality Sensor
- Jumper Wires
- Breadboard
- WiFi Connection

---

## 🔌 Circuit Diagram

| Component | NodeMCU Pin |
|----------|-------------|
| DHT11    | D2          |
| MQ135    | A0          |
| VCC/GND  | 3.3V / GND  |

*You can add a Fritzing diagram here if available.*

---

## 🧰 Libraries Used

Make sure to install the following libraries in the Arduino IDE:

- `ESP8266WiFi`
- `BlynkSimpleEsp8266`
- `WiFiClientSecure`
- `UniversalTelegramBot`
- `DHT`

---

## 🔧 Setup Instructions

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/air-quality-monitoring-system.git
   ```
2. Open the `.ino` file in Arduino IDE
3. Replace the following with your credentials:
   - WiFi SSID and Password
   - Blynk Auth Token
   - Telegram Bot Token and Chat ID
   - ThingSpeak API Key
4. Upload the code to NodeMCU
5. Open Serial Monitor to check the readings and system status

---

## 📱 Blynk Virtual Pins

| Sensor        | Blynk Pin |
|---------------|-----------|
| Temperature   | V0        |
| Humidity      | V1        |
| Air Quality   | V2        |

---

## 📊 Cloud Integration

- **Blynk App**: Real-time display using virtual pins
- **ThingSpeak**: Sends data to fields 1–3 every 5 seconds
- **Telegram**: Sends alert messages for high readings

---


## 📌 To-Do / Future Improvements

- Add OLED display for local readings
- Implement air quality index (AQI) conversion
- Add additional sensors (e.g., CO2, PM2.5)
- Power optimization for long-term deployment

---

## 📜 License

This project is open-source and available under the [MIT License](LICENSE).

---

## 💬 Contact

Feel free to reach out for questions or suggestions!

```
