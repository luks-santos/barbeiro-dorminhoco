#ifndef BARBER_H
#define BARBER_H

#include <semaphore.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;


class Barber
{
    public:
        Barber();
        Barber(int &freeChairs);
        virtual ~Barber() {};
        void setFreeChairs(int &freeChairs);
        void cutHair();
        void unlink();
        int maxChairs;
    private:
        sem_t *barberChair;
        sem_t *waitChairs;
        sem_t *availability;
        int *freeChairs;

};

#endif // BARBER_H
