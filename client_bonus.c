#include "minitalk.h"

int		g_len;

void	ft_transmit(int sig)
{
		if (sig == SIGUSR1)
				ft_printf("%d, charanters succesfully transmitted.\n");
		exit(1);
}

void	send_data(char c, int pid)
{
		int	index;

		index = 0;
		while (index < 8)
		{
				if (c << 1 & 0b10000000)
						kill(pid, SIGUSR2);
				else
						kill(pid, SIGUSR1);
				index++;
				usleep(400);
		}
}

int	main(int ac, char *av[])
{
	int	pid;
	int	index;

	index = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][index])
			send_data(av[2][index++], pid);
		send_data('\0', pid);
		g_len = index;
		signal(SIGUSR1, ft_transmit);
		while (1)
			pause();
	}
	else
		ft_printf("CLIENT : FORMAT Error!\nSend as ./client <PID> <MESSAGE>\n");
}
