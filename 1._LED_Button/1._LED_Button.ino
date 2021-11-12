int tombol1 = 2;
int tombol2 = 3;
int tombol3 = 4;
int lampuM = 5;
int lampuK = 6;
int lampuH = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(tombol1, INPUT);
pinMode(tombol2, INPUT);
pinMode(tombol3, INPUT);
pinMode(lampuM, OUTPUT);
pinMode(lampuK, OUTPUT);
pinMode(lampuH, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int BacaTombol1=digitalRead(tombol1);
Serial.println("Kondisi tombol 1 :" + String(BacaTombol1));
 if (BacaTombol1 == 1) {
  digitalWrite(lampuM, HIGH);
 }
 else{
  digitalWrite(lampuM, LOW);
 }
 int BacaTombol2=digitalRead(tombol2);
Serial.println("Kondisi tombol 2 :" + String(BacaTombol2));
 if (BacaTombol2 == 1) {
  digitalWrite(lampuK, HIGH);
 }
 else{
  digitalWrite(lampuK, LOW);
 }
 int BacaTombol3=digitalRead(tombol3);
Serial.println("Kondisi tombol 3 :" + String(BacaTombol3));
 if (BacaTombol3 == 1) {
  digitalWrite(lampuH, HIGH);
 }
 else{
  digitalWrite(lampuH, LOW);
 }
}
