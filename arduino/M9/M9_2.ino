#define D2 2

void setup() {
    pinMode(D2, INPUT);
    pinMode(A0, INPUT);
    Serial.begin(9600);
}

void loop() {
    int ana = analogRead(A0);
    Serial.print(ana);
    Serial.print(" - ");
    int dig = 750*digitalRead(D2);
    Serial.println(dig);
    delay(100);
}