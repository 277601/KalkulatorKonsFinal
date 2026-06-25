#ifndef OPERACJA_H
#define OPERACJA_H

// Klasa abstrakcyjna (interfejs) dla operacji matematycznych
class Operacja {
public:
    virtual ~Operacja() {}

    // Czysto wirtualna funkcja realizująca polimorfizm
    virtual double oblicz(double a, double b) const = 0;
};

// Deklaracje klas pochodnych [cite: 50]
class Dodawanie : public Operacja {
public:
    double oblicz(double a, double b) const override;
};

class Odejmowanie : public Operacja {
public:
    double oblicz(double a, double b) const override;
};

class Mnozenie : public Operacja {
public:
    double oblicz(double a, double b) const override;
};

class Dzielenie : public Operacja {
public:
    double oblicz(double a, double b) const override;
};

class Reszta : public Operacja {
public:
    double oblicz(double a, double b) const override;
};

#endif // OPERACJA_H