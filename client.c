#include "minitalk.h"

void	send_data(char c, int pid)
{
		int	index;

		index = 0;
		while (index < 8)
		{
				if (c << index & 0b10000000)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				index++;
				usleep(700);
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
		while (av[2][index] != '\0')
		{
			send_data(av[2][index++], pid);
		}
	}
	else
		ft_printf("CLIENT : FORMAT Error!\nSend as ./client <PID> <MESSAGE>\n");
	return (0);
}
