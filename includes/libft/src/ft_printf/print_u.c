/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:27:38 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u_l(int char_printed, t_printf p, unsigned long long nb)
{
	int	prec;
	int	len;

	prec = p.precision;
	len = ft_u_longlong_len(nb);
	char_printed += print_plus(p, nb);
	char_printed += print_space(p, nb);
	if (!(prec == -1 && nb == 0))
		char_printed += len;
	if (prec > 0 && prec > len)
		char_printed += prec - len;
	char_printed += printing_width(p, char_printed);
	char_printed += print_zero_padding(p, char_printed);
	print_precision(p, nb, len);
	if (!(prec == -1 && nb == 0))
		ft_put_u_longlong_base(nb, 10);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}
