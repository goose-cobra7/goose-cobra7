#define ENA 6
#define in1 5
#define in2 4
#define ctrl A0
void setup() {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(A0, INPUT);
    Serial.begin(9600);
}
int X = 0;
int NUM = 0;
void loop() {
    NUM = analogRead(A0);
    X = NUM/4;
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(6, X) ;
    Serial.println(X);
}