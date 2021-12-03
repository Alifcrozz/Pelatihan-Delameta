#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspUdp.h>
#include "SoftwareSerial.h"
#include <PubSubClient.h>

int ledR = 6;
int ledY = 5;
int ledG = 4;
int ldr  = 7;

char ssid[] = "Hotspot"; // your network SSID (name)
char pass[] = "passwordhotspotnya1"; // your network password
int status = WL_IDLE_STATUS; // the Wifi radio's status
unsigned long lastSend;

// Initialize the Ethernet client object
WiFiEspClient espClient;
PubSubClient client(espClient);

SoftwareSerial Serialx(2, 3); // RX, TX   //ESP8266 RX,TX connected to these pins

void setup() {

  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  // initialize serial for debugging
  Serial.begin(115200);
  // initialize serial for ESP module
  Serialx.begin(9600);
  // initialize ESP module
  WiFi.init(&Serialx);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
    lastSend = 0;
  }

  // you're connected now, so print out the data
  Serial.println("You're connected to the network");

  //connect to MQTT server
  client.setServer("192.168.117.241", 1883);
  client.setCallback(callback);
}

//print any message received for subscribed topic
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Pesan diterima [");
  Serial.print(topic);
  Serial.println("] ");
  //==============================================================
  if (strcmp(topic, "dzikry1602/lampuM") == 0) //Membandingkan 2 buah String
  {
    for (int i = 0; i < length; i++) {
      char receivedChar = (char)payload[i];
      if (receivedChar == '1') {
        //Jalankan Perintah1
        Serial.println("JALANKAN PERINTAH 1");
        digitalWrite(ledR, HIGH);
      }
      if (receivedChar == '0') {
        //Jalankan Perintah0
        Serial.println("JALANKAN PERINTAH 0");
        digitalWrite(ledR, LOW);
      }
    }
  }
  //==============================================================
  if (strcmp(topic, "dzikry1602/lampuK") == 0) //Membandingkan 2 buah String
  {
    for (int i = 0; i < length; i++) {
      char receivedChar = (char)payload[i];
      if (receivedChar == '1') {
        //Jalankan Perintah1
        Serial.println("JALANKAN PERINTAH 1");
        digitalWrite(ledY, HIGH);
      }
      if (receivedChar == '0') {
        //Jalankan Perintah0
        Serial.println("JALANKAN PERINTAH 0");
        digitalWrite(ledY, LOW);
      }
    }
  }

  if (strcmp(topic, "dzikry1602/lampuH") == 0) //Membandingkan 2 buah String
  {
    for (int i = 0; i < length; i++) {
      char receivedChar = (char)payload[i];
      if (receivedChar == '1') {
        //Jalankan Perintah1
        Serial.println("JALANKAN PERINTAH 1");
        digitalWrite(ledG, HIGH);
      }
      if (receivedChar == '0') {
        //Jalankan Perintah0
        Serial.println("JALANKAN PERINTAH 0");
        digitalWrite(ledG, LOW);
      }
    }
  }
}

void pushdata() {
  //Ambil Data Baca Sensor
  //int bacaflame = random(10, 100);
  int bacaldr = analogRead(ldr);

  //POST TO SERIAL
  //Serial.print("Sensor Flame: "); Serial.print(bacaflame);
  Serial.print("Sensor LDR: "); Serial.print(bacaldr);
  Serial.println();

  //POST TO MQTT
  //client.publish("dzikry1602/Suhu", dtostrf(datax, 6, 2, msgBuffer)); //Convert to String
  //client.publish("asayuti1602/flame", String(bacaflame).c_str()); //Convert to String
  client.publish("dzikry1602/ldr", String(bacaldr).c_str()); //Convert to String
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!client.connected()) {
    reconnect();
  }
  if ( millis() - lastSend > 1000 ) { // Update and send only after 1 seconds
    pushdata();
    lastSend = millis();
  }
  client.loop();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect, just a name to identify the client
    if (client.connect("BudiHanduk")) {
      Serial.println("connected");

      //client.publish("outpic","Hello World");
      client.subscribe("dzikry1602/lampuM", 0);
      client.subscribe("dzikry1602/lampuK", 0);
      client.subscribe("dzikry1602/lampuH", 0);

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
