const int tombol1 = 2;
const int tombol2 = 3;
const int tombol3 = 4;
const int lampuM = 5;
const int lampuK = 6;
const int lampuH = 7;
int ledflag1 = 0;
int ledflag2 = 0;
int ledflag3 = 0;
 

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
int BacaTombol2=digitalRead(tombol2);
int BacaTombol3=digitalRead(tombol3);
Serial.println("Kondisi tombol 1 :" + String(BacaTombol1));
 if (BacaTombol1 == 1) {
  if (ledflag1==0){
    ledflag1=1;
    digitalWrite(lampuM, HIGH);
    }
  else {
    ledflag1=0;
    digitalWrite(lampuM, LOW);
    }
  delay(100);
  }
  
  if (BacaTombol2 == 1) {
    if (ledflag2==0){
    ledflag2=1;
    digitalWrite(lampuK, HIGH);
    }
    else {
    ledflag2=0;
    digitalWrite(lampuK, LOW);
    }
  delay(100);
  }
   if (BacaTombol3 == 1) {
  if (ledflag3==0){
    ledflag3=1;
    digitalWrite(lampuH, HIGH);
    }
  else {
    ledflag3=0;
    digitalWrite(lampuH, LOW);
    }
  delay(100);
  }
  
  
 }
