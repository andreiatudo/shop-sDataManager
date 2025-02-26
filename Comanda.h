#ifndef COMANDA_H
#define COMANDA_H
#include "Produs.h"

class Comanda {
protected:
    int id;
    int zi, luna, an;             // Data comenzii
    int nrProduse;                // Numarul total de produse din comanda
    Produs* produse;              // Vector alocat dinamic pentru produsele din comanda

public:
    // TODO: de implementat
    Comanda(const int& id=0, const int& zi=1, const int& luna=1, const int& an=2024, const int& nrProduse=0, const Produs* produse=nullptr);
    Comanda(const Comanda& comanda);
    Comanda& operator=(const Comanda& comanda);
    ~Comanda();

    friend std::ostream& operator<<(std::ostream& out, const Comanda& comanda);

    int getId() const;
    int getZi() const;
    int getLuna() const;
    int getAn() const;
    int getNrProduse() const;
    Produs* getProduse() const;
};

#endif
