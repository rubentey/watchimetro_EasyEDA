const int pinBoton1 = 16; // Pin D0
const int pinBoton2 = 14; // Pin D5
const int pinBoton3 = 12; // Pin D6
const int pinBoton4 = 13; // Pin D7
const int pinAnalogico = A0; // Pin A0

void setup() {
  Serial.begin(9600); // Iniciamos la comunicación serial
  pinMode(pinBoton1, INPUT); // Configuramos los pines de los botones como entradas con resistencias pull-up
  pinMode(pinBoton2, INPUT);
  pinMode(pinBoton3, INPUT);
  pinMode(pinBoton4, INPUT);
}

void loop() {
  if (digitalRead(pinBoton1) == HIGH) { // Si el botón 1 se ha pulsado
    Serial.println("Boton 1 pulsado"); // Mostramos un mensaje en la consola serial indicando que el botón 1 se ha pulsado
  } else if (digitalRead(pinBoton2) == HIGH) { // Si el botón 2 se ha pulsado
    Serial.println("Boton 2 pulsado"); // Mostramos un mensaje en la consola serial indicando que el botón 2 se ha pulsado
  } else if (digitalRead(pinBoton3) == HIGH) { // Si el botón 3 se ha pulsado
    Serial.println("Boton 3 pulsado"); // Mostramos un mensaje en la consola serial indicando que el botón 3 se ha pulsado
  } else if (digitalRead(pinBoton4) == HIGH) { // Si el botón 4 se ha pulsado
    Serial.println("Boton 4 pulsado"); // Mostramos un mensaje en la consola serial indicando que el botón 4 se ha pulsado
  }

  int valorAnalogico = analogRead(pinAnalogico); // Leemos el valor del pin A0
  Serial.print("Valor del pin A0: "); // Mostramos un mensaje en la consola serial indicando que se va a mostrar el valor del pin A0
  Serial.println(valorAnalogico); // Mostramos el valor del pin A0

  delay(100); // Esperamos un instante antes de leer el estado de los botones y el valor del pin A0 de nuevo
}
