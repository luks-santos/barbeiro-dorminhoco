#include "Client.h"


Client::Client() {
    barberChair = sem_open("/barberChair", O_CREAT, S_IRWXU, 0);
    waitChairs = sem_open("/waitChairs", O_CREAT, S_IRWXU, 0);
    availability = sem_open("/availability", O_CREAT, S_IRWXU, 1);
}

Client::Client(int &freeChairs) {
    barberChair = sem_open("/barberChair", O_CREAT, S_IRWXU, 0);
    waitChairs = sem_open("/waitChairs", O_CREAT, S_IRWXU, 0);
    availability = sem_open("/availability", O_CREAT, S_IRWXU, 1);
    this->freeChairs = &freeChairs;
}

void Client::sit() {
    cout << "cliente entrou" << endl;
    sem_wait(availability);
    cout << *freeChairs << endl;
    if(*freeChairs > 0) {

        cout << "diminuindo cadeira" << endl;
        --*freeChairs;
        cout << *freeChairs << endl;

        sem_post(waitChairs);
        sem_post(availability);
        sem_wait(barberChair);
        cout << "Cliente feliz" << endl;

    } else {
        sem_post(availability);
       // cout<<" O Cliente foi embora"<<endl;
    }
}
