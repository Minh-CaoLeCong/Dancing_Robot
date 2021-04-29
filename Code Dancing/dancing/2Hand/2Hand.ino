int c;
void setup()   
{  
    pinMode(LED_BUILTIN, OUTPUT);  
    Serial.begin(9600);  
}  
  
void loop()   
{  
    if (Serial.available() > 0)   
    {  
        char c = Serial.read();  
        if (c == '1')   
        {  
            digitalWrite(LED_BUILTIN, HIGH);  
        } else if (c == '0')   
        {  
            digitalWrite(LED_BUILTIN, LOW);  
        }  
    }  
}  
