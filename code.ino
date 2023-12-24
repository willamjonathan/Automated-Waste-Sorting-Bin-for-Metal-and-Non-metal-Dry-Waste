#include <Servo.h>

#define trigPin 3
#define echoPin 9
#define SENSOR 2

Servo servo;
Servo coinservo;

void setup() {
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 servo.attach(4);
 coinservo.attach(11);
 coinservo.write(0);
 pinMode(SENSOR, INPUT);
}

void loop() {
 long duration, distance;
 int L =digitalRead(SENSOR);// read the sensor
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);

 Serial.println(L);
  duration = pulseIn(echoPin, HIGH);
 distance = (duration / 2) / 29.1;
                                                                                                                                                                                                                                                                                                          
 if (distance < 15 && L == 0) {
   Serial.println("The distance is less than 10");
   Serial.print(" & Metal is detected");
   servo.write(70);
   delay(1000);
   servo.write(90);
   coinservo.write(150);
   delay(2000);
   servo.write(105);
   delay(1300);
   servo.write(90);
   coinservo.write(0);
   delay(1500);

 }else if (distance < 15 && L == 1){
   Serial.println("The distance is less than 10");
   Serial.print(" & Non-metal is detected");
   servo.write(110);
   delay(900);
   servo.write(90);
   coinservo.write(130);
   delay(2000);
   servo.write(70);
   delay(800);
   servo.write(90);
   Serial.print(" & Non-metal is detected");

   coinservo.write(0);
  
 }else {
   // servo.write(0);
 }
  if (distance > 60 || distance <= 0) {
   Serial.println("All Clear");
 } else {
   Serial.print(distance);
   Serial.println(" cm");
 }
  delay(500);
}
