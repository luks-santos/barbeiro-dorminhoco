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

#ifndef CLIENT_H
#define CLIENT_H

#include <semaphore.h>
//Biblioteca para funções sleep()
#include <unistd.h>
//Biblioteca para constantes de acesso aos semáforos S_IRWXU, O_CREAT
#include <fcntl.h>
#include <iostream>

using namespace std;

class Client
{
    public:
        Client();
        virtual ~Client() {};
        void setFreeWaitChairs(int free);
        void sitOnChair();
        int getFreeWaitChairs();
    private:
        int maxChairs;
        sem_t *barberChair;
        sem_t *waitChairs;
        sem_t *availability;
        sem_t *freeWaitChairs;
        sem_t *mutex;
};

#endif // CLIENT_H
