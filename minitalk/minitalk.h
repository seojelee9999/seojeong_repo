#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/signal.h>

char	*ft_itoa(int n);
int		allocate_num(long n);
int		ft_strlen(const char *s);
int	ft_atoi(const char *str);
#endif