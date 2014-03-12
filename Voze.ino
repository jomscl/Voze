// Software creado según modelo Conceptual
// 

#include <Metro.h> //Include Metro library
#include "SoftwareSerial.h"
#include "EngineProtocol.h"
//#include "libraries/arduino_serial_message_protocol_master/EngineProtocol.h"

// variables de tiempo
Metro timer = Metro(100);

// configuraciónes de estructuras en memoria
#define canalesIn 7 // 7 para 8 canales
#define canalesInAnalog 1 
#define canalesOut 9

// definiciones de tiempos, 1= 100ms
#define tiempoEnclavamiento 50 
#define tiempoPulso 2

byte contadorIntermitente=0;
#define tiempoIntermitente 3
boolean estadoIntermitente=false;

byte contadorAnalog=0;
#define tiempoAnalog 10 // para que mande los valores analogicos una vez por segundo

struct STin{
  byte pin;
  byte estado; // 0 apagado, 1 encendido
  byte estadoAnt;
  boolean tipo; // 0 lectura digital en puerto analogico, 1 digital
  byte accion; /* bit 0: 1= encendido normal,  0= encendido inverso
                  bit 1: 1= enclavamiento, 0= temporal
                  bit 2: 1= pulso, 0 = temporal
                  bit 3:
                  bit 4: bit 0 de direccion de salida. Si se pone 1111 no esta apuntado a ningun canal
                  bit 5: bit 1 de direccion
                  bit 6: bit 2 de direccion
                  bit 7: bit 3 de direccion  */
  unsigned int tiempo; // contador para pulsos y enclavamiento
  byte transmitir; // 1= transmite, 0 = no transmite
  byte subTipo; // el parametro de transmicion al tablet
};

STin entradas[canalesIn+1];

struct STinAnalog{ // estructura para guardar los puertos analógicos
  byte pin;
  byte algoritmo; // 0= algoritmo de velocidad, 1= Algoritmo de amperes
  int medicion;
  int valor;  
};

STinAnalog entradasAnalog[canalesInAnalog+1];

struct STout{
  byte pin;
  boolean estado; // 0 apagado, 1 encendido
  byte accion; // bit 0: 0= salida normal, 1= salida intermitente
  unsigned int tiempo; // contador del tiempo para reles pulsantes
};

STout salidas[canalesOut+1];

// parametros de comunicacion
#define ADDRESS "0001" // la direccion del auto
#define BAUD_RATE 19200
#define ADDRESSTO "0002" // la direccion de destino, en este caso, el tablet

MessageBuilder mb;
Engine engine(BAUD_RATE,ADDRESS);

void setup() {

  configEntradas();
  configSalidas();
  
  engine.setup();
  engine.setMessageProcessingFuction(&processMessage);
  
  //Serial.begin(9600);
  //Serial.println("OK");
}

void loop() {
  engine.run();
  
  if (timer.check()==1){
    leeCanales();
    //debugEntradas();
    leeCanalesAnalog();
    //debugEntradasAnalog();
    
    procesaCanales();
  
    // debugSalidas();
    escribeCanales();
    
    revisaAnalog();
    cuentaIntermitente();
  }
}

void cuentaIntermitente(){
  if (contadorIntermitente==0){
    contadorIntermitente=tiempoIntermitente + 1;
    estadoIntermitente!=estadoIntermitente;
  }
  contadorIntermitente--;
}
