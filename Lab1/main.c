
#include "fonction.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Forget to pass n parameter!!\n");
        return 1;
    }
    const long n = atol(argv[1]);
    pthread_t tid[n];
    int index_tab[n];

    for (int i = 0; i < n; i++)
    {
        index_tab[i] = i;
        pthread_create(&tid[i], NULL, writter, (index_tab + i));
    }

    /***
     * Une fois que la boucle for qui créée les 3 threads terminent, nous avons dès à présent
     * 4 séquences d'execution et donc l'ordre d'éxécution des threads devient aléatoire mais 
     * par contre si le main se termine en premier l'OS coupe les autres threads.
     */
    printf("Main quitting\n");

    // for (int i=0; i<n ; i++){
    //     pthread_join(tid[i], NULL);
    // }

    //pthread_exit(NULL);

    return 0;
}