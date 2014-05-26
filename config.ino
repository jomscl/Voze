/*
Descripciones de comportamientos
- SW Intermitente Izquierdo: Rele Intermitente izquierdo + M 170:1    OK
- SW Intermitente Derecho:   Rele Intermitente Derecho +   M 180:1    OK
- Combinados (Hazzard)                                     M 120:1    OK?
- SW Puerta:                 Rele Luz interior +           M 190:1 + 160:1
- SW Maleta:                                               M 1a0:1    OK
- AN Velocidad:                                            M 10vel,amp OK
- AN Consumo:                                              M 10vel,amp OK
- SW Luz alta:               Rele Luz alta +               M 150:1    OK
-                            Rele Luz estacionamiento      M 140:1    OK
-                            Rele Luz baja                 M 130:1
-                            Rele Reversa                  M 1c0:1
-                            Rele Boost                    M 1d0:1
-                            Rele Ignicion                 M 1b0:1
-                            Rele Luz interior             M 160:1
-

*/


// pines físicos de entradas
#define I1 A4 // SW Intermitente izquierdo
#define I2 A5 // SW Intermitente derecho
#define I3 10 // SW Puerta
#define I4 11 // SW Maleta
#define I5 A7 
#define I6 A6
#define I7 A0 // velocidad
#define I8 A1 // consumo
#define I9 A2 // SW Luz Alta
#define I10 A3 

void configEntradas(){
  int i=0;
  creaEntrada(i,I1,0,B00000011,2,'7');i++;  
  creaEntrada(i,I2,0,B00010011,2,'8');i++;
  creaEntrada(i,I3,1,B00100101,1,'9');i++;
  creaEntrada(i,I4,1,B11110001,1,'a');i++;
  creaEntrada(i,I9,0,B00110011,2,'5');i++;
  creaEntrada(i,I6,0,B11110001,0,'0');i++;
  creaEntrada(i,I7,0,B11110001,0,'0');i++;
  creaEntrada(i,I8,0,B11110001,0,'0');i++;
  
  creaEntradaAnalog(0,I7,0);
  creaEntradaAnalog(1,I8,1);
}

void creaEntrada(byte pos, byte pin, boolean tipo, byte accion, byte transmitir, byte subTipo){
  entradas[pos].pin=pin;
  entradas[pos].estado=0;
  entradas[pos].estadoAnt=0;
  entradas[pos].tipo=tipo;
  entradas[pos].accion=accion;
  entradas[pos].transmitir=transmitir;
  entradas[pos].subTipo=subTipo;
  pinMode(entradas[pos].pin,INPUT_PULLUP);
}

void creaEntradaAnalog(byte pos, byte pin, byte algoritmo){
  entradasAnalog[pos].pin=pin;
  entradasAnalog[pos].algoritmo=algoritmo;
  entradasAnalog[pos].medicion=0;
  entradasAnalog[pos].valor=0;
  pinMode(entradasAnalog[pos].pin,INPUT);
}

#define O1 12 // Rele Intermitente izquierdo
#define O2 2  // Rele Intermitente Derecho
#define O3 3  // Rele Luz interior
#define O4 4  // Rele Luz alta
#define O5 5  // Rele Reversa. Rele conectado a GND
#define O6 6  
#define O7 7  // Rele Boost. Rele conectado a GND
#define O8 8  // Rele Luz baja
#define O9 9  // Rele Ignicion. Rele conectado a GND
#define O10 13  // Rele Luz estacionamiento

void configSalidas(){
  int i=0;
  creaSalida(i,O1,0,B00000001);i++;  
  creaSalida(i,O2,0,B00000001);i++;
  creaSalida(i,O3,0,B00000010);i++;
  creaSalida(i,O4,0,B00000000);i++;
  creaSalida(i,O5,0,B00000000);i++;
  creaSalida(i,O6,0,B00000000);i++;
  creaSalida(i,O7,0,B00000000);i++;
  creaSalida(i,O8,0,B00000000);i++;
  creaSalida(i,O9,0,B00000000);i++;
  creaSalida(i,O10,0,B00000000);i++;
}

void creaSalida(byte pos, byte pin, boolean estadoInicial, byte accion){
  salidas[pos].pin=pin;
  salidas[pos].estado=estadoInicial;
  salidas[pos].accion=accion;
  pinMode(salidas[pos].pin,OUTPUT);
  escribeCanal(pos);
}


int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
