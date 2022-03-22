#ifndef BARBER_H
#define BARBER_H

#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

#include <iostream>
using namespace std;


class Barber
{
    public:
        Barber();
        virtual ~Barber() {};
        void setFreeChairs(int free);
        void cutHair();
        void unlink();
        int getValue();

    private:
        int maxChairs;
        sem_t *barberChair;
        sem_t *waitChairs;
        sem_t *availability;
        sem_t *freeChairs;
        sem_t *mutex;
};

#endif // BARBER_H
