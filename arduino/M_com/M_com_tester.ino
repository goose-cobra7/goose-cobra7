void setup() {
    //for pins
        // Initialize sensor pins
    pinMode(digi1, INPUT);
    pinMode(digi2, INPUT);
    pinMode(digi3, INPUT);
    pinMode(digi4, INPUT);
    pinMode(digi5, INPUT);
    //engine settings
    pinMode(in1, OUTPUT); //motor 1
    pinMode(in2, OUTPUT); //motor 1
    pinMode(ENA, OUTPUT); //control motor 1
    pinMode(in3, OUTPUT); //motor 2
    pinMode(in4, OUTPUT); //motor 2
    pinMode(ENB, OUTPUT); //control motor 2
    Serial.begin(9600);
}

void loop() {
    
}

void run_circle()
{

}