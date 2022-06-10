/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:38 by cgoth             #+#    #+#             */
/*   Updated: 2021/11/16 18:36:53 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned int nbr, char *base, t_struct *sets)
{
	int	i;

	if (nbr > 15)
		ft_puthex(nbr / 16, base, sets);
	i = nbr % 16;
	sets->total += write (1, &base[i], 1);
}

int	ft_hexlen(unsigned long long nbr, t_struct *sets)
{
	if (nbr > 15)
		ft_hexlen(nbr / 16, sets);
	sets->hexlen++;
	return (sets->hexlen);
}

static void	up_case(t_struct *sets, unsigned int hex)
{
	if (sets->hash && hex > 0)
		sets->total += write(1, "0X", 2);
	if (sets->prec > 0)
		ft_put_null(sets, sets->hexlen);
	if (!sets->is_zero || (sets->is_zero && hex))
		ft_puthex(hex, "0123456789ABCDEF", sets);
}

static void	low_case(t_struct *sets, unsigned int hex)
{
	if (sets->hash && hex > 0)
		sets->total += write(1, "0x", 2);
	if (sets->prec > 0)
		ft_put_null(sets, sets->hexlen);
	if (!sets->is_zero || (sets->is_zero && hex))
		ft_puthex(hex, "0123456789abcdef", sets);
}

void	print_hex(t_struct *sets, const char type)
{
	unsigned int	hex;

	hex = va_arg(sets->ap, unsigned int);
	if (sets->is_zero && !hex)
		sets->width++;
	ft_hexlen(hex, sets);
	if (sets->width && sets->hash && hex > 0)
		sets->width -= 2;
	if (sets->width && !sets->minus && sets->width >= sets->prec)
		ft_shift(sets, sets->hexlen);
	if (type == 'X')
		up_case(sets, hex);
	else if (type == 'x')
		low_case(sets, hex);
	if (sets->width && sets->minus)
		ft_shift(sets, sets->hexlen);
}
