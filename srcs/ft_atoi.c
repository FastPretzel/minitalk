/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:50:45 by cgoth             #+#    #+#             */
/*   Updated: 2022/01/21 16:59:20 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isspace(const char *nptr, int i)
{
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' || \
			nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	i = ft_isspace(nptr, i);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res * sign > 2147483647)
			return (-1);
		if (res * sign < -2147483648)
			return (0);
		res = res * 10 + (long long)(nptr[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}
