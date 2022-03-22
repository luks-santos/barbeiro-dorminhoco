#ifndef BARBERSHOP_H
#define BARBERSHOP_H
#define NCLIENTS 20

#include "Barber.h"
#include "Client.h"

#include <thread>
#include <vector>

#include <iostream>
using namespace std;


class BarberShop
{
    public:
        BarberShop();
        virtual ~BarberShop();
        void closeBarberShop();

    private:
        vector<thread> operation;
        Barber barber;
        Client *clients;
};

#endif // BARBERSHOP_H
