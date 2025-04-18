#define BLYNK_TEMPLATE_ID "TMPL3OH51YesT"
#define BLYNK_TEMPLATE_NAME "Air Quality Monitoring System"
#define BLYNK_AUTH_TOKEN "1Bl6loNDWH5DndtrMdO_ydo5aUQCmsR4"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include "DHT.h"

// WiFi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Telegram Bot
#define BOTtoken "YOUR_TELEGRAM_BOT_TOKEN"
#define CHAT_ID "YOUR_TELEGRAM_CHAT_ID"

// ThingSpeak
String apiKey = "YOUR_THINGSPEAK_API_KEY";
const char* server = "api.thingspeak.com";


// Sensor Setup
#define DHTPIN D2
#define DHTTYPE DHT11
#define MQ135_PIN A0

DHT dht(DHTPIN, DHTTYPE);
WiFiClientSecure telegramClient;
WiFiClient thingspeakClient;
UniversalTelegramBot bot(BOTtoken, telegramClient);

// Blynk Auth
char auth[] = BLYNK_AUTH_TOKEN;

// Thresholds
// Update Theresholds as per your needs

float tempThreshold = 28.0;
float humidThreshold = 75.0;
int airQualityThreshold = 100;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("🚀 NodeMCU Starting...");

  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("🔌 Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Telegram SSL
  telegramClient.setInsecure();

  // Start Blynk
  Blynk.begin(auth, ssid, password);
}

void loop() {
  Blynk.run();
  sendSensorData();
  delay(5000); // 5 seconds delay between readings
}

void sendSensorData() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int airQuality = analogRead(MQ135_PIN);

  if (isnan(h) || isnan(t)) {
    Serial.println("⚠️ Failed to read from DHT sensor!");
    return;
  }

  Serial.print("🌡 Temp: "); Serial.print(t);
  Serial.print(" °C | 💧 Humidity: "); Serial.print(h);
  Serial.print(" % | 🏭 Air Quality: "); Serial.println(airQuality);

  // Send to Blynk App
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V2, airQuality);

  // Send to ThingSpeak
  if (thingspeakClient.connect(server, 80)) {
    String postStr = "api_key=" + apiKey;
    postStr += "&field1=" + String(t);
    postStr += "&field2=" + String(h);
    postStr += "&field3=" + String(airQuality);

    thingspeakClient.print("POST /update HTTP/1.1\n");
    thingspeakClient.print("Host: api.thingspeak.com\n");
    thingspeakClient.print("Connection: close\n");
    thingspeakClient.print("Content-Type: application/x-www-form-urlencoded\n");
    thingspeakClient.print("Content-Length: " + String(postStr.length()) + "\n\n");
    thingspeakClient.print(postStr);
    thingspeakClient.stop();

    Serial.println("📡 Data sent to ThingSpeak.");
  } else {
    Serial.println("❌ ThingSpeak connection failed.");
  }

  // Alerts
  if (t > tempThreshold) {
    String title = "🌡 High Temperature Alert!";
    String body = "Temp: " + String(t) + "°C\n⚠️ *Precaution:* Stay hydrated and avoid going out during peak heat.";
    sendTelegramAlert(title, body);
    Blynk.logEvent("TEMP", "🔥 High Temperature: " + String(t) + "°C");
  }

  if (h > humidThreshold) {
    String title = "💧 High Humidity Alert!";
    String body = "Humidity: " + String(h) + "%\n⚠️ *Precaution:* Use a dehumidifier or ventilation. Stay cool.";
    sendTelegramAlert(title, body);
    Blynk.logEvent("HUMI", "💧 High Humidity: " + String(h) + "%");
  }

  if (airQuality > airQualityThreshold) {
    String title = "🏭 Poor Air Quality Alert!";
    String body = "Air Quality Index: " + String(airQuality) + "\n⚠️ *Precaution:* Wear a mask, avoid outdoor activities, and use an air purifier.";
    sendTelegramAlert(title, body);
    Blynk.logEvent("AIR", "⚠️ Poor Air Quality: AQI " + String(airQuality));
  }
}

void sendTelegramAlert(String title, String body) {
  String message = "🚨 *" + title + "*\n" + body;

  bool sent = bot.sendMessage(CHAT_ID, message, "Markdown");
  if (sent) {
    Serial.println("✅ Telegram alert sent: " + title);
  } else {
    Serial.println("❌ Telegram alert failed: " + title);
  }
}
