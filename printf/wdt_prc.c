/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdt_prc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:00:02 by cgoth             #+#    #+#             */
/*   Updated: 2021/11/16 18:20:11 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calc_prec(const char *str, t_struct *sets, int i)
{
	sets->point = 1;
	if (str[++i] == '*')
	{
		i++;
		sets->prec = va_arg(sets->ap, int);
	}
	else if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
			sets->prec = sets->prec * 10 + (int)(str[i++] - 48);
	}
	if (sets->prec < 0)
	{
		sets->prec = 0;
		sets->point = 0;
	}
	else if (!sets->prec)
		sets->is_zero = 1;
	return (i);
}

int	wdt_prc(const char *str, t_struct *sets, int i)
{
	if (str[i] == '*')
	{
		i++;
		sets->width = va_arg(sets->ap, int);
		if (sets->width < 0)
		{
			sets->minus = 1;
			sets->width *= -1;
		}
	}
	else if (str[i] >= '1' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
			sets->width = sets->width * 10 + (int)(str[i++] - 48);
	}
	if (str[i] == '.')
		i = calc_prec(str, sets, i);
	return (i);
}
