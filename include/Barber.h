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

#ifndef BARBER_H
#define BARBER_H

#include <semaphore.h>
//Biblioteca para funções sleep()
#include <unistd.h>
//Biblioteca para constantes de acesso aos semáforos S_IRWXU, O_CREAT
#include <fcntl.h>
#include <iostream>

using namespace std;

class Barber
{
    public:
        Barber();
        virtual ~Barber() {};
        void setFreeWaitChairs(int free);
        void cutHair();
        void unlink();
        int getFreeWaitChairs();
    private:
        int maxChairs;
        sem_t *barberChair;
        sem_t *waitChairs;
        sem_t *availability;
        sem_t *freeWaitChairs;
        sem_t *mutex;
};

#endif // BARBER_H
