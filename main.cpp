/*********************************************************
 * Trabalho da disciplina de Sistemas Operacionais       *
 *               Barbeiro Dorminhoco                     *
 *                                                       *
 * Curso: Bacharelado em Engenharia da Computação        *
 * Professor: Samuel Dias                                *
 *                                                       *
 * Autores:                                              *
 * Lucas Batista dos Santos - 0048505                    *
 * Jorge Luís Vieira Murilo - 0027752                    *
 ********************************************************/
#include "BarberShop.h"
#include <signal.h>
#include <iostream>
using namespace std;

//Tratador de sinal CTRL-C
void closeBarberShop(int sig)
{
    cout << "\nO expediente foi encerrado, volte amanhã!!" << endl;
    exit(0);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    signal(SIGINT, closeBarberShop); //Captura o sinal do crtl+c
    BarberShop barbershop;
    return 0;
}
