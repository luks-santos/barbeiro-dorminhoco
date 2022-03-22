#include <iostream>
#include <signal.h>

#include "BarberShop.h"

using namespace std;



int main() {
    BarberShop barbershop;
    sleep(60);
    barbershop.closeBarberShop();
    return 0;
}
