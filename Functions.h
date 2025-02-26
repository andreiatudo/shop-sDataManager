#pragma once
#include "Client.h"
bool fisierGol(const char* fisier);

Produs* citireStoc(std::ifstream& fisier, int& nrProduse);
Client* citireClienti(std::ifstream& fisier, int& nrClienti, int &nrProduseExistente, Produs* produseExistente);

void afisare(std::ofstream& fout, std::ofstream& gout, const Produs* produse, const Client* clienti, const int& nrProduse, const int& nrClienti);
void afisareSlim(std::ofstream& fout, const Produs* produse, const int& nrProduse);
void procesareStoc(const Client* clienti, const int& nrClienti, const int& nrProduseStoc, Produs* produse);