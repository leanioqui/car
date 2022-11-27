      
#include<LiquidCrystal.h>

int pap (int mar);
int infrarrojo();
float ultrasonido();
int ang_servo(float a);
float tiempo_sonido;
float distancia = 0;
int correccion;
int ledCaida = 13;

int pap1 = A1;
int pap2 = A2;
int pap3 = A3;
int pap4 = A4;

unsigned long tiempoinicial = 0;
unsigned long tiempofinal = 0;
int tiemporeversa = 5000;

const int buzzer = A0;

#define leds_marcha 3
int leds_reversa = A5; 

LiquidCrystal LCD (11, 10, 9, 8, 7, 6);  

#define sens_infrarrojo 2
#define Echo 5
#define Trigger 4
#define servo 12

void setup() {
pinMode(pap1, OUTPUT);
pinMode(pap2, OUTPUT);
pinMode(pap3, OUTPUT);
pinMode(pap4, OUTPUT);

pinMode(servo, OUTPUT);
pinMode(leds_marcha, OUTPUT);
pinMode(leds_reversa, OUTPUT);

pinMode(sens_infrarrojo, INPUT);
pinMode(Trigger, OUTPUT); 
pinMode(Echo, INPUT);  
digitalWrite(Trigger, LOW);

LCD.begin(16,2);

}

void loop() {
 
 
 ang_servo(0);
  
 if(ultrasonido()>=20 && infrarrojo()==LOW){
      pap(1);
    }

    if(ultrasonido()<20 || infrarrojo()==HIGH){
      pap(0);//freno 
      ang_servo(45);
      tiempoinicial=millis();
    
      tiempofinal=0;
      while(millis()- tiempoinicial<=4000){
        pap(-1);
  

  } 

  }

    LCD.setCursor(0,0);
    LCD.print("DIST:");
    LCD.print(ultrasonido());
    LCD.print("cm");

}
float ultrasonido(){
 leds_reversa = LOW;
 digitalWrite(Trigger, HIGH);
 delayMicroseconds(100);           /*pulso de 100us*/
 digitalWrite(Trigger, LOW);
 tiempo_sonido = pulseIn(Echo, HIGH);
 distancia = tiempo_sonido/58.2 ;

return distancia;  
}

int infrarrojo(){
leds_reversa = LOW;
if(digitalRead(sens_infrarrojo)==HIGH){
   digitalWrite(ledCaida,HIGH);
   return HIGH;
  }
  else{
    digitalWrite(ledCaida,LOW);
    return LOW;
  }
}
  


int ang_servo(float ang){
  if(ang==45){
  digitalWrite(servo,HIGH);
  delayMicroseconds(1100);
  digitalWrite(servo,LOW);
  delayMicroseconds(8900);
  }
  if(ang==0){
    digitalWrite(servo,HIGH);
    delayMicroseconds(1500);
    digitalWrite(servo,LOW);
    delayMicroseconds(18500);
  }
}

int pap (int marcha){
  
switch (marcha){

  case -1: 

  digitalWrite(leds_reversa, HIGH);
  digitalWrite(buzzer,HIGH);
  
  digitalWrite(pap1, HIGH);
  digitalWrite(pap2, HIGH);
  digitalWrite(pap3, LOW);
  digitalWrite(pap4, LOW);
  delay(5);

  digitalWrite(pap1, LOW);
  digitalWrite(pap2, LOW);
  digitalWrite(pap3, LOW);
  digitalWrite(pap4, LOW);
  delay(5);

  digitalWrite(pap1, HIGH);
  digitalWrite(pap2, LOW);
  digitalWrite(pap3, LOW);
  digitalWrite(pap4, HIGH);
  delay(5);

  digitalWrite(pap1, LOW);
  digitalWrite(pap2, LOW);
  digitalWrite(pap3, LOW);
  digitalWrite(pap4, LOW);
  delay(5);

  digitalWrite(pap1, LOW);
  digitalWrite(pap2, LOW);
  digitalWrite(pap3, HIGH);
  digitalWrite(pap4, HIGH);
  delay(5);

  digitalWrite(pap1, LOW);
  digitalWrite(pap2, LOW);
  digitalWrite(pap3, LOW);
  digitalWrite(pap4, LOW);
  delay(5);

  digitalWrite(pap1, LOW);
  digitalWrite(pap2, HIGH);
  digitalWrite(pap3, HIGH);
  digitalWrite(pap4, LOW);
  delay(5);

  digitalWrite(pap1, LOW);
  digitalWrite(pap2, LOW);
  digitalWrite(pap3, LOW);
  digitalWrite(pap4, LOW);
  delay(5);

  break;

  case 0:
  
  digitalWrite(buzzer,LOW);
  
  digitalWrite(pap1, HIGH);
  digitalWrite(pap2, HIGH);
  digitalWrite(pap3, HIGH);
  digitalWrite(pap4, HIGH);

  break;

  case 1:

  digitalWrite(leds_marcha, HIGH);
  digitalWrite(buzzer,LOW);

  digitalWrite(pap1, LOW);
  digitalWrite(pap2, HIGH);
  digitalWrite(pap3, HIGH);
  digitalWrite(pap4, LOW);
  delay(5);

  digitalWrite(pap1, LOW);
  digitalWrite(pap2, LOW);
  digitalWrite(pap3, LOW);
  digitalWrite(pap4, LOW);
  delay(5);

  digitalWrite(pap1, LOW);
  digitalWrite(pap2, LOW);
  digitalWrite(pap3, HIGH);
  digitalWrite(pap4, HIGH);
  delay(5);

  digitalWrite(pap1, LOW);
  digitalWrite(pap2, LOW);
  digitalWrite(pap3, LOW);
  digitalWrite(pap4, LOW);
  delay(5);

  digitalWrite(pap1, HIGH);
  digitalWrite(pap2, LOW);
  digitalWrite(pap3, LOW);
  digitalWrite(pap4, HIGH);
  delay(5);

  digitalWrite(pap1, LOW);
  digitalWrite(pap2, LOW);
  digitalWrite(pap3, LOW);
  digitalWrite(pap4, LOW);
  delay(5);

  digitalWrite(pap1, HIGH);
  digitalWrite(pap2, HIGH);
  digitalWrite(pap3, LOW);
  digitalWrite(pap4, LOW);
  delay(5);

  digitalWrite(pap1, LOW);
  digitalWrite(pap2, LOW);
  digitalWrite(pap3, LOW);
  digitalWrite(pap4, LOW);
  delay(5);

  break;
}
  }


  
