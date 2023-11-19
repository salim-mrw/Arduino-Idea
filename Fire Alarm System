#define pin_A0 A0
#define led_green 13
#define buzzer 5

int Rate = 500;

void setup() {

  pinMode(buzzer,OUTPUT);
  pinMode(led_green,OUTPUT);
  pinMode(pin_A0,INPUT);

  Serial.begin(9600);

}

void loop() {

  int val_A0 = analogRead(pin_A0);

  Serial.println(val_A0);

  if(val_A0 >= Rate){

    digitalWrite(led_green,HIGH);
    delay(500);
    
    tone(buzzer,800);
    delay(500);
    
  }

  if(val_A0 < Rate){

    digitalWrite(led_green,LOW);
    delay(500);
    
    noTone(buzzer);
    delay(500);
  
  }
  
}
