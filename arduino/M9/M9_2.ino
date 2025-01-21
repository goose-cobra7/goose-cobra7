#define D2 2

void setup() {
    pinMode(D2, INPUT);
    pinMode(A0, INPUT);
    Serial.begin(9600);
}

void loop() {
    int ana = analogRead(A0); //get the value of sensor in analog mode
    Serial.print(ana); //print the value analoge
    Serial.print(" - "); //print seperator between 2 values
    int dig = 750*digitalRead(D2); //get the value of sensor in digital mode
    //and multiply it by 700 to egt it on the same range as the analog
    Serial.println(dig); //print the value of sensor in digital mode
    delay(100); 
}