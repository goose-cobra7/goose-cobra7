void setup()
{
    pinMode(13, OUTPUT); //2
    pinMode(12, OUTPUT); //1
    pinMode(2, INPUT_PULLUP); //1
    pinMode(3, INPUT_PULLUP); //2
}

void loop()
{
    if (digitalRead(2) == 0) // close
    {
        digitalWrite(12, HIGH);
        if (digitalRead(3) == 0)
        {
            digitalWrite(13, LOW);
        }else
        {
            digitalWrite(13, HIGH);
        }
    }else
    {
        digitalWrite(12, LOW);
    }
    
}