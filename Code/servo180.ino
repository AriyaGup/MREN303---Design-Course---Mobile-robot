#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
 myservo.attach(6,600,2500);

 myservo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
 myservo.write(180);

 delay(3000);

 myservo.write(0);

 delay (3000);
}
