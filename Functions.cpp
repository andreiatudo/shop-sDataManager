#include "Functions.h"

bool fisierGol(const char* fisier)
{
	std::ifstream file(fisier, std::ios::binary | std::ios::ate); // Muta curosrul la final
	return file.tellg() == 0;  // Verifica pozitia cursorului
}

Produs* citireStoc(std::ifstream& fisier, int& nrProduse)
{
	Produs* produse = new Produs[nrProduse];
	for (int i = 0;i < nrProduse;i++)
	{
		float pret;
		int cantitate;
		char aux[50];
		fisier >> aux >> pret >> cantitate;
		fisier.ignore();
		produse[i] = Produs(aux, pret, cantitate);
	}
	return produse;
}

Client* citireClienti(std::ifstream& fisier, int& nrClienti, int& nrProduseExistente, Produs* produseExistente)
{
	fisier.ignore();
	Client* clienti = new Client[nrClienti];
	for (int i = 0;i < nrClienti;i++)
	{
		int cantitate;
		char nume[60];
		int zi, luna, an, nrProduse = 0;
		fisier.getline(nume, 60);
		//std::cout<<nume<<'\n';
		fisier >> zi >> luna >> an >> nrProduse;
		fisier.ignore();
		//std::cout<<nrProduse;
		Produs* produse = new Produs[nrProduse];
		for (int j = 0;j < nrProduse;j++)
		{
			char numeAux[50];
			fisier >> numeAux >> cantitate;
			fisier.ignore();
			fisier.ignore();
			// std::cout<<numeAux<<'\n';
			float pret;
			for (int k = 0;k < nrProduseExistente;k++)
			{
				if (strcmp(numeAux, produseExistente[k].getDenumire()) == 0)
				{
					pret = produseExistente[k].getPret();
				}
			}
			produse[j] = Produs(numeAux, pret, cantitate);
			//std::cout<<"."<<produse[j];
		}
		Comanda aux(i, zi, luna, an, nrProduse, produse);
		clienti[i] = Client(nume, aux);
		//std::cout << clienti[i];
		delete[] produse;
	}
	return clienti;
}
void afisareSlim(std::ofstream& fout, const Produs* produse, const int& nrProduse)
{
	for (int i = 0;i < nrProduse;i++)
	{
		if (i != nrProduse - 1)
			fout << produse[i].getId() << ". " << produse[i].getDenumire() << ": " << produse[i].getCantitate() << ", Pret: " << produse[i].getPret() << '\n';
		else
			fout << produse[i].getId() << ". " << produse[i].getDenumire() << ": " << produse[i].getCantitate() << ", Pret: " << produse[i].getPret();
	}
}

void afisare(std::ofstream& fout, std::ofstream& gout, const Produs* produse, const Client* clienti, const int& nrProduse, const int& nrClienti)
{
	for (int i = 0;i < nrProduse;i++)
	{
		if (i != nrProduse-1)
			fout << produse[i].getId() << ". " << produse[i].getDenumire() << ": " << produse[i].getCantitate() << ", Pret: " << produse[i].getPret() << '\n';
		else
			fout << produse[i].getId() << ". " << produse[i].getDenumire() << ": " << produse[i].getCantitate() << ", Pret: " << produse[i].getPret();
	}
	for (int i = 0;i < nrClienti;i++)
	{
		gout << "Nume: " << clienti[i].getNume() << '\n';
		gout << "Comanda ID: " << clienti[i].getComanda().getId() << '\n';
		gout << "Data comenzii: " << clienti[i].getComanda().getZi() << '/' << clienti[i].getComanda().getLuna() << '/' << clienti[i].getComanda().getAn() << '\n';
		gout << "Produse comandate:\n";
		float suma = 0;
		//std::cout<<clienti[i];
		Produs* produseTemp = clienti[i].getComanda().getProduse();
		int nrProduseComanda = clienti[i].getComanda().getNrProduse();
		for (int j = 0;j < nrProduseComanda;j++)
		{
			gout << produseTemp[j].getCantitate() << " X " << produseTemp[j].getDenumire() << " (" << produseTemp[j].getPret() << ")\n";
			suma = suma + produseTemp[j].getCantitate() * produseTemp[j].getPret();
		}
		if (i != nrClienti - 1)
			gout << "Total comanda: " << suma << " RON\n\n";
		else
			gout << "Total comanda: " << suma << " RON";
	}
}

void procesareStoc(const Client* clienti, const int& nrClienti, const int& nrProduseStoc, Produs* produse)
{
	for (int i = 0;i < nrClienti;i++)
	{
		int nrProduseComanda = clienti[i].getComanda().getNrProduse();
		Produs* aux = clienti[i].getComanda().getProduse();
		for (int j = 0;j < nrProduseComanda;j++)
		{
			for(int k=0;k<nrProduseStoc;k++)
				if (strcmp(aux[j].getDenumire(), produse[k].getDenumire()) == 0)
				{
					produse[k].setCantitate(produse[k].getCantitate() - aux[j].getCantitate());
				}
		}
	}
}

