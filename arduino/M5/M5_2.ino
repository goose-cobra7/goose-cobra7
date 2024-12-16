 
#define BUTTON 2 // button pin number
int counter = 0;

 void setup() {
    Serial.begin(9600);
    pinMode(BUTTON, INPUT_PULLUP); // sets the digital pin 14 as input
 }

 void loop() {
    if (digitalRead(BUTTON) == 0)
    {
        counter++;
        Serial.println(counter);
    }else if (counter != 0){
        if (counter < 6)
        {
            int temp = counter;
            Serial.print(temp);
            Serial.print("+ ");
            Serial.print(--counter);
            Serial.print("= ");
            Serial.println(counter + temp);
            counter = 0;
        }else if (counter < 11)
        {
            int temp = counter;
            Serial.print(temp);
            Serial.print("- ");
            Serial.print(--counter);
            Serial.print("= ");
            Serial.println(temp - counter);
            counter = 0;
        }else if (counter < 16)
        {
            if (counter % 2 == 0)
            {
                Serial.println("even");
                counter = 0;
            }else{
                Serial.println("odd");
                counter = 0;
            }
        }else{
            Serial.println("number is bigger than 15");
            counter = 0;
        }
        
    }else
    {
      
    }
    delay(500); //0.5 seconds delay
 }