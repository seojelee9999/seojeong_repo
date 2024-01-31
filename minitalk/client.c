#include "minitalk.h"

void	sendsig(int id, int num)
{
	if (num != 0)
		kill(id, SIGUSR1);
	else
		kill(id, SIGUSR2);
}

void	end_bit(int pid)
{
	int bit;
	
	bit = 128;
	while (bit)
	{
		sendsig(pid, bit & 255);
		bit = bit >> 1;
		usleep(100);
	}
}
void	select_sig(char *pid, char *str)
{
	int	bit;
	int	int_pid;
	int	i;

	int_pid = ft_atoi(pid);
	i = 0;
	while (str[i])
	{
		bit = 128;
		while (bit)
		{
			sendsig(int_pid, bit & str[i]);
			bit = bit >> 1;
			usleep(100);
		}
		i++;
	}
	end_bit(int_pid);
}

void	final_sig(int sig)
{
	if (sig == SIGUSR1)
		exit(0);
}

int	main(int argc, char **argv)
{
	int	pid;
	
	signal(SIGUSR1, final_sig);
	if (argc != 3)
	{
		write(1, "ac or av error\n", 15);
		exit(0);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		if (pid < 100 || pid > 99999)
		{
			write(1, "pid is unvailid\n", 16);
			exit(0);
		}
		select_sig(argv[1], argv[2]);
	}
	return (0);
}
