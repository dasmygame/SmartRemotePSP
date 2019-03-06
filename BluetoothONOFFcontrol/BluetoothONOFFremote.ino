/*
Arduino Button Remote using Serial Commands


waits for a character on serial 
and in case of a desirable input, it turns an LED on/off.

Possible string values:
a (turns the LED on)
b (turns the LED off)
*/

char junk;
String inputString="";

void setup()                    // run once, when the sketch starts
{
 Serial.begin(9600);            // set the baud rate to 9600, Serial Monitor should be the same
 pinMode(13, OUTPUT);
}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //makes string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // clear serial buffer
    if(inputString == "a"){         //in case of 'a' turn the LED on
      digitalWrite(13, HIGH);  
    }else if(inputString == "b"){   //in case of 'b' turn the LED off
      digitalWrite(13, LOW);
    }
    inputString = "";
  }
}
