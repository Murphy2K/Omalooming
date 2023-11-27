int greenLed = 13; // Roheline led
int redLed = 12; // Punane led
int buzzer = 11; // Buzzer 
int digitalPin = 2; // KY-026 digital interface
int analogPin = A0; // KY-026 analog interface
int digitalVal; // digital readings
int analogVal; //analog readings
int threshold = 1000; // tundlikus
int soundDuration = 5000; // Kui kaua heli kestab (millisekundites)

void setup()
{
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // Read the digital interface
  digitalVal = digitalRead(digitalPin); 
  if(digitalVal == HIGH) // if flame is detected
  {
    digitalWrite(redLed, HIGH); // turn ON red LED
    digitalWrite(greenLed, LOW); // turn OFF green LED
    tone(buzzer, 1000); // make a sound
  }
  else
  {
    digitalWrite(redLed, LOW); // turn OFF red LED
    digitalWrite(greenLed, HIGH); // turn ON green LED
    noTone(buzzer); // stop the sound
  }
  // Read the analog interface
  analogVal = analogRead(analogPin); 
  Serial.println(analogVal); // print analog value to serial
  if(analogVal < threshold) // if flame is detected
  {
    digitalWrite(redLed, HIGH); // turn ON red LED
    digitalWrite(greenLed, LOW); // turn OFF green LED
    tone(buzzer, 1000); // make a sound
    delay(soundDuration); // keep the sound on for the specified duration
    noTone(buzzer); // stop the sound
  }
  else
  {
    digitalWrite(redLed, LOW); // turn OFF red LED
    digitalWrite(greenLed, HIGH); // turn ON green LED
    noTone(buzzer); // stop the sound
  }
  delay(100);
}
