#ifndef MENUKONSOLOWE_H
#define MENUKONSOLOWE_H

#include "kalkulator.h"

class MenuKonsolowe {
private:
    Kalkulator kalk; // Obiekt kalkulatora zagnieżdżony w menu
    void wyswietlMenu();

public:
    MenuKonsolowe();
    void uruchom(); // Główna pętla programu
};

#endif // MENUKONSOLOWE_H