#ifndef BARBER_H
#define BARBER_H

#include <semaphore.h>
#include <fcntl.h>
#include <iostream>
using namespace std;


class Barber
{
    public:
        Barber();
        Barber(int &freeChairs);
        virtual ~Barber() {};

        void cutHair();
        int *freeChairs;
    private:
        sem_t *barberChair;
        sem_t *waitChairs;
        sem_t *availability;

};

#endif // BARBER_H
