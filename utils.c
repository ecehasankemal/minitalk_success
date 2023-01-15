/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:28:35 by hece              #+#    #+#             */
/*   Updated: 2023/01/15 14:28:36 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
