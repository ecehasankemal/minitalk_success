#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ptr)
{
		static int	index;
		static char	chr;

		(void)ptr;
		if (sig == SIGUSR1)
				chr = (chr << 1) | 1;
		else if (sig == SIGUSR2)
				chr = (chr << 1);
		index++;
		if (index == 8)
		{
				ft_printf("%c", chr);
				if (!chr)
				{
						usleep(400);
						kill(info->si_pid, SIGUSR1);
				}
				index = 0;
				chr = 0;
		}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("SERVER : Server started\n -> %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
			pause();
	return (0);
}
