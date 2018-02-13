
/*

// Ejercicio led y boton


const int led = 13;
const int boton = 2;

int estado = 0;
int anterior = 0;
int encender = 0;

void setup(){
	pinMode(boton, INPUT);
	pinMode(led, OUTPUT);
}

void loop() {

estado = digitalRead(boton);
	if ((estado == HIGH) && (anterior == LOW)){
		encender = 1 - encender;
		delay(150);
	}
	anterior = estado;
	if(encender == 1){
	    alarma = 1;
	    digitalWrite(led, HIGH);
	    delay(200);
	}
	else{
		alarma = 0;
		digitalWrite(led, LOW);
		delay(200);
	}
}


 */



const int pir = 2;   // Constantes
const int puerta = 3;
const int ventana = 4;
const int activador = 5;
const int buzzer = 6;
const int led1 = 7;
const int led2 = 8;
const int ldr1 = 0;
const int ldr2 = 1;
const int ledAlarma = 13;
int alarma = 0;
int estado = 0;
int anterior = 0;
int encender = 0;
int valorLDR1, valorLDR2, sensorPIR, sensorPuerta, sensorVentana;

void setup()
{
	Serial.begin(9600);
	pinMode(pir, INPUT);
	pinMode(puerta, INPUT);
	pinMode(ventana, INPUT);
	pinMode(activador, INPUT);
	pinMode(buzzer, OUTPUT);
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(ledAlarma, OUTPUT);
}

void loop()
{
	valorLDR1 = analogRead(ldr1);
	valorLDR2 = analogRead(led2);

	Serial.println(valorLDR1);
	Serial.println(valorLDR2);

	if (valorLDR1 > 600){
		digitalWrite(led1, HIGH);
	}
	else {
		digitalWrite(led1, LOW);
	}
	if (valorLDR2 > 600){
		digitalWrite(led2, HIGH);
	}
	else{
		digitalWrite(led2, LOW);
	}


estado = digitalRead(activador);
	if ((estado == HIGH) && (anterior == LOW)){
		encender = 1 - encender;
		delay(150);
	}
	anterior = estado;
	if(encender == 1){
	    alarma = 1;
	    digitalWrite(ledAlarma, HIGH);
	    delay(200);
	}
	else{
		alarma = 0;
		digitalWrite(ledAlarma, LOW);
		delay(200);
	}
	Serial.println(alarma);

	if (alarma == 1){
		sensorPIR = digitalRead(pir);
		sensorPuerta = digitalRead(puerta);
		sensorVentana = digitalRead(ventana);

		if((sensorVentana == 0) || (sensorPuerta == 0) || (sensorPIR == 1)){
		    digitalWrite(buzzer, HIGH);
		    delay(250);
		    digitalWrite(buzzer, LOW);
		    delay(250);
		    digitalWrite(buzzer, HIGH);
		    delay(250);
		    digitalWrite(buzzer, LOW);
		    delay(250);
		    digitalWrite(buzzer, HIGH);
		    delay(250);
		    digitalWrite(buzzer, LOW);
		    delay(250);
		    
		}
		else{

		}
	}



}