int pinoRa = 11; 
int pinoGa = 10; 
int pinoBa = 9; 

int pinoRb = 7; 
int pinoGb = 6; 
int pinoBb = 5; 

int pinoRc = 4; 
int pinoGc = 3; 
int pinoBc = 2; 

#define COMMON_ANODE 

int timeRed = 15000;
int timeYellow = 5000;
int timeGreen = 10000;
 
void setup(){
  delay(5000);
  pinMode(pinoRa, OUTPUT); 
  pinMode(pinoGa, OUTPUT); 
  pinMode(pinoBa, OUTPUT); 
  pinMode(pinoRb, OUTPUT); 
  pinMode(pinoGb, OUTPUT); 
  pinMode(pinoBb, OUTPUT); 
  pinMode(pinoRc, OUTPUT); 
  pinMode(pinoGc, OUTPUT); 
  pinMode(pinoBc, OUTPUT); 
}
 
void loop(){
  setColor(255, 0, 0); //PARÂMETROS PARA PRODUZIR A COR VERMELHA
  delay(timeRed); //INTERVALO DE 1 SEGUNDO
  setColor(0, 255, 0); //PARÂMETROS PARA PRODUZIR A COR VERDE
  delay(timeYellow); //INTERVALO DE 1 SEGUNDO
  setColor(255, 255, 0); //PARÂMETROS PARA PRODUZIR A COR AMARELA
  delay(timeGreen); //INTERVALO DE 1 SEGUNDO
}
 void setColor(int vermelho, int verde, int azul){
  
  #ifdef COMMON_ANODE 
    vermelho = 255 - vermelho;
    verde = 255 - verde; 
    azul = 255 - azul; 
  #endif
  analogWrite(pinoRa, vermelho); 
  analogWrite(pinoGa, verde); 
  analogWrite(pinoBa, azul); 

  analogWrite(pinoRb, vermelho); 
  analogWrite(pinoGb, verde); 
  analogWrite(pinoBb, azul); 

  analogWrite(pinoRc, vermelho); 
  analogWrite(pinoGc, verde); 
  analogWrite(pinoBc, azul); 
}
