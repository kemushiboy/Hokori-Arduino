const int relayPin = 3;
const int sensorPin = 13;
const int highPin =12;

const unsigned long delayTime = 60000;

unsigned long timer;
unsigned long currentTime;


void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin, OUTPUT);
  pinMode(highPin, OUTPUT);
  pinMode(sensorPin, INPUT);

  digitalWrite(highPin,HIGH);
  digitalWrite(relayPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  currentTime = millis();

  //sensor反応時
  if(digitalRead(sensorPin) == LOW){
    digitalWrite(relayPin, LOW);
    //タイマーリセット
    timer = currentTime;
  }
  
   //sensor反応からdelay時間経過
   if(currentTime - timer >= delayTime){
     digitalWrite(relayPin, HIGH);
  }
}
