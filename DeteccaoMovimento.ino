/**
 * Programa de deteccao de movimentos.
 * Nome do programa: DeteccaoMovimento.ino
 * Desenvolvido por: Luiz Gustavo
 */

// declaracao das portas digitais
int pinoSensor  = 4;
int ledVermelho = 6;
int pinoAlarme  = 7;
int somAlarme   = 8;
int valorSensorPIR = 0;

void setup()
{
  // setando o led vermelho
  pinMode(ledVermelho, OUTPUT);

  // sensor de movimento
  pinMode(pinoSensor, INPUT);

  // som do alarme
  pinMode(somAlarme, OUTPUT);
}// end setup()

void loop()
{
  /* le o valor do sensor PIR
     1 se detectar movimento
     0 se nao detectar nada */
  valorSensorPIR = digitalRead(pinoSensor);

  // verifica se houve movimento
  if(valorSensorPIR == 1)
  {
    // chama o metodo para ligar o alarme
    alarmeOn();
  }
  else
  {
    // chama o metodo para desligar o alarme
    alarmeOff();
  }// end if
}// end loop()

/**
 * Metodo alarmeOn() - liga o alarme e o led vermelho.
 */
void alarmeOn()
{
  // liga o led vermelho
  digitalWrite(ledVermelho, HIGH);

  // toca o alarme, com frequencia de 1500 hz
  tone(somAlarme, 1500);

  // tempo que o alarme fica tocando 3 minutos
  delay(180000);

  // desliga o alarme
  alarmeOff();
}// end alarmeOn()

/**
 * Metodo alarmeOff() - desliga o alarme.
 */
void alarmeOff()
{
  // desliga o led
  digitalWrite(ledVermelho, LOW);

  // desliga o alarme
  noTone(somAlarme);
}// end alarmeOff()
