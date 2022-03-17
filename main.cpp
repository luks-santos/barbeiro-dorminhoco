#include <iostream>
#include "BarberShop.h"
#include <signal.h>

#include <stdio.h>

using namespace std;



void sigintHandler(int sig_num)
{

    printf("\n O expediente foi encerrado \n");
    raise(SIGTERM);

}

int main()
{
    signal(SIGINT, sigintHandler);
    int chairs = 5;
    BarberShop barberShop(chairs);
    barberShop.openBarberShop();
    return 0;


    //while(true);
}
