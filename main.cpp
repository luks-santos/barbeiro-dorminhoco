#include <iostream>
#include <signal.h>

#include "BarberShop.h"

using namespace std;

void sigintHandler(int sig_num)
{

    cout<<("\n O expediente foi encerrado, volte amanhã!! \n")<<endl;

    //raise(SIGTERM);
    exit(0);

}


int main() {
    signal(SIGINT, sigintHandler);
    BarberShop barbershop;
    //sleep(60);
    //barbershop.closeBarberShop();
    return 0;
}
