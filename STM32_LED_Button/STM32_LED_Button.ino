// Inisialisasi komponen
int tombol1 = PA0;
int tombol2 = PA1;
int tombol3 = PB1;
int lampuM  = PB12;
int lampuK  = PB13;
int lampuH  = PA8;

void setup() {
// Baudrate yang digunakan untuk baca serial
Serial.begin(9600);

// Inisialisasi Fungsi Komponen
pinMode(tombol1, INPUT);
pinMode(tombol2, INPUT);
pinMode(tombol3, INPUT);
pinMode(lampuM, OUTPUT);
pinMode(lampuK, OUTPUT);
pinMode(lampuH, OUTPUT);
}

void loop() {
// Baca Nilai Button
int BacaTombol1=digitalRead(tombol1);
int BacaTombol2=digitalRead(tombol2);
int BacaTombol3=digitalRead(tombol3);

//Fungsi dan print button 1 dengan lampu merah
Serial.print("Kondisi tombol 1 :");
Serial.print(BacaTombol1);
Serial.print(" || ");
 if (BacaTombol1 == 1) {
  digitalWrite(lampuM, HIGH);
 }
 else{
  digitalWrite(lampuM, LOW);
 }

//Fungsi dan print button 1 dengan lampu kuning
Serial.print("Kondisi tombol 2 :");
Serial.print(BacaTombol2);
Serial.print(" || ");
 if (BacaTombol2 == 1) {
  digitalWrite(lampuK, HIGH);
 }
 else{
  digitalWrite(lampuK, LOW);
 }


//Fungsi dan print button 3 dengan lampu hijau
Serial.print("Kondisi tombol 3 :");
Serial.print(BacaTombol3);
Serial.println();
 if (BacaTombol3 == 1) {
  digitalWrite(lampuH, HIGH);
 }
 else{
  digitalWrite(lampuH, LOW);
 }
}
