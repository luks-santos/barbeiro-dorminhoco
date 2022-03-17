#include "Barber.h"


Barber::Barber()
{
    unlink();
    barberChair = sem_open("/barberChair", O_CREAT, S_IRWXU, 0);
    waitChairs = sem_open("/waitChairs", O_CREAT, S_IRWXU, 0);
    availability = sem_open("/availability", O_CREAT, S_IRWXU, 1);


}

Barber::Barber(int &freeChairs)
{
    unlink();
    barberChair = sem_open("/barberChair", O_CREAT, S_IRWXU, 0);
    waitChairs = sem_open("/waitChairs", O_CREAT, S_IRWXU, 0);
    availability = sem_open("/availability", O_CREAT, S_IRWXU, 1);
    this->freeChairs = &freeChairs;
}

void Barber::setFreeChairs(int &freeChairs)
{
    this->freeChairs = &freeChairs;
}

void Barber::cutHair()
{

     while(true){
        if(*freeChairs == 5){
            cout << "Não há clientes para atender, o Barbeiro foi dormir zzz" << endl;
        }
        sem_wait(waitChairs);
        sem_wait(availability);

        cout << "Atendendo Cliente" << endl;

        ++*freeChairs;
        int ran = rand() % 10+1;
        sleep(ran);
        sem_post(barberChair);
        sem_post(availability);
        cout << "Cabelo cortado" << endl;
    }
}

void Barber::unlink()
{
    sem_unlink("/barberChair");
    sem_unlink("/waitChairs");
    sem_unlink("/availability");
}
