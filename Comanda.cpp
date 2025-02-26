#include "Comanda.h"


//implementare clasa Comanda

Comanda::Comanda(const int& id, const int& zi, const int& luna, const int& an, const int& nrProduse, const Produs* produse)
{
	this->id = id;
	this->zi = zi;
	this->luna = luna;
	this->an = an;
	this->nrProduse = nrProduse;
	if (nrProduse > 0 && produse != nullptr)
	{
		this->produse = new Produs[nrProduse];
		for (int i = 0; i < nrProduse; i++)
		{
			this->produse[i] = produse[i];
		}
	}
	else {
		this->produse = nullptr;
		this->nrProduse = 0;
	}

}

Comanda::Comanda(const Comanda& comanda)
{
	this->id = comanda.id;
	this->zi = comanda.zi;
	this->luna = comanda.luna;
	this->an = comanda.an;
	this->nrProduse = comanda.nrProduse;
	if (comanda.nrProduse > 0 && comanda.produse != nullptr)
	{
		this->produse = new Produs[comanda.nrProduse];
		for (int i = 0; i < comanda.nrProduse; i++)
		{
			this->produse[i] = comanda.produse[i];
		}
	}
	else
	{
		this->produse = nullptr;
		this->nrProduse = 0;
	}
}

Comanda& Comanda::operator=(const Comanda& comanda)
{

	if (this != &comanda)
	{
		if (this->produse != nullptr)
		{
			delete[] this->produse;
			this->produse = nullptr;
		}

		this->id = comanda.id;
		this->zi = comanda.zi;
		this->luna = comanda.luna;
		this->an = comanda.an;
		this->nrProduse = comanda.nrProduse;

		if (comanda.nrProduse > 0 && comanda.produse != nullptr)
		{
			this->produse = new Produs[comanda.nrProduse];
			for (int i = 0; i < comanda.nrProduse; i++)
			{
				this->produse[i] = comanda.produse[i];
			}
		}
	}
	return *this;
}

Comanda::~Comanda()
{
	if (this->produse != nullptr)
	{
		delete[] this->produse;
		this->produse = nullptr;
	}
}

int Comanda::getId() const
{
	return this->id;
}

int Comanda::getZi() const
{
	return this->zi;
}

int Comanda::getLuna() const
{
	return this->luna;
}

int Comanda::getAn() const
{
	return this->an;
}

int Comanda::getNrProduse() const
{
	return this->nrProduse;
}

Produs* Comanda::getProduse() const
{
	return this->produse;
}

std::ostream& operator<<(std::ostream& out, const Comanda& comanda)
{
	out << "Id-ul comenzii este: " << comanda.id << '\n';
	out << "Ziua comenzii este: " << comanda.zi << '\n';
	out << "Luna comenzii este: " << comanda.luna << '\n';
	out << "Anul comenzii este: " << comanda.an << '\n';
	out << "Numarul de produse ale comenzii este: " << comanda.nrProduse << '\n';
	if (comanda.nrProduse > 0 && comanda.produse != nullptr)
	{
		for (int i = 0;i < comanda.nrProduse;i++)
		{
			out << comanda.produse[i];
		}
	}
	return out;
}
