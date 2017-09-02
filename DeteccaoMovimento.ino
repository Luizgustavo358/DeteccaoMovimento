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

  if(valorSensorPIR == 1)
  {
    alarmeOn();
  }
  else
  {
    alarmeOff();
  }// end if
}// end loop()

void alarmeOn()
{

}// end alarmeOn()

void alarmeOff()
{

}// end alarmeOff()
