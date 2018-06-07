#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char napisy[4][80] = {"Ha Ha ! To tylko sygnal powierzchowny!\n", "Tylko proces %d smieje sie syngalowi %d prosto w twarz!\n", "Auc, to bolalo!\n"};

int nr_napisu = 0;

void obsluga_sig_int(int sig)
{
    if(nr_napisu == 3)
    {
        puts("Dobrze! Dobrze! Już koncze");
        exit (1);
    }    
    printf(napisy[nr_napisu], getpid(), sig);
    nr_napisu = ((nr_napisu + 1) % 4); //tutaj zmiana 
    
}

/*void obsluga_sig_quit(int sig)
{
    printf("Z powrotem dziala!");
    signal(SIGINT, SIG_DFL);
}*/

int main(int argc, char** argv)
{
    signal(SIGINT, obsluga_sig_int);
    //int count = 0;
    int licznik;
    //sigset_t zestaw, wystapily;
    //sigemptyset(&zestaw);
    //sigaddset(&zestaw, SIGQUIT);
    //sigaddset(&zestaw, SIGINT);
    //sigprocmask(SIG_BLOCK, &zestaw, NULL);
    
    //sigpend(wystapily)
    //sigismember(&wystapily)
    
    
    
    //signal(SIGQUIT, obsluga_sig_quit);

        while (1)
        {
            printf("Czesc, tu proces: %d\n", getpid());
            sleep(1);
            licznik++;
        }

    
    return 0;
} 
