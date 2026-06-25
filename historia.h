#ifndef HISTORIA_H
#define HISTORIA_H

#include <vector>
#include <string>

class Historia {
private:
    std::vector<std::string> wpisy; // Hermetyzacja

public:
    void dodajWpis(const std::string& wpis);
    void wyswietl() const;
    void wyczysc();
};

#endif // HISTORIA_H