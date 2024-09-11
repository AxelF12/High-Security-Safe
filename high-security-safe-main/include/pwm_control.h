// Hier wird abgeklärt, dass die Headerdatei nur einmal aufgerufen wurde
#ifndef PWM_CONTROL_H
#define PWM_CONTROL_H

// Einbindung der Arduino Bibiliothek
#include <Arduino.h>

// Deklaration der externen HardwareTimer-Pointer
// Extren bedeutet, dass die Variablen in einer anderen Funktion verwendet werden
// Hardwaretimer ist eine Klasse um den Hardware-Timer zu steuern
// Die Zeiger werden verwendet um auf die Hardware-Timer-Instanzen zuzugreifen 
// Zeiger wegen Speicherplatz
extern HardwareTimer *MyTim1;
extern HardwareTimer *MyTim2;

// Funktionsdeklarationen werden vorher aufgerufen
void timer_setup();
void stell_motor();
void motor_geschlossen();
void motor_geoeffnet();
void motor_1_geoffnet ();
void motor_2_geoffnet ();
void test_funktion ();

#endif //Schließt das IF ein, dass Oben begonnen wurden
// PWM_CONTROL_H


