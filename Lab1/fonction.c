#include "fonction.h"

void * writter(void *index){
    int *valeur = (int*)index;
    printf("[%ld] Hello, World %d!!!\n", pthread_self(), *valeur);
    return 0;
}