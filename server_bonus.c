/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:17:44 by hece              #+#    #+#             */
/*   Updated: 2023/01/08 05:53:33 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	take_it_b(int sig, siginfo_t *info, void *context)
{
	static char		str = 0;
	static pid_t	client_id = 0;
	static int		get_byte = 0;

	(void)context;
	if (client_id == 0)
		client_id = info->si_pid;
	if (sig == SIGUSR1)
		str = str | 1;
	if (++get_byte == 8)
	{
		get_byte = 0;
		if (!str)
		{
			kill(client_id, SIGUSR1);
			client_id = 0;
			ft_printf("\n");
		}
		ft_printf("%c", str);
		str = 0;
	}
	else
		str = str << 1;
}
int	main(void)
{
	struct sigaction client;

	client.sa_sigaction = take_it_b;
	client.sa_flags = SA_SIGINFO;
	ft_printf("\033[92mServer PID: \033[0m");
	ft_printf("\033[93m%d\033[0m",getpid());
	ft_printf("\n");
	while (1)
	{
		sigaction(SIGUSR1, &client, 0);
		sigaction(SIGUSR2, &client, 0);
	}
	return (0);
}
