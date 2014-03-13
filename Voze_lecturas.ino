#define SWIntIzq 0 // Pos en el vector de ese rele
#define SWIntDer 1 // Pos en el vector de ese rele
#define RIntIzq 0 // Pos en el vector de ese rele
#define RIntDer 1 // Pos en el vector de ese rele
// rutinas digitales
// =================

void leeCanales(){
  for (int i=0;i<=canalesIn;i++){leeCanal(i);}  
}

void leeCanal(int canal){
  boolean v;
  if (entradas[canal].tipo==1){
    v=!digitalRead(entradas[canal].pin);
  }
  else
  {
    if(analogRead(entradas[canal].pin)<=400){v=true;}else{v=false;}
  }
  if (v!=entradas[canal].estado){
    entradas[canal].estado=v;
    if (entradas[canal].transmitir==1){enviaEntrada(entradas[canal].subTipo,v);}
  }
}

void debugEntradas(){
  for (int i=0;i<=canalesIn;i++){
    Serial.print(entradas[i].estado);
    if (i==4){Serial.print(":");}
  }
}

void procesaCanales(){
  byte canalAccion;
  
  for (int i=0;i<=canalesIn;i++){
    // leer a que canal afecta
    canalAccion=cAccion(i);
	
    if (canalAccion<=10){ // con esto se descartan canales superiores, IE para entradas sin salidas directas
      if(entradas[i].tiempo>0){entradas[i].tiempo--; }

      // aciones tipo 00000001, encendido directo o inverso
      if (entradas[i].tiempo==0 && !(entradas[i].accion & B00000110)){
	salidas[canalAccion].estado=entradas[i].estado ^ !(entradas[i].accion & B00000001); 
      }// fin 00000001

      // aciones tipo B00000010, normal o con enclavamiento
      if ((entradas[i].accion & B00000010) && (entradas[i].estado==true)){
	if (entradas[i].tiempo==0){
          salidas[canalAccion].estado=!salidas[canalAccion].estado;
          entradas[i].tiempo=tiempoPulso;
          // caso especial de los flashers
          if (salidas[canalAccion].estado==true){
            if (i==SWIntIzq){salidas[RIntDer].estado==false;}
            if (i==SWIntDer){salidas[RIntIzq].estado==false;} 
	  }
        }
      } // fin 00000010

      // aciones tipo B00000100, pulso o normal
      if (entradas[i].accion & B00000100){
	if ((entradas[i].estado==true) ){
	  if (entradas[i].tiempo==0){
	    salidas[canalAccion].estado=!(entradas[i].accion & B00000001);
	    entradas[i].tiempo=tiempoEnclavamiento;
	  }  
	}
	else{
	  if(entradas[i].tiempo==0){
	    salidas[canalAccion].estado=entradas[i].accion & B00000001;
	  }
	}
      } // fin 00000100
    } // fin canalAccion<=10
  } // fin for pricipal  
} // fin procesaCanales

byte cAccion(byte i){
  byte accion;
  byte canalAccion=0;
  accion=entradas[i].accion;
  if (accion & B10000000){canalAccion+=8;}
  if (accion & B01000000){canalAccion+=4;}
  if (accion & B00100000){canalAccion+=2;}
  if (accion & B00010000){canalAccion+=1;}
  return canalAccion;
}

// rutinas analogicas
// ==================

void leeCanalesAnalog(){
  int valor=0;
  for (int i=0;i<=canalesInAnalog;i++){
    entradasAnalog[i].medicion=analogRead(entradasAnalog[i].pin);
    if (entradasAnalog[i].algoritmo==0){
      valor=convierteVelocidad(entradasAnalog[i].medicion);
    }
    else
    {
      valor=convierteAmpere(entradasAnalog[i].medicion);
    }
    entradasAnalog[i].medicion=valor;
  }  
}

int convierteVelocidad(int medicion){
  // algoritmo para converit la medición analogica a un valor de km/s
  int salida;
  salida=medicion; // corregir
  return salida;
}

int convierteAmpere(int medicion){
  // algoritmo para converit la medición analogica a un valor de Amp.
  int salida;
  salida=medicion; // corregir
  return salida;
}

void debugEntradasAnalog(){
  for (int i=0;i<=canalesInAnalog;i++){
    Serial.print(entradasAnalog[i].medicion);
    Serial.print(":");
    Serial.print(entradasAnalog[i].valor);
    Serial.println(":");
  }
}
void revisaAnalog(){
	if (contadorAnalog<=tiempoAnalog){
		contadorAnalog++;
	}
	else
	{
		contadorAnalog=0;
		enviaEntradasAnalog();
	}
}
