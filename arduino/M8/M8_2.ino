#define ENA 5
#define in1 6
#define in2 7
#define in3 8
#define in4 9
#define ENB 10



void setup() {
    pinMode(in1, OUTPUT); //motor 1
    pinMode(in2, OUTPUT); //motor 1
    pinMode(ENA, OUTPUT); //control motor 1
    pinMode(in3, OUTPUT); //motor 2
    pinMode(in4, OUTPUT); //motor 2
    pinMode(ENB, OUTPUT); //control motor 2
    Serial.begin(9600);
}

void loop() {
    int NUM1 = 90;
    int NUM2 = 110;     
    digitalWrite(in1,LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ENA, NUM1);
    digitalWrite(in3,LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ENB, NUM2);
    Serial.print((NUM2*5)/256);
    Serial.print("---");
    Serial.println((NUM2*5)/256);
}