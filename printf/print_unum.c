/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:31:30 by cgoth             #+#    #+#             */
/*   Updated: 2021/11/16 18:35:12 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unum(t_struct *sets)
{
	unsigned int	unum;

	unum = va_arg(sets->ap, unsigned int);
	if (sets->is_zero && !unum)
		sets->width++;
	if (sets->width && !sets->minus)
		ft_shift(sets, ft_numlen(unum));
	if (sets->prec > 0)
		ft_put_null(sets, ft_numlen(unum));
	if (!sets->is_zero || (sets->is_zero && unum))
		ft_putnbr_rec(unum, sets);
	if (sets->width && sets->minus)
		ft_shift(sets, ft_numlen(unum));
}
