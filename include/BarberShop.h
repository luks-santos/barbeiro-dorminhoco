#ifndef BARBERSHOP_H
#define BARBERSHOP_H

//Constantes para quantidade de threads dos clientes e cadeiras disponíveis
#define NCLIENTS 30
#define NCHAIRS 5

#include <thread>
#include <vector>
//Import das classes dos barbeiros e clientes
#include "Barber.h"
#include "Client.h"

class BarberShop
{
    public:
        BarberShop();
        virtual ~BarberShop();
        void organizeBarberShop();
    private:
        vector<thread> operation;
        Barber barber;
        Client *clients;
};

#endif // BARBERSHOP_H
