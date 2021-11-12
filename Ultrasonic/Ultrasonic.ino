//Download dan masukan Lihbrary NewPing
#include <NewPing.h>
//Inisialisasi pembuatan variable
int lampuM = 6;
int lampuK = 7;
int lampuH = 8;
int buzz = 3;
int triger =5;
int echo =4;
int batas =200; //Maksimal 400 cm
NewPing cm(triger,echo,batas);
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(buzz, OUTPUT);
 pinMode(lampuM, OUTPUT);
 pinMode(lampuK, OUTPUT);
 pinMode(lampuH, OUTPUT);
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 int bacaJarak=cm.ping_cm();
 //Print ke Serial Monitor
 Serial.print("Data jarak:");
 Serial.print(bacaJarak);
 Serial.print(" cm");
 Serial.println();
 delay(1000); //Jeda waktu perulagan seama 500 mili detik
 if (bacaJarak < 20 and bacaJarak!=0) {
  Serial.println("Berhenti");
  digitalWrite(lampuM, HIGH);
  digitalWrite(lampuK, LOW);
  digitalWrite(lampuH, LOW);
  digitalWrite(buzz, HIGH);
  delay(100);
  digitalWrite(buzz, LOW);
  }
  else if (bacaJarak >21 and bacaJarak <70 ) {
  Serial.println("Bahaya");
  digitalWrite(lampuM, LOW);
  digitalWrite(lampuK, HIGH);
  digitalWrite(lampuH, LOW);
  digitalWrite(buzz, HIGH);
  delay(1000);
  digitalWrite(buzz, LOW);  
     }
  else{
  Serial.println("Aman");  
  digitalWrite(lampuM, LOW);
  digitalWrite(lampuK, LOW);
  digitalWrite(lampuH, HIGH);
  digitalWrite(buzz,LOW);  
    }
}
