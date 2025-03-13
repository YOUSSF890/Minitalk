#include "minitalk.h"

int ft_atoi(char *input)
{
    long nbr;
    int i;

    nbr = 0;
    i = 0;
    if (input[0] == '\0')
        (write(1, "Error in PID\n", 14), exit(1));
    while(input[i])
    {
        if (input[i] < '0' || input[i] > '9')
            (write(1, "Error in PID\n", 14), exit(1));
        nbr = nbr * 10 + (input[i] - 48);
        i++;
    }
    if (nbr == 0 || nbr > 2147483647)
        (write(1, "Error in PID\n", 14), exit(1));
    return (nbr);
}

void ft_anime(int nbr, char c)
{
    int i;

    i = 0;
    while(i < 8)
    {
        if(c % 2 == 0)
        {
            if (kill(nbr, SIGUSR1) == -1)
                (write(1, "Error in PID\n", 14), exit(1));
        }
        else
        {
            if (kill(nbr, SIGUSR1) == -1)
                (write(1, "Error in PID\n", 14), exit(1));
        }
        c = c / 2;
        i++;
    }
    usleep(200);
    usleep(200);
}

int main(int ac, char *av[])
{
    int nbr;
    int j;

    j = 0;
    if (ac != 3)
        return(write(1,"Error in argemont\n",19), 0);

    nbr = ft_atoi(av[1]);
    j = 0;
    while(av[2][j])
    {
        ft_anime(nbr, av[2][j]);
        j++;
    }
}