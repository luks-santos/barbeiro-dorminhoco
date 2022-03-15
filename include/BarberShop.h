#ifndef BARBERSHOP_H
#define BARBERSHOP_H

#include "Barber.h"
#include "Client.h"

#include <thread>

#include <iostream>
using namespace std;



class BarberShop
{
    public:
        BarberShop();
        virtual ~BarberShop() {}

        void openBarberShop();

    private:
};

#endif // BARBERSHOP_H
