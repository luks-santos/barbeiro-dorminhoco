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

#include "Barber.h"

Barber::Barber()
{
    //Caso os semáforos ainda estão com nome faz o fechamento destes
    unlink();
    //Inicia novos semáforos com nome
    barberChair = sem_open("/barberChair", O_CREAT, S_IRWXU, 0);
    waitChairs = sem_open("/waitChairs", O_CREAT, S_IRWXU, 0);
    availability = sem_open("/availability", O_CREAT, S_IRWXU, 1);
    mutex =  sem_open("/mutex", O_CREAT, S_IRWXU, 1);
}

void Barber::setFreeWaitChairs(int free)
{
    freeWaitChairs = sem_open("/freeWaitChairs", O_CREAT, S_IRWXU, free);
    maxChairs = free;
}

void Barber::cutHair()
{
     while(true){
        //Se não possuir clientes na barbearia
        if(getFreeWaitChairs() == maxChairs){
            //Seção crítica para cout
            sem_wait(mutex);
            cout << "Não há clientes para atender, o Barbeiro foi dormir. zzz" << endl;
            sem_post(mutex);
        }
        //Espera cliente sentar e sinalziar que está pronto para cortar cabelo
        sem_wait(waitChairs);
        //Espera liberar seção critica
        sem_wait(availability);
        //Cliente libera cadeira livres
        sem_post(freeWaitChairs);
        //Seção crítica para cout
        sem_wait(mutex);
        cout << "O Barbeiro está cortando o Cabelo do Cliente " << (maxChairs - getFreeWaitChairs()) + 1 << "." << endl;
        sem_post(mutex);
        //Tempo para cortar cabelo, pode variar para cliente
        sleep(rand() % 6);
        //Avisa que terminou de cortar o cabelo
        sem_post(barberChair);
        //Libera seção critica para novo cliente
        sem_post(availability);
         //Seção crítica para cout
        sem_wait(mutex);
        cout << "Cabelo do cliente " << (maxChairs - getFreeWaitChairs()) + 1  << " foi cortado." << endl;
        sem_post(mutex);
    }
}
//Retorna quantidade de cadeiras de espera disponíveis
int Barber::getFreeWaitChairs()
{
    int *aux = new int();
    sem_getvalue(freeWaitChairs, aux);
    int value = *aux;
    delete aux; aux = nullptr;
    return value;
}
//Remove nome dos semáforos
void Barber::unlink()
{
    sem_unlink("/barberChair");
    sem_unlink("/waitChairs");
    sem_unlink("/availability");
    sem_unlink("/mutex");
    sem_unlink("/freeWaitChairs");
}
