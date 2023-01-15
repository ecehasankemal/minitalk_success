#include "minitalk.h"

void	handler(int sig)
{
	static int	index;
	static char	chr;

	if (sig == SIGUSR1)
		chr = (chr << 1) | 1;
	else if (sig == SIGUSR2)
		chr = (chr << 1);
	index++;
	if (index == 8)
	{
		ft_printf("%c", chr);
		index = 0;
		chr = 0;
	}
}

int	main(void)
{
	ft_printf("SERVER : Server started\nPID -> %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
