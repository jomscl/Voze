void enviaEntrada(byte canal, boolean v){
  mb.setFlags(0);
  mb.setAddressFrom(ADDRESS);
  mb.setAddressTo("0002");
  mb.setMessageType(canal+48);
  mb.setMessageSubType(v);
  mb.setData("data");
  
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
