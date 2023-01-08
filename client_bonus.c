/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:38:00 by hece              #+#    #+#             */
/*   Updated: 2023/01/08 05:38:11 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	ft_atoi(const char *str)
{
	int	iter;
	int	dop;
	int	result;

	iter = 0;
	dop = 1;
	result = 0;
	while ((str[iter] >= '\t' && str[iter] <= '\r') || str[iter] == ' ')
		iter++;
	if (str[iter] == '+' || str[iter] == '-')
	{
		if (str[iter] == '-')
			dop *= -1;
		iter++;
	}
	while (str[iter] >= '0' && str[iter] <= '9' && str[iter] != '\0')
	{
		result = ((str[iter] - '0') + (result * 10));
		iter++;
	}
	return (result * dop);
}

void	finish(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Mission Completed");
	}
}

void	get_binary(int pid, char *str)
{
	int	iter;
	int	index;

	index = 0;
	while (str[index])
	{
		iter = 7;
		while (iter >= 0)
		{
			if (str[index] >> iter & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
				iter--;
		}
		index++;
	}
	ft_printf("Signal send completed");
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, finish);
		get_binary(pid, argv[2]);
	}
	else
		ft_printf("Wrong argumants");
	return (0);
}
