/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:00:49 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hash(t_printf p, long long nb)
{
	char	c;
	int		i;

	i = ft_u_len_base(nb, 8);
	c = p.conversion_percent;
	if (p.hash && ft_strchr("oO", c) && nb != 0 && i >= p.precision)
		return (write(1, "0", 1));
	if (p.hash && ft_strchr("oO", c) && p.precision == -1 && nb == 0)
		return (write(1, "0", 1));
	else if (p.hash && c == 'x' && nb != 0)
		return (write(1, "0x", 2));
	else if (p.hash && c == 'X' && nb != 0)
		return (write(1, "0X", 2));
	return (0);
}

int		hash_length(t_printf p, long long nb)
{
	if (p.hash && ft_strchr("oO", p.conversion_percent) && nb != 0)
		return (1);
	else if (p.hash && p.conversion_percent == 'x' && nb != 0)
		return (2);
	else if (p.hash && p.conversion_percent == 'X' && nb != 0)
		return (2);
	return (0);
}

int		print_space(t_printf p, long long nb)
{
	if (p.space && ft_strchr("diD", p.conversion_percent))
	{
		if (nb >= 0)
		{
			ft_putchar(' ');
			return (1);
		}
	}
	return (0);
}

int		print_plus(t_printf p, long long nb)
{
	if (p.znak_plus && nb >= 0 && !ft_strchr("uU", p.conversion_percent))
	{
		ft_putchar('+');
		return (1);
	}
	return (0);
}
