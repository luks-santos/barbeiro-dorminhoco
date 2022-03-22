#include "Client.h"

Client::Client()
{
    barberChair = sem_open("/barberChair", O_CREAT, S_IRWXU, 0);
    waitChairs = sem_open("/waitChairs", O_CREAT, S_IRWXU, 0);
    availability = sem_open("/availability", O_CREAT, S_IRWXU, 1);
    mutex = sem_open("/mutex", O_CREAT, S_IRWXU, 1);
}

void Client::setFreeChairs(int free)
{
    freeChairs = sem_open("/freeChairs", O_CREAT, S_IRWXU, free);
    maxChairs = free;
}

void Client::sit()
{
    sleep(rand() % 20);
    sem_wait(availability);
    if(getValue()) {
        sem_wait(mutex);
        cout << "Chegou um novo cliente." << endl;
        sem_post(mutex);

        sem_wait(freeChairs);

        sem_wait(mutex);
        cout << "Existem " << getValue() << " de " << maxChairs << " cadeiras livres para espera, Cliente aguardando sua vez." << endl;
        sem_post(mutex);

        sem_post(waitChairs);
        sem_post(availability);
        sem_wait(barberChair);
    }
    else {
        sem_post(availability);

        sem_wait(mutex);
        cout<< "Não existem cadeiras de espera disponíveis, Cliente foi embora." << endl;
        sem_post(mutex);
    }
}

int Client::getValue()
{
    int *aux = new int();
    sem_getvalue(freeChairs, aux);
    int value = *aux;
    delete aux; aux = nullptr;
    return value;
}
