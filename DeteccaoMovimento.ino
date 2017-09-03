/**
 * Programa de deteccao de movimentos.
 * Nome do programa: DeteccaoMovimento.ino
 * Desenvolvido por: Luiz Gustavo
 */

// incluindo biblioteca virtuabotixRTC
#include <virtuabotixRTC.h>

// declaracao das portas digitais
int pinoSensor  = 4;
int ledVermelho = 6;
int pinoAlarme  = 7;
int somAlarme   = 8;
int dataRTC     = 4;
int resetRTC    = 9;
int clkRTC      = 5;
int valorSensorPIR = 0;

// determina os pinos ligados ao modulo
virtuabotixRTC myRTC(clkRTC, dataRTC, resetRTC);

void setup()
{
  // setando o led vermelho
  pinMode(ledVermelho, OUTPUT);

  // sensor de movimento
  pinMode(pinoSensor, INPUT);

  // som do alarme
  pinMode(somAlarme, OUTPUT);

  // Informacoes iniciais de data e hora
  // Apos setar as informacoes, comente a linha abaixo
  // (segundos, minutos, hora, dia da semana, dia do mes, mes, ano)
  myRTC.setDS1302Time(00, 00, 08, 1, 03, 09, 2017); // 08:00 03/09/17 DOMINGO
}// end setup()

void loop()
{
  /* le o valor do sensor PIR
     1 se detectar movimento
     0 se nao detectar nada */
  valorSensorPIR = digitalRead(pinoSensor);

  // le as informacoes do CI
  myRTC.updateTime();

  // verifica se houve movimento
  if((valorSensorPIR == 1) && (myRTC.hours >= 22) && (myRTC.hours < 8))
  {
    // chama o metodo para ligar o alarme
    alarmeOn();
  }
  else
  {
    // chama o metodo para desligar o alarme
    alarmeOff();
  }// end if

  // faz um delay de 1 seg
  delay(1000);
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
