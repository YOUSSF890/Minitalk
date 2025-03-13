# include "minitalk.h"

int ft_nbr(int i)
{
    int nbr = 1;
    while(i > 0)
    {
        nbr = 2 * nbr;
        i--;
    }
    // retrun (nbr);
}

void handle_signal(int sig, siginfo_t *info, void *context)
{
    int i;
    char nbr;
    static int				index;

    i = 8;
    if(sig == SIGUSR1)
    {
        nbr = nbr + (ft_nbr(i) * 0);
    }
    else if(sig == SIGUSR2)
    {
        nbr = nbr + (ft_nbr(i) * 1);
    }
    i--;
    if(i == 0)
    {
        write(1,&nbr,1);
    }
}


int main()
{
    struct sigaction sa;
    int nbr;
    nbr = getpid();
    printf("PID : ");
    
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    printf("%d\n",nbr);
}