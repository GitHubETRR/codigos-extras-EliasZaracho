#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2,3);

#define PWM_L 10
#define IN_L_1 9
#define IN_L_2 8
#define IN_R_1 7
#define IN_R_2 6
#define PWM_R 5

#define Adelante                        70 //F
#define Atras                           66 //B
#define Izquierda                       76 //L
#define Derecha                         82 //R
#define Detener                         83 //S
#define MaxVel                         113 //q
#define MedAltVel                       56 //8
#define MedVel                          53 //5
#define MedBajVel                       52 //4
#define Diagonal_Adelante_Izquierda     71 //G
#define Diagonal_Adelante_Derecha       73 //I
#define Diagonal_Atras_Izquierda        72 //H
#define Diagonal_Atras_Derecha          74 //J

char comando = Detener;

void setup() {
  bluetooth.begin(38400);
  pinMode(PWM_L, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(IN_L_1, OUTPUT);
  pinMode(IN_L_2, OUTPUT);
  pinMode(IN_R_1, OUTPUT);
  pinMode(IN_R_2, OUTPUT);

  digitalWrite(PWM_L, 1);
  digitalWrite(PWM_R, 1);
}

void loop() {
  if(bluetooth.available()){
    comando = bluetooth.read();
  }
  switch(comando){
    case Detener:
      digitalWrite(IN_L_1, 0);
      digitalWrite(IN_L_2, 0);
      digitalWrite(IN_R_1, 0);
      digitalWrite(IN_R_2, 0);
    break;
    
    case Adelante:
      digitalWrite(IN_L_1, 1);
      digitalWrite(IN_L_2, 0);
      digitalWrite(IN_R_1, 1);
      digitalWrite(IN_R_2, 0);
    break;

    case Atras:
      digitalWrite(IN_L_1, 0);
      digitalWrite(IN_L_2, 1);
      digitalWrite(IN_R_1, 0);
      digitalWrite(IN_R_2, 1);
    break;

    case Izquierda:
      digitalWrite(IN_L_1, 0);
      digitalWrite(IN_L_2, 1);
      digitalWrite(IN_R_1, 1);
      digitalWrite(IN_R_2, 0);
    break;

    case Derecha:
      digitalWrite(IN_L_1, 1);
      digitalWrite(IN_L_2, 0);
      digitalWrite(IN_R_1, 0);
      digitalWrite(IN_R_2, 1);
    break;
  }
}
