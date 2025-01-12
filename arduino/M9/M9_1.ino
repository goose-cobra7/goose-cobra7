#define D2 2

void setup() {
    pinMode(D2, INPUT);
    pinMode(13, OUTPUT);
}

void loop() {
    if (digitalRead(D2) == HIGH) {
        digitalWrite(13, HIGH);
    } else {
        digitalWrite(13, LOW);
    }
    delay(100); // wait for 100 milliseconds before next check
}