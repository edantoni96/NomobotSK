#include <Adafruit_NeoPixel.h>

String input;

static const uint8_t echo = D0;
static const uint8_t trigger = D1;
static const uint8_t servo_l = D0;
static const uint8_t servo_r = D1;
static const uint8_t button_A = D2;
static const uint8_t button_B = D3;
static const uint8_t motor_2n = D4;
static const uint8_t motor_2p = D5;
static const uint8_t motor_1n = D6;
static const uint8_t motor_1p = D7;
static const uint8_t led_pin = D8;
static const uint8_t buzz_pin = D0 ;
static const uint8_t line_l = D8;
static const uint8_t line_r = A0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, D8, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(115200);
  pinMode(motor_2n, OUTPUT);
  pinMode(motor_2p, OUTPUT);
  pinMode(motor_1n, OUTPUT);
  pinMode(motor_1p, OUTPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(button_A, INPUT);
  pinMode(button_B, INPUT);
  pinMode(line_r, INPUT);
  pixels.begin();
  setColor(0,255,255,255,100);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("TEST PROGRAM");

  while(!Serial.available())
  {
  }

  input = Serial.readString();
  Serial.println(input);

  if(input == "TEST_M1\n") {
    Serial.println("Test Motor DC 1 Forward");
    digitalWrite(motor_1p, HIGH);
    digitalWrite(motor_1n, LOW);
    delay(5000);
    digitalWrite(motor_1p, LOW);
    digitalWrite(motor_1n, LOW);
    delay(1000);
    Serial.println("Test Motor DC 1 Backward");
    digitalWrite(motor_1p, LOW);
    digitalWrite(motor_1n, HIGH);
    delay(5000);
    Serial.println("Test Motor DC 1 Stop");
    digitalWrite(motor_1p, LOW);
    digitalWrite(motor_1n, LOW);
  }
  else if(input == "TEST_M2\n") {
    Serial.println("Test Motor DC 2 Forward");
    digitalWrite(motor_2p, HIGH);
    digitalWrite(motor_2n, LOW);
    delay(5000);
    digitalWrite(motor_2p, LOW);
    digitalWrite(motor_2n, LOW);
    delay(1000);
    Serial.println("Test Motor DC 2 Backward");
    digitalWrite(motor_2p, LOW);
    digitalWrite(motor_2n, HIGH);
    delay(5000);
    Serial.println("Test Motor DC 2 Stop");
    digitalWrite(motor_2p, LOW);
    digitalWrite(motor_2n, LOW);
  }
  else if(input == "TEST_LED\n") {
    Serial.println("Test Led");
    int led = 0;
    for(led=0; led <16; led++)
    {
      setColor(led,255,0,0,100); //red
    }
    for(led=0; led <16; led++)
    {
      setColor(led,0,255,0,100);
    }
    for(led=0; led <16; led++)
    {
      setColor(led,0,0,255,100); 
    }
  }
  else if(input == "TEST_BUZ\n") {
    pinMode(buzz_pin, OUTPUT);
    Serial.println("Test Buzzer");
    delay(500);
    digitalWrite(buzz_pin, HIGH);
    delay(500);
    digitalWrite(buzz_pin, LOW);
    delay(1000);
    digitalWrite(buzz_pin, HIGH);
    delay(500);
    digitalWrite(buzz_pin, LOW);
    delay(1000);
    digitalWrite(buzz_pin, HIGH);
    delay(500);
    digitalWrite(buzz_pin, LOW);
    Serial.println("Test Buzzer Done");
  }
  else if(input == "TEST_ULTRA\n") {
    String data, command;
    long duration;
    int distance;
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    Serial.println("Test Ultrasonic");
    while(1){
      if(Serial.available()){
        command = Serial.readString();
        if(command == "STOP\n") {
          break;
        }
      }
      digitalWrite(trigger, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigger, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echo, HIGH);
      // Calculating the distance
      distance = duration * 0.034 / 2;
      // Prints the distance on the Serial Monitor
      Serial.print("Distance: ");
      Serial.println(distance);
      delay(200);
    }
  }
  else if(input == "TEST_LINE\n") {
    int lstat,rstat;
    String command;
    pinMode(line_l, INPUT);
    pinMode(line_r, INPUT);

    while (1) {
      if(Serial.available()){
        command = Serial.readString();
        if(command == "STOP\n") {
          break;
        }
      }
      lstat = digitalRead(line_l);
      rstat = analogRead(line_r);
      Serial.print("right : ");
      Serial.print(rstat);
      Serial.print(" | left : ");
      Serial.println(lstat);
    }
  }
  else if (input == "TEST_BUTTON\n"){
    String command;
    while(1) {
      if(!digitalRead(button_A)) {
        Serial.println("Button A pressed");
      }
      if(!digitalRead(button_B)) {
        Serial.println("Button B pressed");
      }
      if(Serial.available()){
        command = Serial.readString();
        if(command == "STOP\n") {
          break;
        }
      }
      delay(200);
    }
  }
  
}

void setColor(int led, int redValue, int greenValue, int blueValue, int delayValue)
{
  pixels.setPixelColor(led, pixels.Color(redValue, greenValue, blueValue)); 
  pixels.show();
  delay(delayValue);
}
