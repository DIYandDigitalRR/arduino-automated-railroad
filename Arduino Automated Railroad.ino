int station1;
int station2;
int station3;
int Speed;
int Direction;
int speedval;


void setup() {
Serial.begin(9600);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop() {
  station1=analogRead(A0);
  station2=analogRead(A1);
  station3=analogRead(A2);
  speedval=analogRead(A3);
  Speed=map(speedval,0,1023,0,255);
  analogWrite(3,Speed);
  Serial.println(Direction);
  Serial.println(Speed);
  delay(200);


if (station1<500){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  Direction=0;
  delay(5000);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);

  delay(1500);
  }
if (station2<500){
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
  Direction=1;
  delay(5000);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);


  delay(1500);
}  

if ((station3<500) && (Direction==1)){
  digitalWrite(5,LOW);
 digitalWrite(6,LOW);
  delay(5000);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  delay(1500);
}
if ((station3<500) && (Direction==0)){
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 delay(5000);
 digitalWrite(5,HIGH);
 digitalWrite(6,LOW);
 delay(1500);
 }
}
