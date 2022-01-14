#include <VirtualWire.h>

int FD = 2;
int FE = 3;
int TD = 4;
int TE = 5;

char letra = "S";

void setup(){

Serial.begin(9600);
vw_set_ptt_inverted(true);
vw_setup(2000);
vw_set_rx_pin(6);
vw_rx_start();

pinMode(FD, OUTPUT);
pinMode(FE, OUTPUT);
pinMode(TD, OUTPUT);
pinMode(TE, OUTPUT);

}

void loop(){

uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

if(vw_get_message(buf, &buflen))
  {
    letra = buf[0];
   if(letra=='F'){
    analogWrite(FD, 150);
    analogWrite(FE, 150);
    analogWrite(TD, 250);
    analogWrite(TE, 250);
   }
else if(letra=='B'){
  analogWrite(FD, 250);
  analogWrite(FE, 250);
  analogWrite(TD, 150);
  analogWrite(TE, 150);
}
else if(letra=='L'){
  analogWrite(FD, 250);
  analogWrite(FE, 150);
  analogWrite(TD, 250);
  analogWrite(TE, 150);
}
else if(letra=='R'){
  analogWrite(FD, 150);
  analogWrite(FE, 250);
  analogWrite(TD, 150);
  analogWrite(TE, 250);
}
else if(letra=='U'){
  analogWrite(FD, 255);
  analogWrite(FE, 255);
  analogWrite(TD, 255);
  analogWrite(TE, 255);
}
else if(letra=='D'){
  analogWrite(FD, 155);
  analogWrite(FE, 155);
  analogWrite(TD, 155);
  analogWrite(TE, 155);
}
else if(letra=='A'){
  analogWrite(FD, 250);
  analogWrite(FE, 150);
  analogWrite(TD, 150);
  analogWrite(TE, 250);
}
else if(letra=='H'){
  analogWrite(FD, 150);
  analogWrite(FE, 250);
  analogWrite(TD, 250);
  analogWrite(TE, 150);
}
else if(letra=='S'){
  analogWrite(FD, 200);
  analogWrite(FE, 200);
  analogWrite(TD, 200);
  analogWrite(TE, 200);
}
 }
  }
