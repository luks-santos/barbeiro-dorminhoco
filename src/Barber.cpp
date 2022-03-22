#include "Barber.h"

Barber::Barber()
{
    unlink();
    barberChair = sem_open("/barberChair", O_CREAT, S_IRWXU, 0);
    waitChairs = sem_open("/waitChairs", O_CREAT, S_IRWXU, 0);
    availability = sem_open("/availability", O_CREAT, S_IRWXU, 1);
    mutex =  sem_open("/mutex", O_CREAT, S_IRWXU, 1);
}

void Barber::setFreeChairs(int free)
{
    freeChairs = sem_open("/freeChairs", O_CREAT, S_IRWXU, free);
    maxChairs = free;
}

void Barber::cutHair()
{
     while(true){
        if(getValue() == maxChairs){
            sem_wait(mutex);
            cout << "Não há clientes para atender, o Barbeiro foi dormir. zzz" << endl;
            sem_post(mutex);
        }
        sem_wait(waitChairs);
        sem_wait(availability);
        sem_post(freeChairs);

        sem_wait(mutex);
        cout << "O Barbeiro está cortando o Cabelo do Cliente " << (maxChairs - getValue()) + 1 << "." << endl;
        sem_post(mutex);

        sleep(rand() % 5);
        sem_post(barberChair);
        sem_post(availability);

        sem_wait(mutex);
        cout << "Cabelo do cliente " << (maxChairs - getValue()) + 1  << " foi cortado." << endl;
        sem_post(mutex);
    }
}

int Barber::getValue()
{
    int *aux = new int();
    sem_getvalue(freeChairs, aux);
    int value = *aux;
    delete aux; aux = nullptr;
    return value;
}

void Barber::unlink()
{
    sem_unlink("/barberChair");
    sem_unlink("/waitChairs");
    sem_unlink("/availability");
    sem_unlink("/mutex");
    sem_unlink("/freeChairs");
}
