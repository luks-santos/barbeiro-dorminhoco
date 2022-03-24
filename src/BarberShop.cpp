#include "BarberShop.h"

BarberShop::BarberShop()
{
    //Seta o número de cadeiras disponíveis na barbearia
    barber.setFreeChairs(NCHAIRS);
    //Inicia a thread do barbeiro
    operation.push_back(thread(&Barber::cutHair, barber));
    //Inicia o vetor de clientes com número fixo de clientes
    clients = new Client[NCLIENTS];
    //Inicia as threads dos clientes representadas por um número fixo
    for(int i = 0; i < NCLIENTS; i++) {
        clients[i].setFreeChairs(NCHAIRS);
        operation.push_back(thread(&Client::sitOnChair, clients[i]));
    }
}

BarberShop::~BarberShop()
{
    organizeBarberShop();
    delete[] clients;
    clients = nullptr;
}

//Sincroniza as threads
void BarberShop::organizeBarberShop() {
    for(long unsigned int i = 0; i < operation.size(); i++){
        operation[i].join();
    }
}
