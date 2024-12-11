#define BUTTON 2 // button pin number
int counter = 0;
void setup() {
    pinMode(BUTTON, INPUT_PULLUP); // sets the digital pin 14 as input
    Serial.begin(9600); // serial communication speed at 9600 baud
}

void loop() {
    if (digitalRead(BUTTON) == 0)
    {
        counter++;
        Serial.println(counter);
    }else if (counter != 0){
        Serial.print(counter);
        Serial.print(" * 2 = ");
        Serial.println(counter*2);
        Serial.println("wait for key press...  ");
        counter = 0;
    }else
    {
      
    }
    delay(500); //0.5 seconds delay
    
}