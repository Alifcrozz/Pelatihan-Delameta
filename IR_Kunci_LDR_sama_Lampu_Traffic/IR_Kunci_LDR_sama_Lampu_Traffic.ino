//inisialisasi
int R=PA3;
int Yellow =PA2;
int G=PA1;
int IR=PA0;
int LDR= PA4;
int kunci=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(R,OUTPUT);
pinMode(Yellow,OUTPUT);
pinMode(G,OUTPUT);
pinMode(IR,INPUT);
pinMode(LDR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int BacaLDR = analogRead(LDR);
int BacaIR  = digitalRead(IR);
BacaIR  = map(BacaIR, 1,0, 0, 1);
BacaLDR = map(BacaLDR, 0, 4095, 1000, 0);

Serial.print("Baca LDR : "); Serial.print(BacaLDR); Serial.print(" || "); 
Serial.print("Baca IR :  "); Serial.print(BacaIR ); Serial.print(" || ");
Serial.print("Kunci   :  "); Serial.print(kunci  );  

  if(BacaIR == 1 and kunci == 0) {
    kunci=1;
    delay(500);
  }
  else if (BacaIR == 1 and kunci == 1){
    kunci=0;
    delay(500);
    }
  
if(kunci == 1){
     
  if      (BacaLDR == 0) {
    digitalWrite(R,     HIGH);
    digitalWrite(Yellow, LOW);
    digitalWrite(G,      LOW);
  }
  else if (BacaLDR > 25 and BacaLDR < 50 ) {
    digitalWrite(R,      LOW );
    digitalWrite(Yellow, HIGH);
    digitalWrite(G,      LOW );    
    }
  else if (BacaLDR >= 50 ) {
    digitalWrite(R,      LOW );
    digitalWrite(Yellow, LOW );
    digitalWrite(G,      HIGH);
    }
   else if (kunci == 0) {
    digitalWrite(R,      LOW );
    digitalWrite(Yellow, LOW );
    digitalWrite(G,      LOW );
    }
   }
    
}
