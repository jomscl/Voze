#define RIntIzq 0 // Pos en el vector de ese rele
#define RIntDer 1 // Pos en el vector de ese rele
#define RLuzInt 2 // Pos en el vector de ese rele
#define RLuzAlta 3 // Pos en el vector de ese rele
#define RReversa 4 // Pos en el vector de ese rele
#define RNA 5 // Pos en el vector de ese rele
#define RBoost 6 // Pos en el vector de ese rele
#define RLuzBaj 7 // Pos en el vector de ese rele
#define RIgnic 8 // Pos en el vector de ese rele
#define RLuzEst 9 // Pos en el vector de ese rele

void enviaEntrada(byte subTipo, byte valor){
  mb.setFlags(0);
  mb.setAddressFrom(ADDRESS);
  mb.setAddressTo(ADDRESSTO);
  mb.setMessageType('1');
  mb.setMessageSubType(subTipo);
  if (valor==0){
    mb.setData("0");
  }
  else{
    mb.setData("1");
  }
  engine.sendMessage(mb.getMessage());
}

void enviaEntradasAnalog(){
  String mensaje;
  mensaje=String(entradasAnalog[0].valor);
  mensaje+=",";
  mensaje+=String(entradasAnalog[1].valor);
  mb.setFlags(0);
  mb.setAddressFrom(ADDRESS);
  mb.setAddressTo(ADDRESSTO);
  mb.setMessageType('1');
  mb.setMessageSubType('0');
  mb.setData(mensaje);  
  engine.sendMessage(mb.getMessage());
  
}

void processMessageCom(char flags, String address_from, char type,char sub_type,String data){
  
  boolean mensajeEstado=false;
  // analizo la data del mensaje
  if (data=="0"){mensajeEstado=false;}
  if (data=="1"){mensajeEstado=true;}
  
  // veo que tipo de mensaje es
  if (type=='1'){
    // Rele Luz estacionamiento      M 140:1
    if (sub_type=='4'){salidas[RLuzEst].estado=mensajeEstado;}
    
    //Rele Luz alta +               M 150:1
    if (sub_type=='5'){salidas[RLuzAlta].estado=mensajeEstado;}
    
    //Rele Luz baja                 M 130:1
    if (sub_type=='3'){salidas[RLuzBaj].estado=mensajeEstado;}
    
    //Rele Reversa                  M 1c0:1
    if (sub_type=='c'){salidas[RReversa].estado=mensajeEstado;}
    
    //Rele Boost                    M 1d0:1
    if (sub_type=='d'){salidas[RBoost].estado=mensajeEstado;}
    
    //Rele Ignicion                 M 1b0:1
    if (sub_type=='b'){salidas[RIgnic].estado=mensajeEstado;}
    
    //Rele Luz interior             M 160:1
    if (sub_type=='6'){salidas[RLuzInt].estado=mensajeEstado;}
    
     //Rele Luz interior             M 190:1 // segunda variante
    if (sub_type=='9'){salidas[RLuzInt].estado=mensajeEstado;}
    
    //Combinados (Hazzard)                                     M 120:1
    if (sub_type=='2'){
      salidas[RIntIzq].estado=mensajeEstado;
      salidas[RIntDer].estado=mensajeEstado;
    }
    
  } // fin IF type==1
  
    //Serial.println("Received message: ");
    //Serial.print("Flags: ");
    //Serial.println((int)flags);
    //Serial.print("From: ");
    //Serial.println(address_from);
    //Serial.print("Type: ");
    //Serial.println(type);
    //Serial.print("Sub-Type: ");
    //Serial.println(sub_type);
    //Serial.print("Data: ");
    //Serial.println(data);
}
