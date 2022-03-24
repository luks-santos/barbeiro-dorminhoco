#ifndef BARBER_H
#define BARBER_H

#include <semaphore.h>
//Biblioteca para funções sleep()
#include <unistd.h>
//Biblioteca para constantes de acesso aos semáforos
#include <fcntl.h>
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
        int getFreeChairs();
    private:
        int maxChairs;
        sem_t *barberChair;
        sem_t *waitChairs;
        sem_t *availability;
        sem_t *freeChairs;
        sem_t *mutex;
};

#endif // BARBER_H
