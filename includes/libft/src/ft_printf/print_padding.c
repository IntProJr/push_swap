/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:17:52 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/07 15:46:17 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printing_width(t_printf p, int written)
{
	int	spaces_printed;
	int	i;

	spaces_printed = 0;
	i = p.width_option - written;
	if (p.width_option > 0 && p.width_option > written && !p.znak_minus)
	{
		while (i-- > 0)
		{
			if (ft_strchr("cDOUCSsp", p.conversion_percent)
				&& (p.zero && (p.znak_minus || p.precision)))
			{
				ft_putchar('0');
				spaces_printed++;
			}
			else if (!p.zero || (ft_strchr("diuoxX", p.conversion_percent)
			&& p.precision && p.zero))
			{
				ft_putchar(' ');
				spaces_printed++;
			}
		}
	}
	return (spaces_printed);
}

int	print_zero_padding(t_printf p, int char_printed)
{
	int zero_printed;
	int i;

	zero_printed = 0;
	i = 0;
	if (p.zero == 1 && (p.width_option > char_printed))
	{
		i = p.width_option - char_printed;
		while (i > 0)
		{
			ft_putchar('0');
			zero_printed++;
			i--;
		}
	}
	return (zero_printed);
}

int	print_width_minus(t_printf p, int char_printed)
{
	int spaces_printed;
	int i;
	int	width;

	spaces_printed = 0;
	width = p.width_option;
	i = 0;
	if (width > 0 && width > char_printed && !p.zero && p.znak_minus)
	{
		i = width - char_printed;
		while (i > 0)
		{
			ft_putchar(' ');
			spaces_printed++;
			i--;
		}
	}
	return (spaces_printed);
}

int	print_precision(t_printf p, long long nb, int nb_len)
{
	int	zero_printed;
	int	i;

	zero_printed = 0;
	i = 0;
	if (nb < 0)
		nb_len -= 1;
	if (p.precision != -1 && p.precision > nb_len)
	{
		i = (p.precision - nb_len);
		while (i > 0)
		{
			ft_putchar('0');
			zero_printed++;
			i--;
		}
	}
	return (zero_printed);
}
