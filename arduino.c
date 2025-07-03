// Pins
const int buttonPins[] = {2, 3, 4, 5, 6};    // Butoes
const int ledPins[] = {8, 9, 10, 11, 12};    // LEDs
const int buzzerPin = 13;                      

const int noteFrequencies[] = {262, 294, 330, 349, 392};

int buttonStates[5]; 
const int numButtons = 5;   
bool buttonPressed = false;
int lastButton = 0;
void setup() {
  // Initialize all LED pins as outputs
  for (int i = 0; i < numButtons; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); 
  }

  pinMode(buzzerPin, OUTPUT);

  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT);
  }
  
  Serial.begin(9600);
}

void loop() {

  for (int i = 0; i < numButtons; i++) {
    buttonStates[i] = digitalRead(buttonPins[i]);
    if (buttonStates[i] == LOW) {
      digitalWrite(ledPins[i], LOW);
      if (i == lastPin) {
        noTone(buzzerPin);
        anyButtonPressed = false;
      }
    } else {
      digitalWrite(ledPins[i], HIGH);
      tone(buzzerPin, noteFrequencies[i]);
      anyButtonPressed = true;
      lastPin = i;
      delay(50);
    }
  }
  delay(50);
}
