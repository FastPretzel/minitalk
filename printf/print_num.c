/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:11:50 by cgoth             #+#    #+#             */
/*   Updated: 2021/11/16 18:48:07 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(unsigned int num)
{
	int	len;

	len = 1;
	while (num > 9)
	{
		len++;
		num /= 10;
	}
	return (len);
}

void	ft_putnbr_rec(unsigned int n, t_struct *sets)
{
	char	res;

	if (n / 10 != 0)
		ft_putnbr_rec(n / 10, sets);
	res = (n % 10) + '0';
	sets->total += write(1, &res, 1);
}

static void	pos_num(t_struct *sets, int num)
{
	if (sets->is_zero && !num)
		sets->width++;
	if (sets->plus || sets->space)
		sets->width--;
	if (sets->plus && sets->zero)
		sets->total += write(1, "+", 1);
	if (!sets->plus && sets->space && sets->zero)
		sets->total += write(1, " ", 1);
	if (sets->width && !sets->minus && sets->width >= sets->prec)
		ft_shift(sets, ft_numlen((unsigned int)num));
	if (sets->plus && !sets->zero)
		sets->total += write(1, "+", 1);
	if (!sets->plus && sets->space && !sets->zero)
		sets->total += write(1, " ", 1);
	if (sets->width && !sets->minus && sets->zero && sets->prec < 0)
		ft_shift(sets, ft_numlen((unsigned int)num));
	if (sets->prec > 0)
		ft_put_null(sets, ft_numlen((unsigned int)num));
	if (!sets->is_zero || (sets->is_zero && num))
		ft_putnbr_rec(num, sets);
	if (sets->width && sets->minus)
		ft_shift(sets, ft_numlen((unsigned int)num));
}

static void	neg_num(t_struct *sets, int num)
{
	sets->width--;
	if (sets->zero && !sets->point)
		sets->total += write(1, "-", 1);
	if (sets->width && !sets->minus && sets->prec < sets->width)
		ft_shift(sets, ft_numlen((unsigned int)(num *(-1))));
	if (!sets->zero || (sets->zero && sets->point))
		sets->total += write(1, "-", 1);
	if (sets->prec > 0)
		ft_put_null(sets, ft_numlen((unsigned int)(num *(-1))));
	ft_putnbr_rec(num *(-1), sets);
	if (sets->width && sets->minus)
		ft_shift(sets, ft_numlen((unsigned int)(num *(-1))));
}

void	print_num(t_struct *sets)
{
	int	num;

	num = va_arg(sets->ap, int);
	if (num >= 0)
		pos_num(sets, num);
	else
		neg_num(sets, num);
}
