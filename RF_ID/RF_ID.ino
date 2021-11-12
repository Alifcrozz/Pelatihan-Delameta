//Download dan masukan Library MFRC522
#include <SPI.h>
#include <MFRC522.h>
//Inisialisasi pembuatan variable
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

int buzz = 5; 
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 SPI.begin(); // Initiate SPI bus
 mfrc522.PCD_Init(); // Initiate MFRC522
 pinMode(buzz, OUTPUT);
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
 // Select one of the cards
 if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
 
 //Show UID on serial monitor
 Serial.print("UID tag :");
 String content= "";
 byte letter;
 for (byte i = 0; i < mfrc522.uid.size; i++) 
 {
 Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : "");
 Serial.print(mfrc522.uid.uidByte[i], HEX);
 content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : ""));
 content.concat(String(mfrc522.uid.uidByte[i], HEX));
 }
 Serial.println();
 Serial.print("Message : ");
 content.toUpperCase();
 if (content == "2AA5B715") //Sesuaikan dengan ID kartu anda
 {
 Serial.println("Selamat datang Agus Wawan!!!");
 ok();
 delay(2000);
 }
 else if (content == "1A 0CE980") //Sesuaikan dengan ID kartu anda
 {
 Serial.println("Selamat datang Budi Setiadi!!!");
 ok();
 delay(2000);
 }
 else{
 Serial.println("Kartu Belum Terdaftar!");
 gagal();
 }
 Serial.println("Tempelkan Kartu!");
 delay(500); //Jeda waktu perulagan seama 500 mili detik
}

void ok() {
   digitalWrite(buzz,HIGH);
 delay(100);
 digitalWrite(buzz,LOW);
 delay(100);
 digitalWrite(buzz,HIGH);
 delay(100);
 digitalWrite(buzz,LOW);
  }
void gagal() {
 digitalWrite(buzz, HIGH);
 delay(1000);
 digitalWrite(buzz,LOW);
}
