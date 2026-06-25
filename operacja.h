#ifndef OPERACJA_H
#define OPERACJA_H

#include <iostream>

// Klasa abstrakcyjna (interfejs) dla operacji matematycznych
class Operacja {
public:
    virtual ~Operacja() {} // Wirtualny destruktor

    // Czysto wirtualna funkcja realizująca polimorfizm
    virtual double oblicz(double a, double b) const = 0;
};

// Dziedziczenie publiczne klas pochodnych
class Dodawanie : public Operacja {
public:
    double oblicz(double a, double b) const override {
        return a + b;
    }
};

class Odejmowanie : public Operacja {
public:
    double oblicz(double a, double b) const override {
        return a - b;
    }
};

class Mnozenie : public Operacja {
public:
    double oblicz(double a, double b) const override {
        return a * b;
    }
};

class Dzielenie : public Operacja {
public:
    double oblicz(double a, double b) const override {
        if (b == 0) {
            std::cerr << "Blad: Nie mozna dzielic przez 0!" << std::endl;
            return 0;
        }
        return a / b;
    }
};

class Reszta : public Operacja {
public:
    double oblicz(double a, double b) const override {
        if (b == 0) return 0;
        return (int)a % (int)b;
    }
};

#endif // OPERACJA_H