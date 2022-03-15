#include "Barber.h"
#include <unistd.h>

Barber::Barber() {}

Barber::Barber(int &freeChairs) {
    sem_unlink("/barberChair");
    sem_unlink("/waitChairs");
    sem_unlink("/availability");

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
        sleep(10);
        sem_post(barberChair);
        sem_post(availability);
        cout << "Cabelo cortado" << endl;
    }
}
