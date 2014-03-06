void escribeCanales(){
  for (int i=0;i<=canales;i++){escribeCanal(i);}   
}

void escribeCanal(byte canal){
  digitalWrite(salidas[canal].pin,salidas[canal].estado);
}

void debugSalidas(){
  for (int i=0;i<=canales;i++){
    Serial.print(salidas[i].estado);
    if (i==4){Serial.print(":");}
  }
}
