void enviaEntrada(byte canal, boolean v){
  mb.setFlags(0);
  mb.setAddressFrom(ADDRESS);
  mb.setAddressTo(ADDRESS);
  mb.setMessageType(canal+48);
  mb.setMessageSubType(v);
  mb.setData("data");  
  engine.sendMessage(mb.getMessage());
}

void enviaEntradasAnalog(){
  String mensaje;
  mensaje=String(entradasAnalog[0].valor);
  mensaje+=",";
  mensaje+=String(entradasAnalog[1].valor);
  mb.setFlags(0);
  mb.setAddressFrom(ADDRESS);
  mb.setAddressTo(ADDRESS);
  mb.setMessageType(1);
  mb.setMessageSubType(0);
  mb.setData(mensaje);  
  engine.sendMessage(mb.getMessage());
}

void recibeOrdenes(){

}

void processMessage(char flags, String address_from, char type,char sub_type,String data){
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
