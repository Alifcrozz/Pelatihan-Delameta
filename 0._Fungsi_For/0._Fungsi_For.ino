void setup() {
  // put your setup code here, to run once:

for(float i=5; i<=7; i++){
pinMode(i,OUTPUT);
}
}
void loop() {
  // put your main code here, to run repeatedly:
for(float i=5; i<=7; i++){
digitalWrite(i,HIGH);
delay(1000);
digitalWrite(i,LOW);
delay(1000);
 }
}
