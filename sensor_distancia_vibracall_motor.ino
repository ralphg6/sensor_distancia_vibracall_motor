//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

#define LED_VERMELHO 2
#define LED_AMARELO 3
#define LED_VERDE 4

#define  pinSensor1T 7
#define  pinSensor1E 6

unsigned long distance1;

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic1(pinSensor1T, pinSensor1E);

void setup() {
  Serial.begin(9600);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_AMARELO, HIGH);
  digitalWrite(LED_VERDE, HIGH);
  delay(1000);
}

// the loop routine runs over and over again forever:
void loop() {

  int microseconds = ultrasonic1.timing();

  Serial.print("Microsegundos: ");
  Serial.print(microseconds);
 
  distance1 = ultrasonic1.convert(microseconds, Ultrasonic::CM);
  
  Serial.print(" Distância: ");
  Serial.println(distance1);

  if (distance1 > 100) {

    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, HIGH);

  } else if (distance1 > 50) {

    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERDE, LOW);
    
  } else {
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, LOW);
  }
  delay(200);
}
