int Flame=A1;
int Buzz=5;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int BacaFlame=analogRead(Flame);
BacaFlame = map(BacaFlame, 20,1021,100,0);
Serial.print("Nilai :");
Serial.print(BacaFlame);
Serial.println();
if (BacaFlame <=10){
  digitalWrite(Buzz, LOW);
  Serial.println("Aman");
}
else if (BacaFlame <=50){
  Serial.println("Waspada Silahkan Periksa");
  digitalWrite(Buzz, HIGH);
  delay(1000);
  digitalWrite(Buzz, LOW);
  delay(1000);
}
else if (BacaFlame >=70){
  Serial.println("Waspada Silahkan Mengungsi");
  digitalWrite(Buzz, HIGH);
  delay(100);
  digitalWrite(Buzz, LOW);
  delay(100);
  }
}
