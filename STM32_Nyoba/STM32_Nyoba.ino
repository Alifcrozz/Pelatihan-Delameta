int lampuM = PB12;
int lampuK = PB13;
int lampuH = PB14;

void setup() {
  // put your setup code here, to run once:
  pinMode(lampuM, OUTPUT);
  pinMode(lampuK, OUTPUT);
  pinMode(lampuH, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(lampuM, HIGH);
  delay(500);
  digitalWrite(lampuM, LOW);
  delay(500);
  digitalWrite(lampuK, HIGH);
  delay(500);
  digitalWrite(lampuK, LOW);
  delay(500);
  digitalWrite(lampuH, HIGH);
  delay(500);
  digitalWrite(lampuH, LOW);
  delay(500);
}
