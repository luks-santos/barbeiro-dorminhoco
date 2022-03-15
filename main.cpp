#include <iostream>
#include <thread>
#include "BarberShop.h"
#include "Client.h"
#include <vector>

using namespace std;

int main()
{
    int cad = 5;
    int *cadap = &cad;
    vector<thread> vthread;

    Barber barber(*cadap);
    vthread.push_back(thread(&Barber::cutHair, &barber));
    Client *clis = new Client[10];

      for(int i = 0; i < 10; i++){
        clis[i].freeChairs = cadap;
        vthread.push_back(thread(&Client::sit, clis[i]));
    }

      for(int i = 0; i < 10; i++){
        vthread[i].join();
    }
    return 0;
}
