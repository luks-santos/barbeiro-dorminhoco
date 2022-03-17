#include <iostream>
#include <signal.h>
#include <stdio.h>

#include "BarberShop.h"

using namespace std;



void sigintHandler(int sig_num)
{
    cout << "\nO expediente foi encerrado" << endl;
    raise(SIGTERM);

}

int main()
{
    signal(SIGINT, sigintHandler);
    int chairs = 5;
    BarberShop barberShop(chairs);
    barberShop.openBarberShop();
    return 0;
}
