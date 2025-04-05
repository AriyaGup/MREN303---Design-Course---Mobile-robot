 // MREN 303 Pico W Wifi Gamepad Read and Switch Modes
// Written For MREN 303 

#include <WiFi.h>
#include <WiFiUdp.h>
#include <Servo.h>
#include <Wire.h>
#include <SparkFun_TB6612.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;

#ifndef STASSID
#define STASSID "MREN303_wifi-2.4GHz"
#define STAPSK "MREN@303p1"
#endif

//motor pins
#define AIN1 11
#define AIN2 10 
#define PWMA 9
#define BIN1 13
#define BIN2 14
#define PWMB 15
#define STBY 12

// Encoder pins
//#define ENCA_A 8
//#define ENCA_B 10
//#define ENCB_A 7
//#define ENCB_B 5

// Ultrasonic sensor pins
#define trigPin 7
#define echoPin 8

long duration;
int distance;


unsigned int localPort = 8888;  // local port to listen on

int servo1Pos = 180; // default center
int servo2Pos = 180;

Motor motor1 = Motor(AIN1, AIN2, PWMA, 1, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, -1, STBY);

// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE + 1];  // buffer to hold incoming packet,
char ReplyBuffer[] = "acknowledged\r\n";        // a string to send back
// char Arrays to match commands from gamepad 
char stringA[17] =    "A Button Press";
char stringB[17] =    "B Button Press";
char stringY[17] =    "Y Button Press";
char stringX[17] =    "X Button Press";
char stringLB[17] =   "LB Button Press";
char stringRB[17] =   "RB Button Press";
char stringLS[17] =   "L Stick Press";
char stringRS[17] =   "R Stick Press";
char stringBack[17]=  "Back Press";
char stringStart[17]= "Start Press";
char stringUp[17] =   "Up DPad Press"; 
char stringDown[17] = "Down DPad Press";
char stringLeft[17] = "Left DPad Press";
char stringRight[17]= "Right DPad Press";
char stringLX[17] =   "L Stick X Value ";
char stringLY[17] =   "L Stick Y Value ";
char stringRX[17] =   "R Stick X Value ";
char stringRY[17] =   "R Stick Y Value ";
char stringLT[17] =   "L Trigger Value ";
char stringRT[17] =   "R Trigger Value ";

int batteryLevel = 0;
bool pollBattery = false; 

int valueLx = 0;
int valueLy = 0;
int valueRx = 0;
int valueRy = 0;
int valueLt = 0;
int valueRt = 0; 

//game modes
const int IDLE_MODE = 0;
const int AUTO_MODE = 1;
const int MANUAL_MODE = 2;
int current_mode = IDLE_MODE; // Variable to store the current mode. Starts in idle mode

char comparisonString[17] = "";

unsigned long startTime = 0;  // Variable to store the start time
unsigned long currentTime = 0; // Variable to store the current time

WiFiUDP Udp;

void setup() { //This handles network function and runs on core 1

  delay(2000);
  Serial.begin(115200);
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
  Serial.printf("UDP server on port %d\n", localPort);
  Udp.begin(localPort);
}

void loop1Task(void *pvParameters) {
  setup1();  // Make sure setup1() runs
  while (true) {
    loop1();
    delay(10);  // Small delay to prevent excessive CPU usage
  }
}

void setup1(){ //This handles all inputs and outputs and runs on core 2
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,0);
  myservo1.attach(5);
  myservo2.attach(2);
  myservo3.attach(6);
  myservo1.write(120);
  myservo2.write(150);
  myservo3.write(180);

  // Initialize motor driver pins as outputs
  pinMode(STBY, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

//functions

void moveForward() {
  motor1.drive(-255);
  motor2.drive(-255);
  return;
}

void stopMotors() {
  motor1.brake();
  motor2.brake();
  return;
}

void turnLeft() {
  left(motor1, motor2, 255);
  return;
}

void turnRight() {
  right(motor1, motor2, 255);
  return;
}

void moveBackward() {
  motor1.drive(255);
  motor2.drive(255);
  return;
}

int findDist() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  //Serial.print("Distance (cm): ");
  //Serial.println(distance);

  return distance;
}

