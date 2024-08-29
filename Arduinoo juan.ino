const int ledVerde = 2;    
const int ledRojo = 3;     
const int ledAmarillo = 4; 


bool modoIntermitente = false;
unsigned long tiempoUltimoCambio = 0;
const unsigned long intervaloIntermitente = 500; 

void setup() {

  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);

 
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char comando = Serial.read();
    
    switch (comando) {
      case '1':
        encenderLed(ledVerde);
        break;
      case '2':
        apagarLed(ledVerde);
        break;
      case '3':
        encenderLed(ledRojo);
        break;
      case '4':
        apagarLed(ledRojo);
        break;
      case '5':
        encenderLed(ledAmarillo);
        break;
      case '6':
        apagarLed(ledAmarillo);
        break;
      case '7':
        encenderTodasLasLuces();
        break;
      case '8':
        apagarTodasLasLuces();
        break;
      case '9':
        modoIntermitente = !modoIntermitente;
        break;
      default:
        Serial.println("Comando no válido");
        break;
    }
  }

  
  if (modoIntermitente) {
    unsigned long tiempoActual = millis();
    if (tiempoActual - tiempoUltimoCambio >= intervaloIntermitente) {
      tiempoUltimoCambio = tiempoActual;
      
      
      digitalWrite(ledVerde, !digitalRead(ledVerde));
      digitalWrite(ledRojo, !digitalRead(ledRojo));
      digitalWrite(ledAmarillo, !digitalRead(ledAmarillo));
    }
  }
}


void encenderLed(int pin) {
  digitalWrite(pin, HIGH);
  Serial.print("LED ");
  Serial.print(pin);
  Serial.println(" encendido");
}


void apagarLed(int pin) {
  digitalWrite(pin, LOW);
  Serial.print("LED ");
  Serial.print(pin);
  Serial.println(" apagado");
}


void encenderTodasLasLuces() {
  encenderLed(ledVerde);
  encenderLed(ledRojo);
  encenderLed(ledAmarillo);
}


void apagarTodasLasLuces() {
  apagarLed(ledVerde);
  apagarLed(ledRojo);
  apagarLed(ledAmarillo);
}
