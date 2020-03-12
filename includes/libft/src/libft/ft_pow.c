/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:53:55 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

unsigned long long	ft_pow(unsigned long long i, int pow)
{
	int res;

	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	res = i;
	while (pow > 0)
	{
		res = res * i;
		pow--;
	}
	return (res);
}
