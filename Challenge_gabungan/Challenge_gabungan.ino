int lampuM = 6;
int lampuK = 7;
int lampuH = 8;
int buzz = 5;
int pir = 2;
int flame = A1;
int ldr = A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(lampuM, OUTPUT);
pinMode(lampuK, OUTPUT);
pinMode(lampuH, OUTPUT);
pinMode(buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int Bacaldr = analogRead(ldr);
Bacaldr = map(Bacaldr, 12,1023,0,100);
int Bacaflame = analogRead(flame);
Bacaflame = map(Bacaflame, 20,1021,100,0);
int Bacapir = digitalRead(pir);

//Serial.print("Nilai LDR : "+ String(Bacaldr));
  //Serial.print(" || Nilai sensor pir: " + String(Bacapir));
  //Serial.print(" || Nilai sensor flame: " + String(Bacaflame));
  //Serial.println();   //Untuk Enter

analogWrite(lampuM, Bacaldr);

if (Bacaflame <=10){
  digitalWrite(buzz, LOW);
  Serial.println("Aman Banget");
  digitalWrite(lampuH, HIGH);
  digitalWrite(lampuK, LOW);
  
}
else if (Bacaflame <=50){
  Serial.println("Warning Silahkan Periksa");
  digitalWrite(lampuK, HIGH);
  digitalWrite(lampuH, LOW);
  digitalWrite(buzz, HIGH);
  delay(1000);
  digitalWrite(buzz, LOW);
  delay(1000);
}
else if (Bacaflame >=70){
  Serial.println("Waspada Silahkan Mengungsi");
  digitalWrite(lampuK, HIGH);
  digitalWrite(lampuH, HIGH);
  digitalWrite(buzz, HIGH);
  delay(100);
  digitalWrite(buzz, LOW);
  delay(100);
  }


}
