/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:27:54 by hece              #+#    #+#             */
/*   Updated: 2023/01/15 14:27:55 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct sigaction	g_act;

int	ft_atoi(const char *str)
{
	register int	iter;
	register int	result;

	iter = 0;
	result = 0;
	while ((str[iter] >= '\t' && str[iter] <= '\r') || str[iter] == ' ')
		iter++;
	while (str[iter] >= '0' && str[iter] <= '9' && str[iter] != '\0')
		result = ((str[iter++] - '0') + (result * 10));
	return (result);
}

void	send_bit(int pid, char c)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		if ((c << index) & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		sigaction(SIGUSR2, &g_act, NULL);
		index++;
	}
}

void	received_signal(int pid, siginfo_t *inf, void *context)
{
	(void)pid;
	(void)context;
	ft_printf("Signal received /Sender pid -> %d\n", inf->si_pid);
}

int	main(int ac, char *av[])
{
	int	index;

	g_act.sa_flags = SA_SIGINFO;
	g_act.sa_sigaction = &received_signal;
	index = 0;
	if (ac == 3)
	{
		while (av[2][index] != '\0')
		{
			send_bit(ft_atoi(av[1]), av[2][index]);
			index++;
		}
	}
	return (0);
}
