int greenLed = 13; // Green LED pin
int redLed = 12; // Red LED pin
int buzzer = 11; // Buzzer pin
int digitalPin = 2; // KY-026 digital interface
int analogPin = A0; // KY-026 analog interface
int digitalVal; // digital readings
int analogVal; //analog readings
int threshold = 1000; // Threshold under where buzzer start make sound
int soundDuration = 5000; // How long buzzer continue make sound after flame go out (in milliseconds)

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
