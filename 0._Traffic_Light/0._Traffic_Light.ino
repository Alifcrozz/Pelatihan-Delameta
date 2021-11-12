int R=5;
int Y=6;
int G=7;

void setup() {
  // put your setup code here, to run once:

pinMode(R,OUTPUT);
pinMode(G,OUTPUT);
pinMode(Y,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(R, HIGH);
  digitalWrite(Y, LOW);
  digitalWrite(G, LOW);
  delay(2000);
  digitalWrite(R, LOW);
  digitalWrite(Y, HIGH);
  digitalWrite(G, LOW);
  delay(1000);
  digitalWrite(R, LOW);
  digitalWrite(Y, LOW);
  digitalWrite(G, HIGH);
  delay(1000);
  digitalWrite(R, LOW);
  digitalWrite(Y, HIGH);
  digitalWrite(G, LOW);
  delay(1000);
}
