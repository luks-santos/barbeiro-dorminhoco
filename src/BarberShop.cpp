/*********************************************************
 * Trabalho da disciplina de Sistemas Operacionais       *
 *               Barbeiro Dorminhoco                     *
 *                                                       *
 * Curso: Bacharelado em Engenharia da Computação        *
 * Professor: Samuel Dias                                *
 *                                                       *
 * Autores:                                              *
 * Lucas Batista dos Santos - 0048505                    *
 * Jorge Luís Vieira Murilo - 0027752                    *
 ********************************************************/

#include "BarberShop.h"

BarberShop::BarberShop()
{
    //Seta o número de cadeiras disponíveis na barbearia
    barber.setFreeWaitChairs(NCHAIRS);
    //Inicia a thread do barbeiro
    operation.push_back(thread(&Barber::cutHair, barber));
    //Inicia o vetor de clientes com número fixo de clientes
    clients = new Client[NCLIENTS];
    //Inicia as threads dos clientes representadas por um número fixo
    for(int i = 0; i < NCLIENTS; i++) {
        clients[i].setFreeWaitChairs(NCHAIRS);
        operation.push_back(thread(&Client::sitOnChair, clients[i]));
    }
}

BarberShop::~BarberShop()
{
    organizeBarberShop(); //Sincroniza as threads
    delete[] clients;
    clients = nullptr;
}

//Sincroniza as threads
void BarberShop::organizeBarberShop() {
    for(long unsigned int i = 0; i < operation.size(); i++){
        operation[i].join();
    }
}
