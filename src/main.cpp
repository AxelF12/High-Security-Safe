#include <Arduino.h>

// put function declarations here:
//Definierung
typedef enum ()
{SAFE_LOCKED; 
LEVEL_ONE_UNLOCKED;
LEVEL_TWO_UNLOCKED;
LEVEL_THREE_UNLOCKED;
SAFE_OPEN;
SAFE_LOCKED} Zustand_1;

typedef enum {
  INPUT_ONE_ACCEPTED;
  INPUT_TWO_ACCEPTED;
  INPUT_THREE_ACCEPTED;
  OPEN_DOOR;
  CLOSE_DOOR;
  INPUT_REFUSED
} BEDINGUNG_1;


//Globale Variable
ZUSTAND_1 = CLOSE_DOOR;  

//FUNKTION 
void 




void high_security_safe ()