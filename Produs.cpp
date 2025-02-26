#include "Produs.h"
int Produs::numarProduse = 0;
//implementare clasa Produs

Produs::Produs(const char* denumire, const float& pret, const int& cantitate) : id(numarProduse++)
{
	this->denumire[0] = '\0';

	if (denumire != nullptr) {
		strncpy(this->denumire, denumire, sizeof(this->denumire) - 1);
		this->denumire[sizeof(this->denumire) - 1] = '\0'; 
	}
	this->pret = pret;
	this->cantitate = cantitate;
}

Produs::Produs(const Produs& produs) : id(numarProduse++)
{
	strncpy(this->denumire, produs.denumire, sizeof(this->denumire) - 1);
	this->denumire[sizeof(this->denumire) - 1] = '\0';
	this->pret = produs.pret;
	this->cantitate = produs.cantitate;
}

Produs& Produs::operator=(const Produs& produs)
{
	if (this != &produs)
	{
		strncpy(this->denumire, produs.denumire, sizeof(this->denumire) - 1);
		this->denumire[sizeof(this->denumire) - 1] = '\0';
		this->pret = produs.pret;
		this->cantitate = produs.cantitate;
	}
	return *this;
}

const int Produs::getId() const
{
	return this->id;
}

const char* Produs::getDenumire() const
{
	return this->denumire;
}

float Produs::getPret() const
{
	return this->pret;
}

int Produs::getCantitate() const
{
	return this->cantitate;
}

int Produs::getNumarProduse()
{
	return numarProduse;
}

void Produs::setCantitate(const int& cantitate)
{
	this->cantitate = cantitate;
}

std::ostream& operator<<(std::ostream& out, const Produs& produs)
{
	out << "Id-ul produsului este: " << produs.id<<'\n';
	out << "Pretul produsului este: " << produs.pret << '\n';
	out << "Cantitatea produsului este: " << produs.cantitate << '\n';
	out << "Denumirea produsului este: ";
	(produs.denumire[0] != '\0') ? out << produs.denumire<<'\n' : out << "N/A\n";
	// TODO: insert return statement here
	return out;
}
