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

/**
 * @brief Main'den yollanılan her char karakter için 8 defa sinyal yollar
 * 
 * @param pid Servera ait tanımlama numarasını alır.
 * @param c Main'den yollanılan char karakteri alır.
 */
void	send_bit(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		sigaction(SIGUSR2, &g_act, NULL);
		i--;
	}
}

void	received_signal(int pid, siginfo_t *inf, void *context)
{
	context = 0;
	ft_printf("Signal received /Sender pid -> %d\n", inf->si_pid);
	pid = 0;
}

int	main(int ac, char **av)
{
	int	i;

	g_act.sa_flags = SA_SIGINFO;
	g_act.sa_sigaction = &received_signal;
	i = 0;
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			send_bit(ft_atoi(av[1]), av[2][i]);
			i++;
		}
	}
	return (0);
}
