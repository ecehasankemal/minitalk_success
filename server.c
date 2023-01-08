/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:38:36 by hece              #+#    #+#             */
/*   Updated: 2023/01/08 05:38:37 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	take_it(int sig)
{
	static unsigned char	c;
	static int				i;

	if (sig == SIGUSR1)
		c = c | 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
	c = c << 1;
}

int	main(void)
{
	ft_printf("\033[92mServer PID: \033[0m");
	ft_printf("\033[93m%d\033[0m",getpid());
	ft_printf("\n");
	while (1)
	{
		signal(SIGUSR1, take_it);
		signal(SIGUSR2, take_it);
	}
	return (0);
}
