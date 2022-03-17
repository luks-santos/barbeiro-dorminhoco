#ifndef BARBERSHOP_H
#define BARBERSHOP_H

#include "Barber.h"
#include "Client.h"

#include <thread>
#include <vector>
#include <iostream>

using namespace std;



class BarberShop
{
    public:
        BarberShop(int &chairs);
        virtual ~BarberShop();

        void openBarberShop();

    private:
        int *freeChairs;
        vector<thread> operation;
        Client *clients;
        Barber barber;
};

#endif // BARBERSHOP_H
