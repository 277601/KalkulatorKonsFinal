#ifndef KALKULATOR_H
#define KALKULATOR_H

#include "operacja.h"
#include "historia.h"
#include <iostream>

class Kalkulator {
private:
    double akumulator;
    double pamiec;
    Historia historiaObliczen; // KOMPOZYCJA: aplikacja zawiera historię wprowadzanych obliczeń

public:
    Kalkulator();
    ~Kalkulator();

    double getAkumulator() const;
    void setAkumulator(double wartosc);
    double getPamiec() const;

    void M_plus();
    void M_minus();
    void M_clear();

    void wykonajOperacje(const Operacja& op, double argument);

    // Metody
    void dodajDoHistorii(const std::string& wpis);
    void pokazHistorie() const;

    Kalkulator& operator+=(double wartosc);
    friend std::ostream& operator<<(std::ostream& os, const Kalkulator& k);
};

#endif // KALKULATOR_H