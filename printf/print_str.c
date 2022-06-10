/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:36:42 by cgoth             #+#    #+#             */
/*   Updated: 2021/11/16 18:39:07 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_char(t_struct *sets, int pct)
{
	char	ch;

	if (pct)
		ch = '%';
	else
		ch = va_arg(sets->ap, int);
	if (sets->width > 1 && !sets->minus)
		ft_shift_str(sets, 1, 1);
	sets->total += write(1, &ch, 1);
	if (sets->width > 1 && sets->minus)
		ft_shift_str(sets, 1, 1);
}

void	print_str(t_struct *sets)
{
	char	*str;
	int		i;
	int		prc;

	i = 0;
	prc = sets->prec;
	str = va_arg(sets->ap, char *);
	if (!str)
		str = "(null)";
	if (sets->prec > sets->width)
		sets->prec = sets->width;
	if (sets->width && !sets->minus && sets->width >= sets->prec)
		ft_shift_str(sets, ft_strlen(str), 0);
	while (str[i] && prc <= 0 && !sets->point)
		sets->total += write(1, &str[i++], 1);
	while (str[i] && prc-- > 0 && sets->point)
		sets->total += write(1, &str[i++], 1);
	if (sets->width && sets->minus)
		ft_shift_str(sets, ft_strlen(str), 0);
}
