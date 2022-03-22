#ifndef CLIENT_H
#define CLIENT_H

#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

#include <iostream>
using namespace std;

class Client
{
    public:
        Client();
        virtual ~Client() {};
        void setFreeChairs(int free);
        void sit();
        int getValue();
    private:
        int maxChairs;
        sem_t *barberChair;
        sem_t *waitChairs;
        sem_t *availability;
        sem_t *freeChairs;
        sem_t *mutex;
};

#endif // CLIENT_H
