#include <WiFi.h>
#include "PubSubClient.h"
#define ECHO 2
#define TRIG 15
#define L LOW
#define H HIGH
#define ORG "b6kdov"
#define DEVICE_TYPE "ESP32"
#define DEVICE_ID "24_0A_C4_00_01_10"
#define TOKEN "G8F*JZcTgYJl6h!17W"

int distance = 0;
char SSID[] = "Wokwi-GUEST";
char PASSWORD[] = "";

char server[] = ORG ".messaging.internetofthings.ibmcloud.com";
char publishTopic[] = "iot-2/evt/update/fmt/json";
char topic[] = "iot-2/cmd/update/fmt/Number";
char AUTH[] = "use-token-auth";
char token[] = "G8F*JZcTgYJl6h!17W";
char CLIENTID[] = "d:"ORG":"DEVICE_TYPE":"DEVICE_ID;

WiFiClient wifiClient;
PubSubClient client(server, 1883, wifiClient);

void setup() 
{
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  Serial.print("Trying to connect to WiFi.");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected to ");
  Serial.print(SSID);
  Serial.print("(IP Address: ");
  Serial.print(WiFi.localIP());
  Serial.println(")");

  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());

  mqttConnect();
}

float readDistanceValue()
{
 digitalWrite(TRIG, L); 
 delayMicroseconds(2);
 digitalWrite(TRIG, H);
 delayMicroseconds(10);
 digitalWrite(TRIG, L);
 distance = pulseIn(ECHO, HIGH) * 0.034 / 2;
 return distance;
}

void mqttConnect()
{
  if (!client.connected())
  {
    Serial.print("Client trying to reconnect to ");
    Serial.println(server);
    while (!client.connect( CLIENTID, AUTH, TOKEN))
    {
      Serial.print(".");
      delay(500);
    }
    Serial.println();
    if (client.subscribe(topic))
    {
      Serial.println("Subscription Success!");
    }
    else
    {
      Serial.println("Subscription Failed!");
    }
  }
}

void loop() {
  float currDistance = readDistanceValue();
  Serial.println("Distance: " + String(currDistance, 2) + "m");
  Serial.println("-----");

  if (currDistance < 100)
  {
    String payload = "{\"Alert distance\":";
    payload += currDistance;
    payload += "}";
    Serial.print("Payload: ");
    Serial.println(payload);

    if (client.publish(publishTopic, (char *) payload.c_str()))
    {
      Serial.println("Published Successfully!");
    }
    else
    {
      Serial.println("Publish Failed!");
    }

  }
  else
  {
    String payload = "{\"Distance\":";
    payload += currDistance;
    payload += "}";
    Serial.print("Payload: ");
    Serial.println(payload);

    if (client.publish(publishTopic, (char *) payload.c_str()))
    {
      Serial.println("Published Successfully!");
    }
    else
    {
      Serial.println("Publish Failed!");
    }
  }

  if (!client.loop())
  {
    mqttConnect();
  }
  delay(10000);
}