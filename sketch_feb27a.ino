const int trigger1 = 2; //Trigger pin of 1st Sesnor
const int echo1 = 3; //Echo pin of 1st Sesnor
const int trigger2 = 4; //Trigger pin of 2nd Sesnor
const int echo2 = 6;//Echo pin of 2nd Sesnor
long time_taken;
int dist,distL,distR;
void setup() {
Serial.begin(9600); 
  
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 
}
/*###Function to calculate distance###*/
void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>60)
dist = 60;
}
void loop() { //infinite loopy
calculate_distance(trigger1,echo1);
distR =dist; //get distance of left sensor
calculate_distance(trigger2,echo2);
distL =dist; //get distance of right sensor
//Pause Modes -Hold
if(distL>15 && distR>15 && distL<25 && distR<25){
  Serial.println("Play/Pause");
  delay(500);
}
if(distL<15 && distL>7){
  Serial.println("Volume Increased");
}
if(distL<7 && distL>0){
  Serial.println("Volume Decreased");
}
if(distR<15 && distR>7){
  Serial.println("Forward");
}
if(distR<7 && distR>0){
  Serial.println("Rewind");
}

delay(250);
}
