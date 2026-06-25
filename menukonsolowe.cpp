#include "menukonsolowe.h"
#include <iostream>
#include <string>
#include <limits>

MenuKonsolowe::MenuKonsolowe() {}

void MenuKonsolowe::wyswietlMenu() {
    std::cout << "\n=== KALKULATOR KONSOLOWY ===" << std::endl;
    std::cout << kalk << std::endl;
    std::cout << "Operacje: + (dodaj), - (odejmij), * (pomnoz), / (podziel), % (reszta)" << std::endl;
    std::cout << "Pamiec:   P+ (M+), P- (M-), PC (MC), PR (MR - czytaj)" << std::endl;
    std::cout << "Inne:     H (HISTORIA), C (czysc ekran), Q (wyjscie), I (o autorze)" << std::endl;
    std::cout << "Wybor: ";
}

void MenuKonsolowe::uruchom() {
    bool dziala = true;
    std::string operacja;
    double liczba;

    auto wczytajLiczbe = []() -> double {
        double l;
        while (!(std::cin >> l)) {
            if (std::cin.eof()) exit(0);
            std::cout << "Blad! To nie jest liczba. Podaj poprawna liczbe: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return l;
    };

    std::cout << "Podaj pierwsza liczbe: ";
    liczba = wczytajLiczbe();
    kalk.setAkumulator(liczba);

    while (dziala) {
        wyswietlMenu();
        if (!(std::cin >> operacja)) {
            if (std::cin.eof()) break;
        }

        if (operacja == "Q" || operacja == "q") {
            dziala = false;
        } else if (operacja == "I" || operacja == "i") {
            std::cout << "Autor: Karol Koscielski (Wersja Konsolowa OOP)" << std::endl;
        } else if (operacja == "H" || operacja == "h") { // NOWE: Wyświetlanie historii
            kalk.pokazHistorie();
        } else if (operacja == "C" || operacja == "c") {
            kalk.setAkumulator(0);
        } else if (operacja == "P+") {
            kalk.M_plus();
        } else if (operacja == "P-") {
            kalk.M_minus();
        } else if (operacja == "PC") {
            kalk.M_clear();
        } else if (operacja == "PR") {
            kalk.setAkumulator(kalk.getPamiec());
        } else if (operacja == "+" || operacja == "-" || operacja == "*" || operacja == "/" || operacja == "%") {

            std::cout << "Podaj druga liczbe: ";
            liczba = wczytajLiczbe();

            Operacja* op = nullptr;
            if (operacja == "+") op = new Dodawanie();
            else if (operacja == "-") op = new Odejmowanie();
            else if (operacja == "*") op = new Mnozenie();
            else if (operacja == "/") op = new Dzielenie();
            else if (operacja == "%") op = new Reszta();

            if (op != nullptr) {
                // Zapamiętujemy pierwszą liczbę przed jej nadpisaniem!
                double staraLiczba = kalk.getAkumulator();

                kalk.wykonajOperacje(*op, liczba);
                delete op;

                // Zapisujemy całe równanie jako ciąg znaków do historii (np. "5.0 + 3.0 = 8.0")
                std::string wpisDoHistorii = std::to_string(staraLiczba) + " " + operacja + " "
                                             + std::to_string(liczba) + " = " + std::to_string(kalk.getAkumulator());
                kalk.dodajDoHistorii(wpisDoHistorii);

                std::cout << "\n===============================" << std::endl;
                std::cout << "  WYNIK: " << kalk.getAkumulator() << std::endl;
                std::cout << "===============================\n" << std::endl;

                std::string odp;
                while (true) {
                    std::cout << "Czy zapisac do pamieci (T/N)? ";
                    std::cin >> odp;

                    if (odp == "T" || odp == "t") {
                        kalk.M_clear();
                        kalk.M_plus();
                        std::cout << "Zapisano w pamieci. Pamiec: " << kalk.getPamiec() << std::endl;
                        break;
                    }
                    else if (odp == "N" || odp == "n") {
                        break;
                    }
                    else {
                        std::cout << "Niepoprawny wybor! Wpisz T lub N." << std::endl;
                    }
                }

                std::cout << "\n--- NOWE DZIALANIE ---" << std::endl;
                std::cout << "Podaj pierwsza liczbe: ";
                liczba = wczytajLiczbe();
                kalk.setAkumulator(liczba);
            }
        } else {
            std::cout << "Nieznana komenda!" << std::endl;
        }
    }
}