#define trig 12
#define echo 11
int motorpin =9;
long duration,distance;
char reading ;
void setup()
{
Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(motorpin, OUTPUT);
}
void loop()
{
   digitalWrite(trig, LOW);
delayMicroseconds(2); 
digitalWrite(trig, HIGH);
delayMicroseconds(10); 
digitalWrite(trig, LOW);
duration = pulseIn(echo, HIGH);
distance = (duration/2) * 0.0343;
if(distance<200){ 
  int speed = map(distance,0,200,255,255*.25);

analogWrite(motorpin,speed);
analogWrite(motorpin,speed);
} 
  else{    analogWrite(motorpin,0);}


}