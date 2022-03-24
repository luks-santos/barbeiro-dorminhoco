#include <iostream>
#include <signal.h>

#include "BarberShop.h"

using namespace std;

//Tratador de sinal CTRL-C
void sigintHandler(int sig)
{
    cout << "O expediente foi encerrado, volte amanhã!!" << endl;
    exit(0);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    signal(SIGINT, sigintHandler);
    BarberShop barbershop;
    return 0;
}
