/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:51:10 by cgoth             #+#    #+#             */
/*   Updated: 2021/11/17 13:55:43 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_sets
{
	va_list	ap;
	int		width;
	int		prec;
	int		minus;
	int		zero;
	int		space;
	int		hash;
	int		plus;
	int		total;
	int		perc;
	int		point;
	int		is_zero;
	int		hexlen;
}	t_struct;
int			ft_printf(const char *str, ...);
int			wdt_prc(const char *str, t_struct *sets, int i);
int			ft_hexlen(unsigned long long nbr, t_struct *sets);
int			ft_numlen(unsigned int num);
void		ft_putnbr_rec(unsigned int n, t_struct *sets);
void		print_num(t_struct *sets);
void		print_unum(t_struct *sets);
void		print_char(t_struct *sets, int pct);
void		print_str(t_struct *sets);
void		print_hex(t_struct *sets, const char type);
void		print_ptr(t_struct *sets);
void		ft_shift(t_struct *sets, int len);
void		ft_shift_str(t_struct *sets, int len, int c);
void		ft_put_null(t_struct *sets, int len);
#endif
