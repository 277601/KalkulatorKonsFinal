#include "kalkulator.h"

// Inicjalizacja pól klasy poprzez listę inicjalizacyjną
Kalkulator::Kalkulator() : akumulator(0.0), pamiec(0.0) {}

Kalkulator::~Kalkulator() {
    // Destruktor - tu mógłbyś zwalniać pamięć dynamiczną (new/delete), jeśli byś z niej korzystał
}

double Kalkulator::getAkumulator() const { return akumulator; }
void Kalkulator::setAkumulator(double wartosc) { akumulator = wartosc; }
double Kalkulator::getPamiec() const { return pamiec; }

void Kalkulator::M_plus() {
    pamiec += akumulator;
}

void Kalkulator::M_minus() {
    pamiec -= akumulator;
}

void Kalkulator::M_clear() {
    pamiec = 0.0;
}

void Kalkulator::wykonajOperacje(const Operacja& op, double argument) {
    // Wywołanie polimorficznej funkcji oblicz
    akumulator = op.oblicz(akumulator, argument);
}

Kalkulator& Kalkulator::operator+=(double wartosc) {
    this->akumulator += wartosc;
    return *this; // Użycie wskaźnika this
}

// Definicja zaprzyjaźnionego operatora (friend)
std::ostream& operator<<(std::ostream& os, const Kalkulator& k) {
    os << "[Ekran: " << k.akumulator << " | Pamiec: " << k.pamiec << "]";
    return os;
}
void Kalkulator::dodajDoHistorii(const std::string& wpis) {
    historiaObliczen.dodajWpis(wpis);
}
void Kalkulator::pokazHistorie() const {
    historiaObliczen.wyswietl();
}