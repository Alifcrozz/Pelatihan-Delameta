//Inisialisasi
int pinPIR = 2;
int pinBuzz = 5;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pinPIR,INPUT);
pinMode(pinBuzz, OUTPUT);
}

void loop() {
//Baca Sensor
int BacaPIR=digitalRead(pinPIR);

//Print ke Serial
Serial.print("PIR : ");
Serial.print(BacaPIR);
Serial.println(); //Untuk jarak spasi

//Logika Program
if (BacaPIR=1) {
  digitalWrite(pinPIR,HIGH);
  delay(100);
  digitalWrite(pinPIR,LOW);
  delay(200);
  digitalWrite(pinPIR,HIGH);
  Serial.println("Awas ada maling");
  }
  else{
    digitalWrite(pinPIR, LOW);
    Serial.println("Aman bosku...");
    }
}
