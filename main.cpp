#include <iostream>
#include <thread>
#include "BarberShop.h"
#include "Client.h"

using namespace std;

int main()
{

    int cadeiras = 5;
    int *cd = &cadeiras;

    Barber *b = new Barber(*cd);
    thread(&Barber::cutHair, b).detach();

    for (int i = 0; i < 20; i++) {
        Client *c = new Client(*cd);
         thread(&Client::sit, c).join();
    }



    return 0;
}
