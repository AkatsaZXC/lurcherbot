void setup(){
  Serial.begin(115200);
  pinMode(A0,OUTPUT);
}
void loop(){
  int i = analogRead(A0);
  Serial.println(i);
}
