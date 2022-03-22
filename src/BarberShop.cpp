#include "BarberShop.h"

BarberShop::BarberShop()
{
    int n;
    cout << "Informe a quantidade n de cadeiras livres: ";
    cin >> n;
    barber.setFreeChairs(n);

    operation.push_back(thread(&Barber::cutHair, barber));

    clients = new Client[NCLIENTS];
    for(int i = 0; i < NCLIENTS; i++) {
        clients[i].setFreeChairs(n);
        operation.push_back(thread(&Client::sit, clients[i]));
    }
}

BarberShop::~BarberShop()
{
    cout << "TO AQ" << endl;
    delete[] clients;
    clients = nullptr;
}

void BarberShop::closeBarberShop() {
    for(long unsigned int i = 0; i < operation.size(); i++){
        operation[i].join();
    }
}
