#include<Servo.h>
#define trigPin 10
#define echoPin 11
#define ON 1
#define OFF 0

Servo motor;
int i;
int j;


void setup(){

pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
motor.attach(9);
motor.write(0);
delay(500);
Serial.begin(9600);

}

void loop()
{

j=0;
  
Serial.print(sound());
Serial.print("  ");
  if (sound() < 20){

for(i=0;i<180;++i){

  motor.write(i);
  
}


while(sound()<20){

  j++;
}

for(i=180;i>0;--i){

  motor.write(i);
  
  
}

  }

  delay(1000);
}

int sound(void){

long time;
int length;

digitalWrite(trigPin,OFF);

delay(2);
digitalWrite(trigPin,ON);
delay(10);
digitalWrite(trigPin,OFF);

time = pulseIn(echoPin,ON);

length = (time * 0.0332)/2;

  return length;
}
