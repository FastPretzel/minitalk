/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:28:58 by cgoth             #+#    #+#             */
/*   Updated: 2021/11/16 18:29:56 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(unsigned long long nbr, char *base, t_struct *sets)
{
	int	i;

	if (nbr > 15)
		ft_putptr(nbr / 16, base, sets);
	i = nbr % 16;
	sets->total += write (1, &base[i], 1);
}

void	print_ptr(t_struct *sets)
{
	unsigned long long	ptr;

	ptr = va_arg(sets->ap, unsigned long long);
	sets->width -= 2;
	if (sets->is_zero && !ptr)
		sets->width++;
	if (sets->width && !sets->minus)
		ft_shift(sets, ft_hexlen(ptr, sets));
	sets->total += write(1, "0x", 2);
	if (!sets->is_zero || (sets->is_zero && ptr))
		ft_putptr(ptr, "0123456789abcdef", sets);
	if (sets->width && sets->minus)
		ft_shift(sets, ft_hexlen(ptr, sets));
}
