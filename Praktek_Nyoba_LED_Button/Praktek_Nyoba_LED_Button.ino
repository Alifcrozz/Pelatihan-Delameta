//Inisialisasi Komponen
int alif_tombol1 = PA4;
int alif_tombol2 = PA5;
int alif_tombol3 = PA6;

int alif_lampuM = PA11;
int alif_lampuK = PB8;
int alif_lampuH = PB9;

int kunci1 = 0;
int kunci2 = 0;
int kunci3 = 0;
void setup() {
// Baudrate baca serial
Serial.begin(9600);

//Inisialisasi Fungsi Input
pinMode(alif_tombol1, INPUT);
pinMode(alif_tombol2, INPUT);
pinMode(alif_tombol3, INPUT);

//Inisialisasi Fungsi Ouput
pinMode(alif_lampuM, OUTPUT);
pinMode(alif_lampuK, OUTPUT);
pinMode(alif_lampuH, OUTPUT);
}

void loop() {
// Baca Nilai Button
int BacaTombol1 = digitalRead(alif_tombol1);
int BacaTombol2 = digitalRead(alif_tombol2);
int BacaTombol3 = digitalRead(alif_tombol3);

//Print ke Serial 
Serial.print("Tombol 1: ");
Serial.print(BacaTombol1);
Serial.print(" || ");
Serial.print("Tombol 2: ");
Serial.print(BacaTombol2);
Serial.print(" || ");
Serial.print("Tombol 3: ");
Serial.print(BacaTombol3);
Serial.println();

//Fungsi Program Button 1 dengan lampu merah
if (BacaTombol1 == 1) {
    if (kunci1==0){
    kunci1=1;
    digitalWrite(alif_lampuM, HIGH);
    }
else {
     kunci1=0;
    digitalWrite(alif_lampuM, LOW);
    }
    delay(100);
}
    
//Fungsi Program Button 2 dengan lampu kuning
if (BacaTombol2 == 1) {
    if(kunci2==0){
    kunci2=1;
    digitalWrite(alif_lampuK, HIGH);
    }
else {
    kunci2=1;
    digitalWrite(alif_lampuK, LOW);
    }
    delay(100);
}

//Fungsi Program Button 3 dengan lampu hijau    
if (BacaTombol3 == 1) {
    if (kunci3 ==0)
    kunci3=1;
    digitalWrite(alif_lampuH, HIGH);
    }
else {
    kunci3=0;
    digitalWrite(alif_lampuH, LOW);
    }
    delay(100);
}
