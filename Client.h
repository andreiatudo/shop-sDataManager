#ifndef CLIENT_H
#define CLIENT_H
#include "Comanda.h"

class Client {
private:
    char nume[60];  // Numele clientului
    Comanda comanda; //comanda clientului

public:
    // TODO: de implementat
    Client(const char* nume=nullptr, const Comanda& comanda = Comanda());
    Client(const Client& client);
    Client& operator=(const Client& client);

    friend std::ostream& operator<<(std::ostream& out, const Client& client);

    const char* getNume() const;
    const Comanda& getComanda() const;
};

#endif
