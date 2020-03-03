/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:16:51 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/07 15:18:37 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x_l(int char_printed, t_printf p, unsigned long long nb)
{
	int	prec;

	prec = 0;
	char_printed += hash_length(p, nb);
	if (!(p.precision == -1 && nb == 0))
		char_printed += ft_hex_len(nb);
	if (p.precision > 0)
		prec = p.precision - ft_hex_len(nb);
	char_printed += printing_width(p, char_printed + (prec > 0 ? prec : 0));
	print_hash(p, nb);
	char_printed += print_precision(p, nb, ft_hex_len(nb));
	char_printed += print_zero_padding(p, char_printed);
	if (!(p.precision == -1 && nb == 0))
	{
		if (p.conversion_percent == 'x')
			ft_print_u_hex(nb, "0123456789abcdef");
		else if (p.conversion_percent == 'X')
			ft_print_u_hex(nb, "0123456789ABCDEF");
	}
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}
