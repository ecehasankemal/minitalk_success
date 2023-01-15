/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:28:19 by hece              #+#    #+#             */
/*   Updated: 2023/01/15 14:28:21 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

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
