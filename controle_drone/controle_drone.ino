#include <VirtualWire.h>
int eixo_X = A0;
int eixo_Y = A1;
int Up = 2;
int Down = 3;
int AntiHor = 4;
int Hor = 5;

char *letra = "S";

void setup(){

  Serial.begin(9600);

  pinMode(Up, INPUT_PULLUP);
  pinMode(Down, INPUT_PULLUP);
  pinMode(AntiHor, INPUT_PULLUP);
  pinMode(Hor, INPUT_PULLUP);
  
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_set_tx_pin(1);

}

void loop(){

  if((analogRead(eixo_X)) == 1023)letra = "F";
  else if((analogRead(eixo_X)) == 0)letra = "B";
  else if((analogRead(eixo_Y)) == 0)letra = "L";
  else if((analogRead(eixo_Y)) == 1023)letra = "R";
  else if((digitalRead(Up)) == LOW)letra = "U";
  else if((digitalRead(Down)) == LOW)letra = "D";
  else if((digitalRead(AntiHor)) == LOW)letra = "A";
  else if((digitalRead(Hor)) == LOW)letra = "H";
  else letra = "S";

if(letra == "F")
Serial.println("FRENTE");
else if(letra == "B")
Serial.println("TRAS");
else if(letra == "L")
Serial.println("ESQUERDA");
else if(letra == "R")
Serial.println("DIREITA");
else if(letra == "U")
Serial.println("SOBE");
else if(letra == "D")
Serial.println("DESCE");
else if(letra == "A")
Serial.println("GIRANDO SENTIDO ANTI HORARIO");
else if(letra == "H")
Serial.println("GIRANDO SENTIDO HORARIO");
else if(letra == "S")
Serial.println("ESTABILIZADO");

  for(int i=0; i<3; i++){
    vw_send((uint8_t*)letra, strlen(letra));
    vw_wait_tx();
    delay(10);
  }
}
