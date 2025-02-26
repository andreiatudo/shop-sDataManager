#include "Client.h"

//implementare clasa Client

Client::Client(const char* nume, const Comanda& comanda)
{
	this->nume[0] = '\0';

	if (nume != nullptr) {
		strncpy(this->nume, nume, sizeof(this->nume) - 1);
		this->nume[sizeof(this->nume) - 1] = '\0';
	}
	this->comanda = comanda;
}

Client::Client(const Client& client)
{
	strncpy(this->nume, client.nume, sizeof(this->nume) - 1);
	this->nume[sizeof(this->nume) - 1] = '\0';
	this->comanda = client.comanda;
}

Client& Client::operator=(const Client& client)
{
	if (this != &client)
	{
		strncpy(this->nume, client.nume, sizeof(this->nume) - 1);
		this->nume[sizeof(this->nume) - 1] = '\0';
		this->comanda = client.comanda;
	}
	return *this;

}

const char* Client::getNume() const
{
	return this->nume;
}

const Comanda& Client::getComanda() const
{
	return this->comanda;
}

std::ostream& operator<<(std::ostream& out, const Client& client)
{
	out << "Numele clientului este: ";
	(client.nume[0] != '\0') ? out << client.nume<<'\n' : out << "N/A\n";
	out << client.comanda;
	return out;
}
