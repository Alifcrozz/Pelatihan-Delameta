#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspUdp.h>
#include "SoftwareSerial.h"
#include <PubSubClient.h>
#include <NewPing.h>

int lampuM  = 4;
int lampuK  = 5;
int lampuH  = 6;
int echo    = 7;
int trigger = 8;
int ldr     = A0;
int batas   = 400;

char ssid[] = "Hotspot"; // your network SSID (name)
char pass[] = "passwordhotspotnya1"; // your network password
int status = WL_IDLE_STATUS; // the Wifi radio's status
unsigned long lastSend;

// Initialize the Ethernet client object
WiFiEspClient espClient;
PubSubClient client(espClient);

SoftwareSerial Serialx(2,3); // RX, TX   //ESP8266 RX,TX connected to these pins
NewPing cm(echo, trigger, batas);

void setup() {
// initialize serial for debugging
Serial.begin(115200);
// initialize serial for ESP module
Serialx.begin(9600);
// initialize ESP module
WiFi.init(&Serialx);

pinMode(lampuM, OUTPUT);
pinMode(lampuK, OUTPUT);
pinMode(lampuH, OUTPUT);

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
client.setServer("broker.hivemq.com", 1883);
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
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("Nyalakan Lampu Merah");
       digitalWrite(lampuM, HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("Matikan Lampu Merah");
       digitalWrite(lampuM, LOW);
    }
  }
  }
  //==============================================================
  
}

void pushdata(){
  //Ambil Data / Baca Sensor
   int BacaJarak = cm.ping_cm();
   int BacaLDR   = analogRead(ldr);
  //POST TO SERIAL
  Serial.print("Ultrasonic :");Serial.print(BacaJarak); Serial.print(" cm || "); Serial.print("LDR :");Serial.print(BacaLDR);
  Serial.println();
  
  //POST TO MQTT
  client.publish("dzikry1602/ultrasonic", String(BacaJarak).c_str() ); //Convert to String 
  client.publish("dzikry1602/ldr", String(BacaLDR).c_str() ); //Convert to String 
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
if (client.connect("BonnieMichaela63")) {
Serial.println("connected");

//client.publish("outpic","Hello World");
client.subscribe("dzikry1602/lampuM",0);
client.subscribe("dzikry1602/lampuK",0);
client.subscribe("dzikry1602/lampuH",0);

} else {
  Serial.print("failed, rc=");
  Serial.print(client.state());
  Serial.println(" try again in 3 seconds");
  // Wait 5 seconds before retrying
  delay(3000);
}
}
}
