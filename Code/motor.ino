#define AIN1 17
#define AIN2 16
#define STBY 21
#define PWMA 20
void setup() {
  // put your setup code here, to run once:
 pinMode (AIN1,OUTPUT);
 pinMode (AIN2, OUTPUT);
 pinMode (STBY,OUTPUT);
 pinMode (PWMA, OUTPUT);
 digitalWrite(STBY, HIGH);


}

void stop () {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    digitalWrite(PWMA, HIGH);
  }

void turn1() {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(PWMA, HIGH);
  }
void turn2() {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(PWMA, HIGH);
  }
void loop() {
  // put your main code here, to run repeatedly:
  
  turn1 ();
  delay (3000);
  stop();
  delay(3000);
  turn2();
  delay (3000);
  stop();
  delay(3000);
}

