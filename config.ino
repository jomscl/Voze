/*
Descripciones de comportamientos
- SW Intermitente Izquierdo: Rele Intermitente izquierdo + M 170:1
- SW Intermitente Derecho:   Rele Intermitente Derecho +   M 180:1
- Combinados (Hazzard)                                     M 120:1
- SW Puerta:                 Rele Luz interior +           M 190:1 
- SW Maleta:                                               M 1a0:1
- AN Velocidad:                                            M 10vel,amp
- AN Consumo:                                              M 10vel,amp
- SW Luz alta:               Rele Luz alta +               M 150:1
-                            Rele Luz estacionamiento      M 140:1
-                            Rele Luz baja                 M 130:1
-                            Rele Reversa                  M 1c0:1
-                            Rele Boost                    M 1d0:1
-                            Rele Ignicion                 M 1b0:1
-                            Rele Luz interior             M 160:1
-

*/


// pines físicos de entradas
#define I1 A4
#define I2 A5
#define I3 10
#define I4 11
#define I5 A7 
#define I6 A6
#define I7 A0
#define I8 A1
#define I9 A2 // velocidad
#define I10 A3 // consumo

void configEntradas(){
  int i=0;
  creaEntrada(i,I1,0,B00000001,1);i++;  
  creaEntrada(i,I2,0,B00010000,0);i++;
  creaEntrada(i,I3,1,B00100011,1);i++;
  creaEntrada(i,I4,1,B00110101,0);i++;
  creaEntrada(i,I5,0,B01000101,0);i++;
  creaEntrada(i,I6,0,B11110001,0);i++;
  creaEntrada(i,I7,0,B01100001,0);i++;
  creaEntrada(i,I8,0,B01110001,0);i++;
  //creaEntrada(i,I9,0,B10000001,0);i++;
  //creaEntrada(i,I10,0,B10010001,0);i++;
  
  creaEntradaAnalog(0,I9,0);
  creaEntradaAnalog(1,I10,1);
}

void creaEntrada(byte pos, byte pin, boolean tipo, byte accion, byte transmitir){
  entradas[pos].pin=pin;
  entradas[pos].estado=0;
  entradas[pos].estadoAnt=0;
  entradas[pos].tipo=tipo;
  entradas[pos].accion=accion;
  entradas[pos].transmitir=transmitir;
  pinMode(entradas[pos].pin,INPUT_PULLUP);
}

void creaEntradaAnalog(byte pos, byte pin, byte algoritmo){
  entradasAnalog[pos].pin=pin;
  entradasAnalog[pos].algoritmo=algoritmo;
  entradasAnalog[pos].medicion=0;
  entradasAnalog[pos].valor=0;
  pinMode(entradasAnalog[pos].pin,INPUT);
}

#define O1 12 
#define O2 2
#define O3 3
#define O4 4
#define O5 5
#define O6 6
#define O7 7
#define O8 8 
#define O9 9 
#define O10 13  

void configSalidas(){
  int i=0;
  creaSalida(i,O1,0);i++;  
  creaSalida(i,O2,0);i++;
  creaSalida(i,O3,0);i++;
  creaSalida(i,O4,0);i++;
  creaSalida(i,O5,0);i++;
  creaSalida(i,O6,0);i++;
  creaSalida(i,O7,0);i++;
  creaSalida(i,O8,0);i++;
  creaSalida(i,O9,0);i++;
  creaSalida(i,O10,0);i++;
}

void creaSalida(byte pos, byte pin, boolean estadoInicial){
  salidas[pos].pin=pin;
  salidas[pos].estado=estadoInicial;
  pinMode(salidas[pos].pin,OUTPUT);
  escribeCanal(pos);
}


int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
