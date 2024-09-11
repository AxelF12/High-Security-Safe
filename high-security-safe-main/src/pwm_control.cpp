// Header Dateien werden includiert
#include "pwm_control.h"
#include "pin_defs.h"

// Definition der externen HardwareTimer-Pointer
// Zeiger werden auf 0-Stellung gestellt
// Zeigen auf nichts
HardwareTimer *MyTim1 = nullptr;
HardwareTimer *MyTim2 = nullptr;

//Timer Setup-Funktion
void timer_setup () 
{
  // Timer-Instanz und Kanal für den angegebenen Pin PWM_1 automatisch abrufen
  // TIM_TypeDef ist eine Struktur und enthält die Inhalte zum konfigurieren des Timers
  // Der Zeiger Instance1 zeigt auf die Timer-Instanz, die mit dem PWM_1 verbunden ist
  // digitalPinToPinName(PWM_1) nennt den Arduino-Namen in den STM32-PIN-Namen
  // PinMap_PWM ist eine Tabelle, die angibt welche PINs für PWM verbunden werden können und welche Timer mit den PINs verbunden sind
  // Zusammengefasst: Die Funktion pinmap_peripheral(...) gibt einen Wert zurück, der in einen Zeiger umgewandelt wird
  // Dadurch wird sichergestellt, dass die Instance1 korrekt auf dem Timer registriert ist
  TIM_TypeDef *Instance1 = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(PWM_1), PinMap_PWM);
  //pinmap_function: ermittelt welche Funktion auf einem PIN ausgeführt werden kann
  // Gibt einen Wert zurück der die Funktion beschreibt
  //STM_PIN_Channel(...) extrahiert den Kanal (der mit PWM_1 verbunden ist)
  //Warum? Ein Timer kann mehrere Kanäle
  uint32_t channel1 = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(PWM_1), PinMap_PWM));

  // Erstellen Sie eine neue Instanz des HardwareTimers für PWM_1
  MyTim1 = new HardwareTimer(Instance1);

  // PWM-Frequenz auf 50 Hz einstellen (Standard für Servos)
  // Servo wird auf Mittelstellung gestellt
  // Zeiger auf den channel1 (Kanalnummer, AusgangsPIN, Frequenz, Duty Cycle Verhältnis zwischen Einschaltzeit und Gesamtperiode )
  // 7,5% Plusbreite von 1,5ms bei 50 Hz
  MyTim1->setPWM(channel1, PWM_1, 50, 7.5);  // Mittelstellung (7,5% Duty Cycle entspricht ca. 1,5 ms Pulsweite)
  // Startet die Ausgabe
  MyTim1->resume();

  // Timer-Instanz und Kanal für den angegebenen Pin PWM_2 automatisch abrufen
  TIM_TypeDef *Instance2 = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(PWM_2), PinMap_PWM);
  uint32_t channel2 = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(PWM_2), PinMap_PWM));

  // Erstellen Sie eine neue Instanz des HardwareTimers für PWM_2
  MyTim2 = new HardwareTimer(Instance2);

  // PWM-Frequenz auf 50 Hz einstellen (Standard für Servos)
  MyTim2->setPWM(channel2, PWM_2, 50, 7.5);  // Mittelstellung (7,5% Duty Cycle entspricht ca. 1,5 ms Pulsweite)
  MyTim2->resume();
}

void stell_motor ()
{
  motor_geschlossen();
  delay(1000);  // 1 Sekunde warten

  motor_geoeffnet();
  delay(1000);  // 1 Sekunde warten
}

void motor_geschlossen ()
{
  // Servo auf 90° (1,5 ms Pulsweite, 7,5% Duty Cycle) für PWM_1
  MyTim1->setCaptureCompare(STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(PWM_1), PinMap_PWM)), 7.5, PERCENT_COMPARE_FORMAT);

  // Servo auf 90° (1,5 ms Pulsweite, 7,5% Duty Cycle) für PWM_2
  MyTim2->setCaptureCompare(STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(PWM_2), PinMap_PWM)), 7.5, PERCENT_COMPARE_FORMAT);
}

void motor_geoeffnet ()
{
motor_1_geoffnet ();

 motor_2_geoffnet ();
}

void motor_1_geoffnet ()
{
// Servo auf 180° (2 ms Pulsweite, 10% Duty Cycle) für PWM_1
MyTim1->setCaptureCompare(STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(PWM_1), PinMap_PWM)), 10, PERCENT_COMPARE_FORMAT);
}

void motor_2_geoffnet ()
{
 // Servo auf 180° (2 ms Pulsweite, 10% Duty Cycle) für PWM_2
  MyTim2->setCaptureCompare(STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(PWM_2), PinMap_PWM)), 10, PERCENT_COMPARE_FORMAT);   
}


void test_funktion ()
{
  if (HIGH == digitalRead(BTN_1_PIN))
  {
    motor_1_geoffnet ();
    
  }
  else
  {
    MyTim1->setCaptureCompare(STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(PWM_1), PinMap_PWM)), 7.5, PERCENT_COMPARE_FORMAT);
  }
  if (HIGH == digitalRead(BTN_2_PIN))
  {
    motor_2_geoffnet ();
    
  }
  else
  {
    MyTim2->setCaptureCompare(STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(PWM_2), PinMap_PWM)), 7.5, PERCENT_COMPARE_FORMAT);
  }

}

