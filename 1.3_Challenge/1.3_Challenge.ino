const int tombol1 = 2;
const int tombol2 = 3;
//const int tombol3 = 4;
const int lampuM = 5;
const int lampuK = 6;
//const int lampuH = 7;
 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(tombol1, INPUT);
//pinMode(tombol2, INPUT);
//pinMode(tombol3, INPUT);
pinMode(lampuM, OUTPUT);
pinMode(lampuK, OUTPUT);
//pinMode(lampuH, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int BacaTombol1=digitalRead(tombol1);
int BacaTombol2=digitalRead(tombol2);
Serial.println("Kondisi tombol 1 :" + String(BacaTombol1));
 if (BacaTombol1 ==1 and BacaTombol2 == 1) {
  digitalWrite(lampuM, HIGH);
 }
 else {
  digitalWrite(lampuM, LOW);
 }

}
