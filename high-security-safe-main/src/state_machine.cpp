#include "state_machine.h"
#include "pwm_control.h"

// globale Variablen
State_t state = SAFE_LOCKED;

void state_machine(Event_t event)
{
  switch (state)
  {
  case SAFE_LOCKED:
    if (INPUT_1_ACCEPTED == event)
    {
      state = LEVEL_1_UNLOCKED;
      motor_geschlossen (); //neu
    }
    break;
  case LEVEL_1_UNLOCKED:
    if (INPUT_2_ACCEPTED == event)
    {
      state = LEVEL_2_UNLOCKED;
      motor_1_geoffnet (); //neu
    }
    else if (INPUT_REFUSED == event)
    {
      state = SAFE_LOCKED;
      motor_geschlossen (); //neu
    }
    break;
  case LEVEL_2_UNLOCKED:
    if (INPUT_3_ACCEPTED == event)
    {
      state = LEVEL_3_UNLOCKED;
      motor_2_geoffnet (); //neu
    }
    else if (INPUT_REFUSED == event)
    {
      state = SAFE_LOCKED;
      motor_geschlossen (); //neu
    }
    break;
  case LEVEL_3_UNLOCKED:
    if (OPEN_DOOR == event)
    { motor_1_geoffnet (); //neu
      motor_2_geoffnet (); //neu
      state = SAFE_OPEN;
    }
    break;
  case SAFE_OPEN:
    if (CLOSE_DOOR == event)
    {
      state = SAFE_LOCKED;
      motor_geschlossen (); //neu
    }
    break;
  }
}