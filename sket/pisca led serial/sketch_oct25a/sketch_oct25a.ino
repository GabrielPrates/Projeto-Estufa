int estadoBotao = 0;
int led= 8;
void setup() {
   Serial.begin(9600);
   pinMode(led,OUTPUT);
}

//Método loop, executado enquanto o Arduino estiver ligado.
void loop() {  
  if(estadoBotao == 1){
    //oi
    digitalWrite(led, HIGH);
      
  }else{
    digitalWrite(led, LOW);
  }
     
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    estadoBotao = (int)Serial.read();
 
  }
}
