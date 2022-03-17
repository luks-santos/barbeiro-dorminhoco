#include "Client.h"
#include <unistd.h>

Client::Client()
{
    barberChair = sem_open("/barberChair", O_CREAT, S_IRWXU, 0);
    waitChairs = sem_open("/waitChairs", O_CREAT, S_IRWXU, 0);
    availability = sem_open("/availability", O_CREAT, S_IRWXU, 1);
}

Client::Client(int &freeChairs)
{
    barberChair = sem_open("/barberChair", O_CREAT, S_IRWXU, 0);
    waitChairs = sem_open("/waitChairs", O_CREAT, S_IRWXU, 0);
    availability = sem_open("/availability", O_CREAT, S_IRWXU, 1);
    this->freeChairs = &freeChairs;
}

void Client::setFreeChairs(int &freeChairs)
{
    this->freeChairs = &freeChairs;
}

void Client::sit()
{
    int ran = rand() % 30+1;
    sleep(ran);
    sem_wait(availability);

    if(*freeChairs > 0) {

        cout << "Chegou um cliente!!" << endl;

        --*freeChairs;
        cout << *freeChairs << endl;
        sem_post(waitChairs);

        sem_post(availability);

        sem_wait(barberChair);

    } else {
        sem_post(availability);
       cout<<" O Cliente foi embora"<<endl;
    }
}
