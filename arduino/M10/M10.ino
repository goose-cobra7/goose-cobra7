//pin config engine
#define ENA 5
#define in1 6
#define in2 7
#define in3 8
#define in4 9
#define ENB 10

//pin config sensor
#define dig_left
#define dig_right
#define ana_left
#define ana_right

//wheel configuration
#define radios
//estimate RPM to volt
//voltage --> RPM
//speed = RPM^2*radius

//settings
#define slow_speed
#define high_speed
#define DELAY 100

//method configuration
#define digital 1
#define analoge_PC 2 //proportional
#define analoge_PDC 3 //proportional diffrential
#define configure_mode digital
//in digital speed is not proportional to the error
//
void setup() {
    pinMode(in1, OUTPUT); //motor 1
    pinMode(in2, OUTPUT); //motor 1
    pinMode(ENA, INPUT); //control motor right
    pinMode(in3, OUTPUT); //motor 2
    pinMode(in4, OUTPUT); //motor 2
    pinMode(ENB, INPUT); //control motor left
    pinMode(dig_left, INPUT); //digital left
    pinMode(dig_right, INPUT); //digital right
    pinMode(ana_left, INPUT); //analoge left
    pinMode(ana_right, INPUT); //digital right
    Serial.begin(9600);
}

void loop() {
    int sensor_left = digitalRead(dig_left);
    int sensor_right = digitalRead(dig_right);
    if (sensor_left == HIGH & sensor_right == LOW)
    {
        digital_right();
        delay(DELAY);
    }
    if (sensor_left == LOW & sensor_right == HIGH)
    {
        digital_left();
        delay(DELAY);
    }
    if (sensor_left == HIGH & sensor_right == HIGH)
    {
        digital_forward();
        delay(DELAY);
    }
}
void digital_right()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, slow_speed);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, high_speed);
}
void digital_left()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, high_speed);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, slow_speed);
}

void digital_forward()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, high_speed);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, high_speed);
}
void digital_revese()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ENA, high_speed);
    digitalWrite(in3,LOW);
    digitalWrite(in4, high_speed);
    analogWrite(ENB, NUM2);
}

void analog_right()
{

}

void analog_left()
{

}

void analog_forward()
{

}

