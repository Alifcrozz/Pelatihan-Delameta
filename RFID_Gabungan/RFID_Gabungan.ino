#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

String uidstring;

int buzzer=5;
int lampuM=2;
int lampuK=3;
int lampuH=4;
int infra=A0;

int kunci = 0;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instace
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  lcd.begin();
  pinMode(buzzer,OUTPUT);
  pinMode(lampuM,OUTPUT);
  pinMode(lampuK,OUTPUT);
  pinMode(lampuH,OUTPUT);
  pinMode(infra, INPUT);
  digitalWrite(lampuM, HIGH);
  SPI.begin(); // initiate SPI bus
  mfrc522.PCD_Init();  //initiate MFRC522
  masuk();
}

void loop() {
 int bacainfra = digitalRead(infra);

 
 if(mfrc522.PICC_IsNewCardPresent() and kunci==0) {
    readRFID();
    Serial.println(uidstring);
    
    if(uidstring == "2ATA5IB7P15") {
      kunci=1;
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(0,0); lcd.print("Berhasil");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("Silahkan Masuk");
      digitalWrite(lampuM, LOW);
      digitalWrite(lampuK, HIGH);
      delay(1000);
      digitalWrite(lampuK, LOW);
      delay(100);
      digitalWrite(lampuH, HIGH);
      oke();
      }
      else {
      kunci=0;
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      lcd.setCursor(0,0); lcd.print("Gagal");
      delay(1000);
      gagal();
      lcd.clear();
      delay(500);
      masuk();
       
        }
      }
  if(bacainfra==0 and kunci==1){
    kunci=0;
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(0,0); lcd.print("Sudah Lewat");
    delay(1000);
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(0,0); lcd.print("Sudah Lewat");
    delay(500);
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(0,0); lcd.print("Palang Ditutup");
    delay(500);
    digitalWrite(lampuH, LOW);
    digitalWrite(lampuM, HIGH);
    lcd.clear();
    masuk();
    }
  
}
void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //sound the buzzer when a card is read
  oke();
  //pembatas bisa di ubah sesuai keinginan,disini yang digunakan "U"
  uidstring=String(mfrc522.uid.uidByte[0], HEX)+"T"+
  String(mfrc522.uid.uidByte[1], HEX) +"I"+
  String(mfrc522.uid.uidByte[2], HEX) +"P"+
  String(mfrc522.uid.uidByte[3], HEX);
  uidstring.toUpperCase();
}
void oke(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}
void gagal(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(1000);
}

void masuk(){
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(0,0); lcd.print("Silahkan Tempel");
  lcd.setCursor(0,1); lcd.print("Kartu Anda");
  delay(1000); //Jeda waktu perulagan seama 1000 mili detik
  }
