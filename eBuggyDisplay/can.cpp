#include "can.h"
#include "./zmienne.h"

extern dane dane1;

int temptestv[12] = {50,51,49,45,44,45,47,51,50,52,50,49};
int i;

void CANodczyt(){   //funkcja do odczytu ramek can
    dane1.ErrorMsg = "Err2";    //aktualnie ustawia jakies losowe wartosci

    dane1.Speed = temptestv[i];
    i = i>10 ? 0 : i+1;

    dane1.Swiatla = 0b00100111;
    dane1.Temperatura = 72.23;
}
