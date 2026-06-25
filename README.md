# Zaawansowany Kalkulator Konsolowy (OOP)

Projekt końcowy z przedmiotu **Programowanie Obiektowe** realizujący zaawansowany kalkulator matematyczny w środowisku konsolowym przy użyciu nowoczesnych standardów języka C++. 

Aplikacja została zaprojektowana w architekturze modularnej z pełnym wykorzystaniem paradygmatu programowania obiektowego (OOP), odpornością na błędy strumienia wejściowego (input validation) oraz czytelnym podziałem na warstwę logiki biznesowej i prezentacji.

---

## 🚀 Funkcjonalności

- **Podstawowe operacje matematyczne:** Dodawanie (`+`), odejmowanie (`-`), mnożenie (`*`), dzielenie (`/`) oraz obliczanie reszty z dzielenia (`%`).
- **Rejestr pamięci podręcznej (Memory):** Obsługa operacji dodawania do pamięci (`P+`), odejmowania (`P-`), czyszczenia rejestru (`PC`) oraz wywoływania wartości z pamięci na ekran (`PR`).
- **Moduł historii obliczeń:** Automatyczne zapisywanie poprawnie zrealizowanych równań w dynamicznej strukturze danych z możliwością podejrzenia pełnej historii (`H`) w dowolnym momencie.
- **Bezpieczeństwo i walidacja danych:** Pełna odporność na podanie błędnych typów danych (np. liter zamiast cyfr) oraz zabezpieczenie przed krytycznymi błędami matematycznymi (dzielenie przez zero).

---

## 🛠️ Wykorzystane Mechanizmy Obiektowe (OOP)

Projekt w pełni realizuje założenia programowania obiektowego i pokrywa kluczowe zagadnienia z sylabusa przedmiotu:

1. **Hermetyzacja (Enkapsulacja):** Kluczowe stany obiektów (`akumulator`, `pamiec` oraz wektor `wpisy`) są ukryte w sekcjach `private`. Dostęp do nich realizowany jest wyłącznie przez publiczne metody dostępowe (gettery i settery).
2. **Klasy Abstrakcyjne i Dziedziczenie:** Stworzono hierarchię operacji matematycznych. Klasa bazowa `Operacja` definiuje czysto wirtualną metodę `virtual double oblicz(...) const = 0`, którą w sposób polimorficzny implementują klasy pochodne (`Dodawanie`, `Odejmowanie`, `Mnozenie`, `Dzielenie`, `Reszta`).
3. **Polimorfizm (Wielopostaciowość):** Główny silnik kalkulatora przyjmuje jedynie referencję do klasy bazowej `const Operacja& op`. Decyzja o tym, które działanie matematyczne zostanie wykonane, zapada dynamicznie w czasie uruchomienia programu (*runtime*).
4. **Kompozycja:** Klasa `Kalkulator` zawiera w sobie niezależny obiekt klasy `Historia` (relacja typu *has-a*), delegując do niego zadania związane z rejestrem operacji.
5. **Przeciążanie Operatorów i Przyjaźń Klas:** Zaimplementowano przeciążenie operatora strumieniowego `operator<<` jako funkcję zaprzyjaźnioną (`friend`) klasy `Kalkulator`, co pozwala na bezpośrednie i eleganckie wypisywanie stanu urządzenia za pomocą `std::cout << kalk;`. Przeciążono również operator przypisania z dodawaniem `operator+=`.
6. **Dynamiczne Zarządzanie Pamięcią:** Obiekty konkretnych operacji matematycznych alokowane są na stercie za pomocą operatora `new` w momencie wyboru działania i bezpiecznie niszczone przy użyciu `delete` natychmiast po wykonaniu obliczenia, zapobiegając wyciekom pamięci.

---

## 📂 Struktura Plików

Projekt został podzielony na logiczne moduły (pliki nagłówkowe `*.h` oraz implementacji `*.cpp`), co zapewnia przejrzystość kodu i przyspiesza proces kompilacji:

```text
├── CMakeLists.txt        # Plik konfiguracyjny systemu budowania CMake
├── main.cpp              # Główny punkt wejścia (inicjalizacja i uruchomienie menu)
├── operacja.h            # Deklaracja abstrakcyjnej klasy bazowej i klas pochodnych
├── operacja.cpp          # Implementacja logiki poszczególnych działań matematycznych
├── kalkulator.h          # Deklaracja głównej klasy zarządzającej stanem i pamięcią
├── kalkulator.cpp        # Implementacja logiki biznesowej kalkulatora i operatorów
├── historia.h            # Deklaracja modułu rejestru obliczeń (std::vector)
├── historia.cpp          # Implementacja zarządzania i wyświetlania historii
├── menukonsolowe.h       # Deklaracja warstwy interfejsu użytkownika (UI)
└── menukonsolowe.cpp     # Obsługa pętli programu, komend i walidacji strumienia cin
