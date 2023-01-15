/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:28:27 by hece              #+#    #+#             */
/*   Updated: 2023/01/15 14:29:04 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Gelen sinyal tipine göre bit kaydırma işlemi yapar.
 * 
 * @param signum "sigaction" ile gelen sinyalin tipini alır. SIGUSR1 - SIGUSR2
 * @param inf Client tarafından yollanılan bilgileri tutan struct yapısı
 * @param context Alt metin olarak kullanıla bilir boş da bırakılabilir (:
 */
void	signal_decode(int signum, siginfo_t *inf, void *context)
{
	static int	i = 7;
	static char	a;

	context = 0;
	if (signum == SIGUSR1)
		a = a | 1 << i;
	else if (signum == SIGUSR2)
		a = a | 0 << i;
	i--;
	if (i < 0)
	{
		ft_printf("%c", a);
		kill (inf->si_pid, SIGUSR2);
		a = 0;
		i = 7;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &signal_decode;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
