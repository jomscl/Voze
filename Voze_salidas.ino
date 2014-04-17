void escribeCanales(){
  for (int i=0;i<=canalesOut;i++){escribeCanal(i);}   
}

void escribeCanal(byte canal){
  if (salidas[canal].accion & B00000001){ // intermitente
    if (salidas[canal].estado==true){
      digitalWrite(salidas[canal].pin,estadoIntermitente);
    }
  }
  else
  {
    digitalWrite(salidas[canal].pin,salidas[canal].estado);
  } // fin if continuo o intermitente
}

void debugSalidas(){
  for (int i=0;i<=canalesOut;i++){
    Serial.print(salidas[i].estado);
    if (i==4){Serial.print(":");}
  }
}
