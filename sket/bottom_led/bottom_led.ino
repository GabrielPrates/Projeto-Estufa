int estadoBotao = 0;
 

void setup() {
  pinMode(4, OUTPUT); 
  pinMode(9, INPUT);
  Serial.begin(9600);
  
}
int num = 0;

void loop() {
  //digitalWrite(4, LOW); 
  digitalWrite(4, HIGH);
  

   if (digitalRead(9) == HIGH){
      while(digitalRead(9) == HIGH){
        num = 1;
      }
    }else{
      num = 0;
    }    
  Serial.write(num);  
}
