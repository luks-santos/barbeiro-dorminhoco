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

#include "Client.h"

Client::Client()
{
    //Inicia os semáforos com nome, se já existir o semáforo abre o existente
    barberChair = sem_open("/barberChair", O_CREAT, S_IRWXU, 0);
    waitChairs = sem_open("/waitChairs", O_CREAT, S_IRWXU, 0);
    availability = sem_open("/availability", O_CREAT, S_IRWXU, 1);
    mutex = sem_open("/mutex", O_CREAT, S_IRWXU, 1);
}

void Client::setFreeWaitChairs(int free)
{
    freeWaitChairs = sem_open("/freeWaitChairs", O_CREAT, S_IRWXU, free);
    maxChairs = free;
}

void Client::sitOnChair()
{
    //Sorteia tempo aleátorio para chegada dos clientes
    sleep(rand() % 14);
    sem_wait(availability);//Seção crítica para quantidade de cadeiras e barbeiro
    //Verifica disponiblidade de cadeiras livres
    if(getFreeWaitChairs()) {
        //Seção crítica para cout
        sem_wait(mutex);
        cout << "Chegou um novo cliente." << endl;
        sem_post(mutex);
        //Decrementa quantidade de cadeiras livres
        sem_wait(freeWaitChairs);
         //Seção crítica para cout
        sem_wait(mutex);
        cout << "Existem " << getFreeWaitChairs() << " de " << maxChairs << " cadeiras livres para espera, Cliente aguardando sua vez." << endl;
        sem_post(mutex);
        //Momento que cliente senta na cadeira de espera e chama o barbeiro
        sem_post(waitChairs);
        //Libera seção critica novo cliente entrar na barbearia ou barbeiro corta o cabelo
        sem_post(availability);
        //Espera barbeiro cortar cabelo
        sem_wait(barberChair);
    }
    else {
        sem_wait(mutex);
        cout<< "Não existem cadeiras de espera disponíveis, Cliente foi embora." << endl;
        sem_post(mutex);
        sem_post(availability);
    }
}

int Client::getFreeWaitChairs()
{
    int *aux = new int();
    sem_getvalue(freeWaitChairs, aux);
    int value = *aux;
    delete aux; aux = nullptr;
    return value;
}
