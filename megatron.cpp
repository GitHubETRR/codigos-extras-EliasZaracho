#include "megatron.h"


void Robot::Avanzar()  {
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, HIGH);
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, HIGH);
};
void Robot::Atras()    {
  digitalWrite(MOTOR1_A, HIGH);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_A, HIGH);
  digitalWrite(MOTOR2_B, LOW);
};
void Robot::Derecha()  {
  digitalWrite(MOTOR1_A, HIGH);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, HIGH);
};
void Robot::Izquierda(){
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, HIGH);
  digitalWrite(MOTOR2_A, HIGH);
  digitalWrite(MOTOR2_B, LOW);
};
void Robot::Frenado()  {
  digitalWrite(PWM_1, LOW);
  digitalWrite(PWM_2, LOW);
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, LOW);
};


int Robot::traer_distancia(int sensor){
    digitalWrite(Sensor[sensor].Trigger, HIGH);
    return (pulseIn(Sensor[sensor].Echo, HIGH)/CONVER_A_CM); 
};
