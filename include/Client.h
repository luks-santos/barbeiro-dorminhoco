#ifndef CLIENT_H
#define CLIENT_H

#include <semaphore.h>
#include <fcntl.h>
#include <iostream>
using namespace std;

class Client
{
    public:
        Client();
        Client(int &freeChairs);
        virtual ~Client() {};

        void sit();

    private:
        sem_t *barberChair;
        sem_t *waitChairs;
        sem_t *availability;
        int *freeChairs;
};

#endif // CLIENT_H
