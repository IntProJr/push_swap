/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:18:59 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/07 15:18:37 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_print_u_hex(unsigned long long nb, const char *str)
{
	if (nb < 16)
		ft_putchar(str[nb]);
	else
	{
		ft_print_u_hex(nb / 16, str);
		ft_putchar(str[nb % 16]);
	}
}
