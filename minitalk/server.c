#include "minitalk.h"

void	end(int id)
{
	write(1, "\n", 1);
	kill(id, SIGUSR1);
}

void	handler(int signo, siginfo_t *info, void *tmp)
{
	static int		bit;
	static int		cnt;

	if (tmp != 0)
		tmp = 0;
	if (cnt < 8)
	{
		bit = bit << 1;
		if (signo == SIGUSR1)
			bit = bit | 1;
		cnt++;
	}
	if (cnt == 8)
	{
		if (bit == 255)
			end(info->si_pid);
		else
			write(1, &bit, 1);
		bit = 0;
		cnt = 0;
	}
}

int	main(void)
{
	int					pid;
	char				*pid_str;
	struct sigaction	sigact;

	pid = getpid();
	pid_str = ft_itoa(pid);
	write(1, pid_str, ft_strlen(pid_str));
	free(pid_str);
	write(1, "\n", 1);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (0);
}
