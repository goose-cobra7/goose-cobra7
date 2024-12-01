void setup()
{
    //צפון דרום
    pinMode(2, OUTPUT);//green
    pinMode(3, OUTPUT); //yellow
    pinMode(4, OUTPUT); //red
    //צזרח מערב
    pinMode(5, OUTPUT);//green
    pinMode(6, OUTPUT);//yellow
    pinMode(7, OUTPUT);//red
    pinMode(10, INPUT_PULLUP); //1
    pinMode(11, INPUT_PULLUP); //2
}

void loop()
{
    if (digitalRead(10) == 0)
    {
        if (digitalRead(11) == 0)
        {
            //צפון דרום
            digitalWrite(2, LOW);//green
            digitalWrite(3, LOW);//yellow
            digitalWrite(4, HIGH);//red
            //צזרח מערב
            digitalWrite(5, LOW);//green
            digitalWrite(6, LOW);//yellow
            digitalWrite(7, HIGH);//red
        }else
        {
            //צפון דרום
            digitalWrite(2, HIGH);//green
            digitalWrite(3, LOW);//yellow
            digitalWrite(4, LOW);//red
            //צזרח מערב
            digitalWrite(5, LOW);//green
            digitalWrite(6, LOW);//yellow
            digitalWrite(7, HIGH);//red
        }
        
    }else
    {
        if (digitalRead(11) == 0)
        {
            //צפון דרום
            digitalWrite(2, LOW);//green
            digitalWrite(3, LOW);//yellow
            digitalWrite(4, HIGH);//red
            //צזרח מערב
            digitalWrite(5, HIGH);//green
            digitalWrite(6, LOW);//yellow
            digitalWrite(7, LOW);//red
        }else
        {
            //צפון דרום
            digitalWrite(2, LOW);//green
            digitalWrite(3, LOW);//yellow
            digitalWrite(4, HIGH);//red
            //צזרח מערב
            digitalWrite(5, HIGH);//green
            digitalWrite(6, LOW); //yellow
            digitalWrite(7, LOW);//red
            delay(10000); //10 sec
           
            //צפון דרום
            digitalWrite(2, LOW);//green
            digitalWrite(3, HIGH);//yellow
            digitalWrite(4, HIGH);//red
            //צזרח מערב
            digitalWrite(5, LOW);//green
            digitalWrite(6, HIGH); //yellow
            digitalWrite(7, LOW);//red
            delay(5000); //10 sec
            
            //צפון דרום
            digitalWrite(2, HIGH);//green
            digitalWrite(3, LOW);//yellow
            digitalWrite(4, LOW);//red
            //צזרח מערב
            digitalWrite(5, LOW);//green
            digitalWrite(6, LOW); //yellow
            digitalWrite(7, HIGH);//red
            delay(10000); //10 sec
           
            //צפון דרום
            digitalWrite(2, LOW);//green
            digitalWrite(3, HIGH);//yellow
            digitalWrite(4, LOW);//red
            //צזרח מערב
            digitalWrite(5, LOW);//green
            digitalWrite(6, HIGH); //yellow
            digitalWrite(7, HIGH);//red
            delay(5000); //10 sec
        }
    }
}