#ifndef ZMIENNE_H
#define ZMIENNE_H
//deklaracja zmiennych do przekazywania danych
#include <string>

struct dane{        //struktura która przechowuje wszytkie dane
    int Speed;
    float Temperatura;
    uint8_t Swiatla;
    std::string ErrorMsg;
};


#endif // ZMIENNE_H
