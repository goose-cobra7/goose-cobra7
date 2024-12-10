#define count 5
#define BUTTON 2 // button pin number
#define LED 13 // LED pin number
#define DELEY 1000 // delay time in milliseconds

void setup() 
{
    
    pinMode(LED, OUTPUT); // sets the digital pin 13 as output
    pinMode(BUTTON, INPUT_PULLUP); // sets the digital pin 14 as output
    serialbegin(9600);
    serial.printin("hello world");
}

void loop()
{
    if (digitalRead(BUTTON,LOW));//read the button and if it's pressed
    {
        digitalRead(LED,HIGH);// turns the LED on
        delay(DELEY);  //creates a timer
        for (int i = 0; i < count; i++)
        {
            digitalWrite(LED, HIGH);// turns the LED on
            delay(50);  //delays for 50 milliseconds
            digitalWrite(LED, LOW);   //turns the LED  off       
            delay(50); //delay for 50 milliseconds
            serial.printin(i)//prints the count of times the led blinked
            
        }
    }
    
}