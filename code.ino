#include <WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

unsigned long channelID = YOUR_CHANNEL_ID;
const char* writeAPIKey = "YOUR_WRITE_API_KEY";

WiFiClient client;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");

  ThingSpeak.begin(client);
}

void loop() {

  int waterLevel = random(20, 100);

  ThingSpeak.setField(1, waterLevel);

  int status = ThingSpeak.writeFields(channelID, writeAPIKey);

  Serial.print("Water Level: ");
  Serial.println(waterLevel);

  Serial.print("Status: ");
  Serial.println(status);

  delay(20000);
}
