#include "Barber.h"

Barber::Barber() {
    barberChair = sem_open("/barberChair", O_CREAT, S_IRWXU, 0);
    waitChairs = sem_open("/waitChairs", O_CREAT, S_IRWXU, 0);
    availability = sem_open("/availability", O_CREAT, S_IRWXU, 1);
}

Barber::Barber(int &freeChairs) {
    barberChair = sem_open("/barberChair", O_CREAT, S_IRWXU, 0);
    waitChairs = sem_open("/waitChairs", O_CREAT, S_IRWXU, 0);
    availability = sem_open("/availability", O_CREAT, S_IRWXU, 1);
    this->freeChairs = &freeChairs;
}


void Barber::cutHair() {

     while(true){

        cout << "Esperando Cliente..." << endl;
        sem_wait(waitChairs);
        sem_wait(availability);

        cout << "Atendendo Cliente" << endl;
        ++*freeChairs;
        cout << "Cadeira foi livre " << *freeChairs << endl;

        sem_post(barberChair);
        sem_post(availability);
        cout << "Cabelo cortado" << endl;
    }
}
