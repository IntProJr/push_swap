/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:53:19 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_longlong_d(long long nbr)
{
	char sign;

	sign = (nbr < 0) ? -1 : 1;
	if (nbr >= 10 || nbr <= -10)
		ft_put_longlong_d(nbr / 10);
	ft_putchar((nbr % 10) * sign + '0');
}

int			print_d_longlong(int char_printed, t_printf p, long long nb)
{
	int nb_len;

	nb_len = ft_longlong_len(nb);
	if (p.znak_plus && nb >= 0)
		char_printed += 1;
	char_printed += print_space(p, nb);
	if (!(p.precision == -1 && nb == 0))
		char_printed += nb_len;
	if (p.precision > 0 && p.precision > nb_len && nb >= 0)
		char_printed += p.precision - nb_len;
	if (p.precision > 0 && p.precision >= nb_len && nb < 0)
		char_printed += p.precision - nb_len + 1;
	char_printed += printing_width(p, char_printed);
	print_plus(p, nb);
	if (nb < 0)
		ft_putchar('-');
	char_printed += print_zero_padding(p, char_printed);
	print_precision(p, nb, nb_len);
	if (!(p.precision == -1 && nb == 0))
		ft_put_longlong_d(nb);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}
