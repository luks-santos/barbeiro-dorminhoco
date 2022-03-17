#include "BarberShop.h"

BarberShop::BarberShop(int &chairs)
{
    int aux = chairs;
    freeChairs = &chairs;
    barber.setFreeChairs(*freeChairs);
    operation.push_back(thread(&Barber::cutHair, &barber));

    clients = new Client[10];
    for(int i = 0; i < 10; i++){
        clients[i].setFreeChairs(*freeChairs);
        operation.push_back(thread(&Client::sit, clients[i]));
    }
}

BarberShop::~BarberShop()
{
    cout << "deletei" << endl;
    delete freeChairs;
    freeChairs = nullptr;
    delete[] clients;
    clients = nullptr;
}
void BarberShop::openBarberShop()
{

    for(long unsigned int i = 0; i < operation.size(); i++){
        operation[i].join();
    }

}


