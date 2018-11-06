int LED_1 = 2;
int LED_2 = 3;
int LED_3 = 4;
int randomNumber;



void setup()
{
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop()
{ 
  randomNumber = random(2,5);
  digitalWrite(randomNumber, HIGH);
  delay(100);
  digitalWrite(randomNumber, LOW);
}
