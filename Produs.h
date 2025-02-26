#ifndef PRODUS_H
#define PRODUS_H

#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

class Produs {
    const int id;           // Cod unic al produsului
    char denumire[50];      // Denumirea produsului (șir de caractere)
    float pret;             // Prețul produsului
    int cantitate;          // Cantitatea pe stoc a produsului
    static int numarProduse;
public:
    // TODO: de implementat
    Produs(const char* denumire=nullptr, const float& pret=0.0f, const int& cantitate=0);
    Produs(const Produs& produs);
    Produs& operator=(const Produs& produs);

    friend std::ostream& operator<<(std::ostream& out, const Produs& produs);

    const int getId() const;
    const char* getDenumire() const;
    float getPret() const;
    int getCantitate() const;
    static int getNumarProduse();

    void setCantitate(const int& cantitate);
};

#endif
