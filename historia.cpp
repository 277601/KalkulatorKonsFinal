#include "historia.h"
#include <iostream>

void Historia::dodajWpis(const std::string& wpis) {
    wpisy.push_back(wpis); // Dodaje nowy element na koniec wektora
}

void Historia::wyswietl() const {
    std::cout << "\n--- HISTORIA OBLICZEN ---" << std::endl;
    if (wpisy.empty()) {
        std::cout << "Brak zapisanych operacji." << std::endl;
    } else {
        // Pętla przechodząca przez wszystkie wpisy
        for (size_t i = 0; i < wpisy.size(); ++i) {
            std::cout << i + 1 << ". " << wpisy[i] << std::endl;
        }
    }
    std::cout << "-------------------------\n" << std::endl;
}

void Historia::wyczysc() {
    wpisy.clear();
}