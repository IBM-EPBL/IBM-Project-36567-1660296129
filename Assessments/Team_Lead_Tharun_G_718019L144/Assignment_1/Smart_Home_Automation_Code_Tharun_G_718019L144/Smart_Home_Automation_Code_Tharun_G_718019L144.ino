// Smart Home automation system

/* 
WORKING PRINCIPLE:
- If any movement is detected, light bulb will be turned on.
- If temperature is high (greater than 25 degree celsius), then
  the fan will be switched on.
*/

// Submitted by Tharun G (718019L144)

// Motion sensor - Digital pin 2
const int motionSensor = 2;
// Variable to indicate whether any movement occurred or not
int motionDetection = 0;
// Variable to store the temperature value
int temperature = 0; 

void setup()
{
  Serial.begin(9600);
  pinMode(motionSensor, INPUT); // Motion sensor - Input
  pinMode(0, OUTPUT); // Bulb control - Output
  pinMode(1, OUTPUT); // Fan - Dc motor control - Output
}

void loop()
{
  // Reads the value at Digital pin 2 - Motion sensor output
  motionDetection = digitalRead(motionSensor);
  if (motionDetection)
  {
    digitalWrite(0, HIGH); // Bulb ON
    Serial.println("Movement detected");
    Serial.println("Bulb is turned on!");
  }
  else
  {
    digitalWrite(0, LOW); // Bulb OFF
    Serial.println("No movement detected");
    Serial.println("Bulb is turned off!");
  }
  
  // Reads the value at Analog pin 0 - Temperature sensor output
  temperature = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125); // in celsius
  
  // Printing the temperature value in serial monitor
  Serial.print("Temperature is ");
  Serial.print(temperature);
  Serial.println(" degree celsius");
  
  if (temperature > 25)
  {
    digitalWrite(1, HIGH); // Switch on the fan
    Serial.println("Fan is switched on!");
  }
  else
  {
    digitalWrite(1, LOW); // Switch off the fan
    Serial.println("Fan is switched off!");
  }
  
  Serial.println("*************************");
  delay(1000); // Wait for 1000 millisecond(s)
}
