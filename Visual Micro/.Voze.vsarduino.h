#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
//Board = Arduino Pro or Pro Mini w/ ATmega328 (5V, 16 MHz)
#define __AVR_ATmega328p__
#define __AVR_ATmega328P__
#define ARDUINO 150
#define ARDUINO_MAIN
#define __AVR__
#define __avr__
#define F_CPU 16000000L
#define __cplusplus
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__

#define __builtin_va_list
#define __builtin_va_start
#define __builtin_va_end
#define __DOXYGEN__
#define __attribute__(x)
#define NOINLINE __attribute__((noinline))
#define prog_void
#define PGM_VOID_P int
            
typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {;}

//
//
void leeCanales();
void leeCanal(int canal);
void debugEntradas();
void procesaCanales();
byte cAccion(byte i);
void leeCanalesAnalog();
int convierteVelocidad(int medicion);
int convierteAmpere(int medicion);
void debugEntradasAnalog();
void revisaAnalog();
void escribeCanales();
void escribeCanal(byte canal);
void debugSalidas();
void enviaEntrada(byte canal, boolean v);
void enviaEntradasAnalog();
void recibeOrdenes();
void processMessage(char flags, String address_from, char type,char sub_type,String data);
void configEntradas();
void creaEntrada(byte pos, byte pin, boolean tipo, byte accion, byte transmitir);
void creaEntradaAnalog(byte pos, byte pin, byte algoritmo);
void configSalidas();
void creaSalida(byte pos, byte pin, boolean estadoInicial, byte accion);
int freeRam ();

#include "C:\Program Files\Arduino\hardware\arduino\avr\cores\arduino\arduino.h"
#include "C:\Program Files\Arduino\hardware\arduino\avr\variants\standard\pins_arduino.h" 
#include "C:\Users\jom\Documents\Desarrollos\Github\Voze\Voze.ino"
#include "C:\Users\jom\Documents\Desarrollos\Github\Voze\Voze_lecturas.ino"
#include "C:\Users\jom\Documents\Desarrollos\Github\Voze\Voze_salidas.ino"
#include "C:\Users\jom\Documents\Desarrollos\Github\Voze\comunicaciones.ino"
#include "C:\Users\jom\Documents\Desarrollos\Github\Voze\config.ino"
#endif
