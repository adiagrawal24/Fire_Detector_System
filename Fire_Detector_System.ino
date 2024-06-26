
int flame_sensor_pin = 4;       // initializing pin 4 as the sensor output pin
int buzzer_pin = 3;             // initializing pin 8 as the buzzer pin
int led_pin = 13;                // initializing the pin 2 as the led pin
 
int flame_pin = HIGH;           // state of sensor
 
 
void setup()
{
  pinMode(led_pin, OUTPUT);             // declaring led pin as output pin
  pinMode(flame_sensor_pin, INPUT);     // declaring sensor pin as input pin for Arduino
  pinMode(buzzer_pin, OUTPUT);          // declaring buzzer pin as output pin
  Serial.begin(9600);                   // setting baud rate at 9600
}
 
 
void loop()
{
  flame_pin = digitalRead(flame_sensor_pin);          // reading from the sensor
  if (flame_pin == LOW)                               // applying condition
  {
    Serial.println("FLAME, FLAME, FLAME");
    
    digitalWrite(led_pin, HIGH);
    digitalWrite(buzzer_pin, HIGH);                      // if state is high, then turn high the led
      
    delay(3000);                                   // play a melody on the buzzer
  }
  else
  {
    Serial.println("no flame");
    digitalWrite(led_pin, LOW);  
    digitalWrite(buzzer_pin, LOW);                            // stop playing any tone
  }
}