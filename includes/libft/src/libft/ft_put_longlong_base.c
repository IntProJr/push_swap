/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_longlong_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:06:58 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_put_longlong_base(long long nbr, char base)
{
	unsigned long long nb;

	if (base > 1 && base <= 10)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			if (nbr != LONG_LONG_MIN)
				nbr *= -1;
		}
		nb = nbr;
		if (nb >= (unsigned long long)base)
			ft_put_longlong_base(nb / base, base);
		ft_putchar(nb % base + '0');
	}
	else if (base == 1)
		ft_putnchar('1', nbr);
}