void loop() { //This loop executes on Core 1 of the Pico, handles networking and recieves commands
  // if there's data available, read a packet
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    Serial.printf("Received packet of size %d from %s:%d\n    (to %s:%d)\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort(), Udp.destinationIP().toString().c_str(), Udp.localPort());

    // read the packet into packetBufffer
    int n = Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    packetBuffer[n] = 0;

    
    char valueString[5] = "";

    for (int i=0; i<16 ; i++){
      comparisonString[i]=packetBuffer[i];
    }
    comparisonString[16] = 0;
    
    Serial.println("Comp String:");
    Serial.println((char*)comparisonString);

    if (strcmp(comparisonString,stringA) == 0){
      if (current_mode == IDLE_MODE){ // You can only go to auto mode from idle mode
        Serial.println("Setting mode to auto");//this line may be removed for final version
        current_mode = AUTO_MODE; // Change to auto mode
        startTime = millis();  // Start recording the time
      }           
    }
    if (strcmp(comparisonString,stringB) == 0){
      Serial.println("Setting mode to manual");//this line may be removed for final version
      current_mode = MANUAL_MODE; // Change to manual mode
    }
    if (strcmp(comparisonString,stringY) == 0){
      Serial.println("Setting mode to idle");//this line may be removed for final version
      current_mode = IDLE_MODE; // Change to idle mode
    }   
    if (strcmp(comparisonString,stringLX) == 0){
      for(int i=16; i<=packetSize ; i++){
        valueString[(i-16)] = packetBuffer[i];}
      valueString[5] = 0;
      valueLx = atoi(valueString);
      Serial.println("LX Value is:");
      Serial.println(valueLx);
    }
    if (strcmp(comparisonString,stringLY) == 0){
      for(int i=16; i<=packetSize ; i++){
        valueString[(i-16)] = packetBuffer[i];}
      valueString[5] = 0;
      valueLy = atoi(valueString);
      Serial.println("LY Value is:");
      Serial.println(valueLy);
    }
    if (strcmp(comparisonString,stringRX) == 0){
      for(int i=16; i<=packetSize ; i++){
        valueString[(i-16)] = packetBuffer[i];}
      valueString[5] = 0;
      valueRx = atoi(valueString);
      Serial.println("RX Value is:");
      Serial.println(valueRx);
    }
    if (strcmp(comparisonString,stringRY) == 0){
      for(int i=16; i<=packetSize ; i++){
        valueString[(i-16)] = packetBuffer[i];}
      valueString[5] = 0;
      valueRy = atoi(valueString);
      Serial.println("RY Value is:");
      Serial.println(valueRy);
    }
    if (strcmp(comparisonString,stringRT) == 0){
      for(int i=16; i<=packetSize ; i++){
        valueString[(i-16)] = packetBuffer[i];}
      valueString[5] = 0;
      valueRt = atoi(valueString);
      Serial.println("RT Value is:");
      Serial.println(valueRt);
    }
    if (strcmp(comparisonString,stringLT) == 0){
      for(int i=16; i<=packetSize ; i++){
        valueString[(i-16)] = packetBuffer[i];}
      valueString[5] = 0;
      valueLt = atoi(valueString);
      Serial.println("LT Value is:");
      Serial.println(valueLt);
    }
    if (strcmp(comparisonString,stringStart) == 0){
      Serial.println("Polling Battery Level");
      pollBattery = true;
      char pollBatteryMessage[] = "Polling Battery Level"; 
      memcpy(ReplyBuffer,pollBatteryMessage,22);
    }
    
    // send a reply, to the IP address and port that sent us the packet we received
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(ReplyBuffer);
    Udp.endPacket();
  }
}


