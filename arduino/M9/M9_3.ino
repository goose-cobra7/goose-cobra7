#define D2 2
#define D4 4

void setup() {
    pinMode(D2, INPUT);
    pinMode(A0, INPUT);
    pinMode(D4, INPUT);
    pinMode(A2, INPUT);
    Serial.begin(9600);
}

void loop() {
    int digi_1 = digitalRead(D2); 
    int digi_2 = digitalRead(D4);
    if (digi_1 == 0 && digi_2 == 0) //white
    {
        //forward
        Serial.println("forward");
    }
    if (digi_1 == 1 && digi_2 == 0) //black on left
    {
        //left
        Serial.println("left");
    }
    if (digi_1 == 0 && digi_2 == 1) //black on right
    {
        //right
        Serial.println("right");
    }
    if (digi_1 == 1 && digi_2 == 1) //black
    {
        //stop
  
    }
    delay(300);
}