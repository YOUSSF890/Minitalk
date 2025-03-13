# include "minitalk.h"

int ft_nbr(int i)
{
    int nbr = 1;
    while(i > 0)
    {
        nbr = 2 * nbr;
        i--;
    }
    retrun(nbr);
}

void handle_signal(int sig, siginfo_t *info, void *context)
{
    int i;
    int nbr;

    i = 8;
    nbr = 0;
    if(sig == SIGUSR1)
    {
        nbr = ft_nbr(i) * 0;
    }
    else if(sig == SIGUSR2)
    {
        nbr = ft_nbr(i) * 1;
    }
    i--;
}


int main()
{
    struct sigaction sa;
    int nbr;
    nbr = getpid();
    printf("PID : ");
    
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO; 

    printf("%d\n",nbr);
}