// YOUR CODING GOES HERE
void studentCode(int current_mode){ 
  if(current_mode == IDLE_MODE){
   //Serial.println("You are in idle mode");//this line may be removed for final version
   digitalWrite(LED_BUILTIN, LOW); // LED is off for idle mode
   // Initialize motors state as off
    motor1.brake();
    motor2.brake();
    // No further action required
  }
  else if (current_mode == AUTO_MODE){
    //Serial.println("You are in auto mode");//this line may be removed for final version
    digitalWrite(LED_BUILTIN, LOW); // LED is off for auto mode

    moveForward();
    if (distance<=20) {
      stopMotors();
      delay(500);
      turnLeft();
      delay(950); // adjust for 90-degree turn
      stopMotors();
      delay(300);

      moveForward();
      delay(2000); // move certain distance
      stopMotors();
      delay(300);

      turnLeft();
      delay(950);
      stopMotors();
      delay(300);

      if (distance<20){
        stopMotors();
        delay(500);

        turnRight();
        delay(2500);
        stopMotors();
        delay(300);
        if (distance<20){
          stopMotors();
          //press
          myservo1.write(120);
          current_mode = MANUAL_MODE;
        }
      }
    }
  }
    // Write additional commands for autonomous mode
    //CAUTION: YOU CANNOT PRESS ANY BUTTONS WHILE IN AUTO MODE UNLESS YOU PASS THE GATE (in this case, press B to go to manual mode)
  
  else if (current_mode == MANUAL_MODE) {
    //Serial.println("You are in manual mode");  
    digitalWrite(STBY, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    if ((abs(valueLy)>50)&&(abs(valueLy)>abs(valueLx))) {  
      motor1.drive(valueLy);
      motor2.drive(valueLy);
    } 
    else if ((valueLx > 50)&&(abs(valueLy)<abs(valueLx))) { 
      motor1.drive(valueLx);
      motor2.drive(-valueLx);
    }
    else if ((valueLx < -50)&&(abs(valueLy)<abs(valueLx))) { 
      motor1.drive(valueLx);
      motor2.drive(-valueLx);
    }
    else if ((strcmp(comparisonString, stringX) == 0)||valueLx==0||valueLy==0){
      stopMotors();
    }
    else if (strcmp(comparisonString, stringLeft)==0){
      myservo3.write(180);
    }
    else if (strcmp(comparisonString, stringRight)==0){
      myservo3.write(140);
    }
    else if ((valueRy > 50) && (abs(valueRy) > abs(valueRx))) {
      servo2Pos=servo2Pos+1;
      if(servo2Pos>180){
        servo2Pos=180;
      }
      myservo2.write(servo2Pos);
    }
    else if ((valueRy<-50)&&(abs(valueRy)>abs(valueRx))){  
      servo2Pos=servo2Pos-1;
      if(servo2Pos<90){
        servo2Pos=90;
      }
      myservo2.write(servo2Pos);
    }
    else if ((valueRx > 50) && (abs(valueRx) > abs(valueRy))) {
      servo2Pos=servo2Pos+1;
      if(servo2Pos>180){
        servo2Pos=180;
      }
      myservo2.write(servo1Pos);
    }
    else if ((valueRx<-50)&&(abs(valueRx)>abs(valueRy))){  
      servo1Pos=servo1Pos-1;
      if(servo2Pos<90){
        servo2Pos=90;
      }
      myservo2.write(servo1Pos);
    }
  }

  return;
}

void readBattery(){
  // battery voltage = 1.0V - 1.4V / cell * 4 cells = 4.0V - 5.6V 
  // Too high a voltage for Pico IO, 
  // Use voltage ladder (2 high value resistors connected in series between power and ground, attach an analog read to middle) to convert to 2.0V - 2.8V
  // Pico IO max 3.3V so to map maximum and minimum battery level:   
  // (4096 max value read/ 3.3V max voltage) * 2.0V = 2482 min value,(4096 max value read/ 3.3V max voltage) * 2.8V = 3475 max value    
  // Therefore 2482-3475 is our range for battery level 
  int voltage = analogRead(A0);
  //Serial.println("Voltage reading is:");
  //Serial.println(voltage);
  //if (voltage < 200) {
    //Serial.println("Battery Not Connected");
  //}
  //else{
    batteryLevel = map(voltage,2482,3475,0,100);
    char batteryMessage[] = "Battery Level is: %d %";
    sprintf(ReplyBuffer,batteryMessage,batteryLevel);
    Serial.println("Battery Level is :");
    Serial.print(batteryLevel); 
    Serial.print("% \n");  
    return;
  }

void loop1(){ //This Runs on Core 2 and performs all inputs and outputs

currentTime = millis();
distance = findDist();

if(pollBattery){
    readBattery();
    pollBattery = false;
  }

// After spending more than 30 s in auto mode:
if ((current_mode == AUTO_MODE) && (currentTime - startTime) >= 30000) {
  Serial.println("TIME OUT: changing to manual mode");//this line may be removed for final version
  current_mode = MANUAL_MODE; // Change to manual mode
  }
studentCode(current_mode);
delay(30); //this line may be removed for final version
}


