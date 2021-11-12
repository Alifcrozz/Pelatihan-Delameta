//Inisialisasi
int LDR=A0;
int lampu=6;


void setup() {
//Pin Mode Sensor
Serial.begin(9600);
pinMode(lampu, OUTPUT);
}

void loop() {
//Baca Sensor
int BacaLDR=analogRead(LDR);
BacaLDR = map(BacaLDR, 8,1023,0,255);

//Print ke Serial
Serial.print("Nilai :");
Serial.print(BacaLDR);
Serial.println();
//Logika Program
analogWrite(lampu, BacaLDR);
//if (BacaLDR > 400){
//  digitalWrite(lampu, HIGH);
//}
//else{
//  digitalWrite(lampu, LOW);
//  }
  

}
