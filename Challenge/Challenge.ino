int tombol1=2;
int sensor1=3;
String kunci="dikunci";

int R=5;
int Y=6;
int G=7;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(sensor1,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  digitalWrite(R,HIGH);
  Serial.println("SYSTE START!");
}

void loop() {
   int bacaTombol1=digitalRead(tombol1);
   int bacaSensor1=digitalRead(sensor1);
   Serial.println("Kondisi tombol:" + String(bacaTombol1) + " | " + String (bacaSensor1)+" | " + String (kunci));  
   
    if (bacaTombol1==1 and kunci=="dikunci"){ 
      delay(500);
      kunci="dibuka";
      Serial.println("SELAMAT DATANG SILAHKAN AMBIL TIKET");
      Serial.println("PALANG DIBUKA");
      digitalWrite(R,LOW);
      digitalWrite(Y,HIGH);
      delay(1000);
      digitalWrite(Y,LOW);
      delay(100);
      digitalWrite(G,HIGH);
    }
    
    if (bacaSensor1==0 and kunci=="dibuka" ){ 
      delay(500);
      kunci="dikunci";
      Serial.println("PALANG DITUTUP");
      digitalWrite(G,LOW);
      digitalWrite(R,HIGH);
    }  
    
}
