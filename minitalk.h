#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_atoi(char *str);
void ft_anime(int nbr, char c);
void handle_signal(int sig, siginfo_t *info, void *context);

#endif