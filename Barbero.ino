
#define barbero 2 // Pin del LED del asiento del barbero
#define cliente 3 // Pin del LED del asiento del cliente con el barbero
#define silla1 4  // Pin del LED del asiento del espera 1
#define silla2 5  // Pin del LED del asiento del espera 2
#define silla3 6  // Pin del LED del asiento del espera 3
#define silla4 7  // Pin del LED del asiento del espera 4
#define entrada 8 // Pin del LED de la entrada

int custReady = 0;      // Cantidad de clientes listos para ser atendidos
int access = 1;         // Variable de acceso a recursos compartidos
int noOfSeats = 4;      // Cantidad de asientos disponibles en la sala de esperA
int come = 1;           // Variable para indicar si un cliente quiere ingresar

void setup() {
   Serial.begin(9600);  
   pinMode(barbero,OUTPUT);
   pinMode(silla1, OUTPUT);
   pinMode(silla2, OUTPUT);
   pinMode(silla3, OUTPUT);
   pinMode(silla4, OUTPUT);
   pinMode(entrada, OUTPUT);
   pinMode(cliente, OUTPUT);

  // Inicialmente, todos los LEDs están apagados
  
  digitalWrite(barbero , LOW); 
  digitalWrite(silla1 , LOW); 
  digitalWrite(silla2 , LOW); 
  digitalWrite(silla3 , LOW);  
  digitalWrite(silla4, LOW);
  digitalWrite(entrada, LOW);
  digitalWrite(cliente, LOW);

}

void loop() {

if (come == 1) {

    if (noOfSeats > 0  ) {
      Serial.print(noOfSeats);
      enterWaitingRoom();
      delay(1000);
      signal1();
      updateWaitingRoomLED();
      delay(1000);
      startCutting();
      delay(3000);
      finishCutting();
      signal2();
      SeatsFree();
      delay(200);
    } if(noOfSeats==0) {
      noSpace();
      Serial.print("entro");
      noOfSeats=5;
      Serial.print(noOfSeats);
    }
  }

}

void enterWaitingRoom() {
  digitalWrite(entrada, HIGH);
  delay(500);
  digitalWrite(entrada, LOW);
  noOfSeats--;


}

void signal1() {
  custReady++;
  custReady = custReady % 5;
}

void updateWaitingRoomLED() {
   if(custReady==1){
    digitalWrite(silla1, HIGH);
    digitalWrite(silla2, LOW);
    digitalWrite(silla3, LOW);
    digitalWrite(silla4, LOW);
  }if(custReady==2){
    
    digitalWrite(silla1, HIGH);
    digitalWrite(silla2, HIGH);
    digitalWrite(silla3, LOW);
    digitalWrite(silla4, LOW);
  }
  if(custReady==3){
    
    digitalWrite(silla1, HIGH);
    digitalWrite(silla2, HIGH);
    digitalWrite(silla3, HIGH);
    digitalWrite(silla4, LOW);
  }
  if(custReady==4){
    
    digitalWrite(silla1, HIGH);
    digitalWrite(silla2, HIGH);
    digitalWrite(silla3, HIGH);
    digitalWrite(silla4, HIGH);
  }
}

void startCutting() {
  digitalWrite(barbero, HIGH);
  delay(200);
  digitalWrite(cliente, HIGH);
}

void finishCutting() {
  digitalWrite(cliente, LOW);
    delay(200);
  digitalWrite(barbero, LOW);
}

void signal2() {
  access++;
  access = access % 2;
}

void SeatsFree(){

   if(custReady==1){
    digitalWrite(silla1, LOW);
    digitalWrite(silla2, LOW);
    digitalWrite(silla3, LOW);
    digitalWrite(silla4, LOW);
  }if(custReady==2){
    
    digitalWrite(silla1, HIGH);
    digitalWrite(silla2, LOW);
    digitalWrite(silla3, LOW);
    digitalWrite(silla4, LOW);
  }
  if(custReady==3){
    
    digitalWrite(silla1, HIGH);
    digitalWrite(silla2, HIGH);
    digitalWrite(silla3, LOW);
    digitalWrite(silla4, LOW);
  }
  if(custReady==4){
    
    digitalWrite(silla1, HIGH);
    digitalWrite(silla2, HIGH);
    digitalWrite(silla3, HIGH);
    digitalWrite(silla4, HIGH);
  }
   
  }

void noSpace() {

  digitalWrite(silla1, LOW);
  digitalWrite(silla2, LOW);
  digitalWrite(silla3, LOW);
  digitalWrite(silla4, LOW);
  digitalWrite(entrada, HIGH);
  delay(100);
  digitalWrite(entrada, LOW);
  delay(100);
  digitalWrite(entrada, HIGH);
  delay(100);
  digitalWrite(entrada, LOW);
  delay(100);
  digitalWrite(entrada, HIGH);
  delay(100);
  digitalWrite(entrada, LOW);
  delay(100);

}
