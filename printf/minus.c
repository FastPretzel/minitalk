/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:54:51 by cgoth             #+#    #+#             */
/*   Updated: 2021/11/16 17:54:56 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_shift(t_struct *sets, int len)
{
	char	ch;
	int		wdt;

	wdt = sets->width;
	if (!sets->minus && sets->zero && !sets->point)
		ch = '0';
	else
		ch = ' ';
	if (sets->prec > 0 && sets->prec > len)
		len = sets->prec;
	while (wdt-- > len)
		sets->total += write(1, &ch, 1);
}

void	ft_put_null(t_struct *sets, int len)
{
	int	prc;

	prc = sets->prec;
	while (prc-- > len)
		sets->total += write(1, "0", 1);
}

void	ft_shift_str(t_struct *sets, int len, int c)
{
	char	ch;
	int		wdt;

	wdt = sets->width;
	if (sets->prec > 0 && sets->prec < len)
		len = sets->prec;
	else if (!c && !sets->prec && sets->point)
		len = 0;
	if (c && sets->zero && !sets->minus)
		ch = '0';
	else
		ch = ' ';
	while (wdt-- > len)
		sets->total += write(1, &ch, 1);
}
