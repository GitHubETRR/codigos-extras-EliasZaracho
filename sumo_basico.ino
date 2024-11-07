#include "megatron.h"

Robot megatron;

void setup(){ //únicamente cuando enciende hacemos
  pinMode(IR_FD,INPUT);
  pinMode(IR_FI,INPUT);
  pinMode(MOTOR1_A,OUTPUT);
  pinMode(MOTOR1_B,OUTPUT);
  pinMode(MOTOR2_A,OUTPUT);
  pinMode(MOTOR2_B,OUTPUT);
  pinMode(TRIGGER_1,OUTPUT);
  pinMode(TRIGGER_2,OUTPUT);
  pinMode(LUZ_SEGURIDAD,OUTPUT);
  
  digitalWrite(TRIGGER_1, LOW);
  digitalWrite(TRIGGER_2, LOW);
  digitalWrite(LUZ_SEGURIDAD, LOW);

  for(int i=0;i<VECES_SEGURIDAD;i++){
    digitalWrite(LUZ_SEGURIDAD,HIGH);
    delay(TIME_SEGURIDAD);
    digitalWrite(LUZ_SEGURIDAD,LOW);
    delay(TIME_SEGURIDAD);
  }
  digitalWrite(LUZ_SEGURIDAD,LOW);
}



void loop(){ 
    //caso 1
    while(megatron.traer_distancia(0)> DIST_VISION && megatron.traer_distancia(1) > DIST_VISION && digitalRead(IR_FD)== NEGRO && digitalRead(IR_FI)== NEGRO) {
      analogWrite(PWM_1,VEL_GIRO);
      analogWrite(PWM_2,VEL_GIRO);
      megatron.Derecha();
      delay(TIME_GIRO);
  }

    //caso 2
  if(distancia_frontal_1<=DIST_VISION && distancia_frontal_2<=DIST_VISION){
    megatron.Izquierda();
    delay(TIME_GIRO);
    while(distancia_frontal_1<=DIST_VISION && distancia_frontal_2<=DIST_VISION && digitalRead(IR_FD)== NEGRO && digitalRead(IR_FI)== NEGRO){ //si distancia frontal es la menor
      analogWrite(PWM_1,VELOCIDAD);
      analogWrite(PWM_2,VELOCIDAD);
    megatron.Avanzar();
    }
    if(digitalRead(IR_FD)== BLANCO || digitalRead(IR_FI)== BLANCO){
      while(digitalRead(IR_FD)== BLANCO || digitalRead(IR_FI) == BLANCO){
        analogWrite(PWM_1,VELOCIDAD);
        analogWrite(PWM_2,VELOCIDAD);
        megatron.Atras();
        megatron.Frenado();
      }
    }
  }
}
