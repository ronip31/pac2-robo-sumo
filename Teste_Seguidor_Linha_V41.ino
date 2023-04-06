#include <SharpIR.h>
#include <stdio.h>

#define ir A2 //PINO ANALÓGICO EM QUE O SENSOR ESTÁ CONECTADO
#define model 1080 //DETERMINA O MODELO DO SENSOR (1080 PARA O MODELO 2Y0A21Y OU 20150 PARA O MODELO 2Y0A02Y)
#define sensorD A0
#define sensorE A1
#define D1 2
#define D2 3
#define E3 6
#define E4 7
#define ENA 4
#define ENB 5

SharpIR SharpIR(ir, model); //PASSA OS PARÂMETROS PARA A FUNÇÃO (PINO ANALÓGICO, MODELO DO SENSOR)

void setup() {
  Serial.begin(9600); //INICIALIZA A SERIAL
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(E3,OUTPUT);
  pinMode(E4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  analogWrite(ENA,130);
  analogWrite(ENB,200);

}

void loop() {

 int distancia = SharpIR.getDistance();  //VARIÁVEL RECEBE A DISTÂNCIA MEDIDA
  
  Serial.print("Distância medida: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(distancia); //IMPRIME NA SERIAL A DISTÂNCIA MEDIDA PELO SENSOR
  Serial.println("cm"); //IMPRIME O TEXTO NA SERIAL
  delay(500); //INTERVALO DE 500 MILISSEGUNDOS

  int direito = analogRead(sensorD);
  int esquerdo = analogRead(sensorE);  
  Serial.print(direito);
  Serial.print("\n");
  Serial.print(esquerdo);
  Serial.print("\n");

 /*if(direito < 800 && esquerdo < 800 ){
   
     digitalWrite(D1, LOW);
    digitalWrite(D2, 180);
    digitalWrite(E3, LOW);
    digitalWrite(E4, 180); 
    Serial.print("Para tras");
    delay(20);   
 }*/
 if(direito < 799 && esquerdo < 799 ){
   
     digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(E3, LOW);
    digitalWrite(E4, LOW); 
 Serial.print("Parado ");
 }
    else if(direito > 800 && esquerdo > 800 ){ 
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(E3, HIGH);
    digitalWrite(E4, LOW);
    Serial.print("Frente");  
  
}
}