/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:09:17 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/13 16:59:42 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_va_arg(va_list *arg, t_printf p)
{
	long double	nb;

	if (p.bl)
		nb = (long double)va_arg(*arg, long double);
	else
		nb = (long double)va_arg(*arg, double);
	return (nb);
}

static int	ft_write_nan(t_printf p, char *s, char char_printed, long double nb)
{
	int len;

	len = (nb == -(1.0 / 0.0)) ? 4 : 3;
	char_printed += len;
	if (p.znak_plus == 1)
		char_printed++;
	if (p.space && nb != -(1.0 / 0.0) && p.inf)
	{
		ft_putchar(' ');
		char_printed++;
	}
	char_printed += printing_width(p, char_printed);
	if (nb == -(1.0 / 0.0))
		ft_putchar('-');
	if (p.znak_plus == 1)
		ft_putchar('+');
	ft_putstr(s);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}

static int	ft_nun_inf(t_printf p, char char_printed, long double nb)
{
	char *s;

	if (p.conversion_percent == 'F')
		s = p.inf ? "INF" : "NAN";
	else
		s = p.inf ? "inf" : "nan";
	char_printed += ft_write_nan(p, s, char_printed, nb);
	return (char_printed);
}

int			print_f(va_list *arg, int char_printed, t_printf p)
{
	char		*integer;
	char		*decimal;
	long double	nb;

	nb = ft_va_arg(arg, p);
	p = flag_manager_f(nb, p);
	if (!p.inf && !p.nan)
	{
		nb = round_ld(nb, p);
		integer = integer_f(nb);
		decimal = decimal_f(nb, &p, integer);
		char_printed += write_f(p, integer, decimal, nb);
		free(integer);
		free(decimal);
	}
	else
		char_printed += ft_nun_inf(p, char_printed, nb);
	return (char_printed);
}
