
const int sensorTrigPin = 12;
const int sensorEchoPin = 11;
const int relayPin = 6;
long duration;
int distance;
boolean isTrue = false;
void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(sensorTrigPin, OUTPUT);
  pinMode(sensorEchoPin, INPUT);
  Serial.begin(9600);
  
}

void loop() {  

  duration = pulseIn(sensorEchoPin, HIGH);
  distance = duration*0.034/2;
  
  Serial.println(distance);

  if(distance <= 10){
    isTrue = !isTrue;
     
  }
    
  if (isTrue){
    digitalWrite(relayPin, HIGH);
    delay(5000);  
  }
  else{
    digitalWrite(relayPin, LOW);
    delay(5000);
  }
}
