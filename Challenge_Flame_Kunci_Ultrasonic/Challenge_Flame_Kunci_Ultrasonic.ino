#include <NewPing.h>

int Flame   = PA0;
int Red     = PA1;
int Yellow  = PA2;
int Green   = PA3;
int Trigger = PB1;
int Echo    = PB0;
int Batas   = 400;
int kunci   = 0;

NewPing cm(Trigger, Echo, Batas);
 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Red   , OUTPUT);
pinMode(Yellow, OUTPUT);
pinMode(Green , OUTPUT);
pinMode(Flame , INPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
int BacaJarak = cm.ping_cm();
int BacaFlame = analogRead(Flame);
BacaFlame     = map(BacaFlame, 1, 4094, 1, 100);
Serial.print("kunci : "); Serial.print(kunci); Serial.println();

  if(BacaFlame <= 10 and kunci == 0){
  kunci = 1;
  delay(3000);
  }
  else if(BacaFlame <= 10 and kunci == 1){
  kunci = 0;
  digitalWrite(Red   , LOW );
      digitalWrite(Yellow, LOW );
      digitalWrite(Green , LOW);
  delay(3000);
  }

if(kunci == 1) {
  if (BacaJarak <20 and BacaJarak !=0) {
      Serial.print("Jarak : "); Serial.print(BacaJarak);
      Serial.print(" || ")    ; Serial.print("Terlalu Dekat"); 
      Serial.println();
      digitalWrite(Red   , HIGH);
      digitalWrite(Yellow, HIGH);
      digitalWrite(Green , HIGH);
      delay(100);
      digitalWrite(Red   , LOW);
      digitalWrite(Yellow, LOW);
      digitalWrite(Green , LOW);
      delay(100);
      }
      else if (BacaJarak >= 20 and BacaJarak < 70){
      Serial.print("Jarak : "); Serial.print(BacaJarak);
      Serial.print(" || ")    ; Serial.print("Bahaya"); 
      Serial.println();
      digitalWrite(Red   , HIGH);
      digitalWrite(Yellow, HIGH);
      digitalWrite(Green , HIGH);
      delay(1000);
      digitalWrite(Red   , LOW);
      digitalWrite(Yellow, LOW);
      digitalWrite(Green , LOW);   
      delay(1000);   
      }
      else if (BacaJarak >=70) {
        Serial.print("Jarak : "); Serial.print(BacaJarak);
      Serial.print(" || ")    ; Serial.print("Jauh"); 
      Serial.println();
      digitalWrite(Red   , HIGH);
      digitalWrite(Yellow, LOW);
      digitalWrite(Green , LOW);
      delay(500);
      digitalWrite(Red   , LOW);
      digitalWrite(Yellow, HIGH);
      digitalWrite(Green , LOW);
      delay(500);
      digitalWrite(Red   , LOW );
      digitalWrite(Yellow, LOW );
      digitalWrite(Green , HIGH);
      delay(500);
      digitalWrite(Red   , LOW );
      digitalWrite(Yellow, HIGH );
      digitalWrite(Green , LOW);
      delay(500);
      digitalWrite(Red   , HIGH );
      digitalWrite(Yellow, LOW );
      digitalWrite(Green , LOW);
      delay(500);
      }
      else if (kunci == 0){
      digitalWrite(Red   , LOW );
      digitalWrite(Yellow, LOW );
      digitalWrite(Green , LOW);
      delay(500);  
      }
    
    }
}
