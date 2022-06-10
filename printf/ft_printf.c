/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:39:29 by cgoth             #+#    #+#             */
/*   Updated: 2021/11/17 13:58:52 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_struct	*sets_init(t_struct *sets)
{
	sets->width = 0;
	sets->prec = 0;
	sets->minus = 0;
	sets->zero = 0;
	sets->space = 0;
	sets->hash = 0;
	sets->plus = 0;
	sets->perc = 0;
	sets->point = 0;
	sets->is_zero = 0;
	sets->hexlen = 0;
	return (sets);
}

static int	type_conv(const char *type, t_struct *sets, int i)
{
	if (type[i] == '*' || type[i] == '.' || (type[i] >= '1' && type[i] <= '9'))
		i = wdt_prc(type, sets, i);
	if (type[i] == 'c')
		print_char(sets, 0);
	if (type[i] == 's')
		print_str(sets);
	if (type[i] == 'd' || type[i] == 'i')
		print_num(sets);
	if (type[i] == 'x' || type[i] == 'X')
		print_hex(sets, type[i]);
	if (type[i] == 'p')
		print_ptr(sets);
	if (type[i] == 'u')
		print_unum(sets);
	if (type[i] == '%')
		print_char(sets, 1);
	return (i);
}

static int	flags_proc(const char *str, t_struct *sets, int i)
{
	while (str[i] != 'u' && str[i] != 'd' && str[i] != 'i' && \
			str[i] != 'c' && str[i] != 's' && str[i] != 'p' && \
			str[i] != 'x' && str[i] != 'X' && str[i] != '%' && \
			str[i] != '.' && str[i] != '*' && !(str[i] >= '1' && str[i] <= '9'))
	{
		if (str[i] == '-')
			sets->minus = 1;
		if (str[i] == '0')
			sets->zero = 1;
		if (str[i] == '#')
			sets->hash = 1;
		if (str[i] == ' ')
			sets->space = 1;
		if (str[i] == '+')
			sets->plus = 1;
		i++;
	}
	i = type_conv(str, sets, i);
	sets_init(sets);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			res;
	t_struct	*sets;	

	i = -1;
	res = 0;
	sets = (t_struct *)malloc(sizeof(t_struct));
	if (!sets)
		return (-1);
	sets_init(sets);
	sets->total = 0;
	va_start(sets->ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
			i = flags_proc(str, sets, ++i);
		else
			res += write(1, &str[i], 1);
	}
	res += sets->total;
	va_end(sets->ap);
	free(sets);
	sets = NULL;
	return (res);
}
