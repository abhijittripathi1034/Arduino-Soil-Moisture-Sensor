int moistureSensor = 0;            // nail to read from is pin A0
int moisture_val;

const int redLEDPin = 3;           // red LED connected to digital pin
const int yellowLEDPin = 4;        // yellow LED connected to digital pin
const int greenLEDPin = 5;         // green LED connected to digital pin
const int blueLEDPin = 7;           // blue LED connected to digital pin
const int buttonPin = 9;           // button connected to digital pin

const int voltage = 8;             // the voltage nail is on pin D8

int buttonState = 0;           // initialise button as off

void setup() {
  Serial.begin(9600);             //open serial port
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);   //set the LED pins as outputs
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
if (buttonState == HIGH) {     
  digitalWrite(blueLEDPin, HIGH);
    
  digitalWrite(voltage, HIGH);
  moisture_val = analogRead(moistureSensor); //read the value from the nail
  Serial.print("Moisture Level: ");          //
  Serial.println( moisture_val );            //print moisture level 0-1024
  delay(50);

  delay(1000);        // fake thinking...
  digitalWrite(blueLEDPin, LOW);

  if (moisture_val < 350)  {
    digitalWrite(redLEDPin, HIGH);      // if moisture is less than 350 have red on, others off
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(greenLEDPin, LOW);
  }
  if (moisture_val < 800 && moisture_val > 350)  {
    digitalWrite(redLEDPin, LOW);
    digitalWrite(yellowLEDPin, HIGH);   // if moisture is less than 230 but over 190 have yellow on, others off
    digitalWrite(greenLEDPin, LOW);
  }
  if (moisture_val > 800 && moisture_val < 1023)  {
    digitalWrite(redLEDPin, LOW);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(greenLEDPin, HIGH);     // if moisture is over 230 and less than 300 have green on, others off
  }
  if (moisture_val > 1023){
    digitalWrite(redLEDPin, HIGH);      // if moisture is over than 300  (possibly flooded) have red on, others off
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(greenLEDPin, LOW);
  }
  //digitalWrite(voltage, HIGH);          // reset button state
  //delay(5000);                          // wait 5 ses

    //digitalWrite(redLEDPin, HIGH);      // if moisture is over than 300  (possibly flooded) have red on, others off
    //digitalWrite(yellowLEDPin, HIGH);
    //digitalWrite(greenLEDPin, HIGH);

}
}
