/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:27:14 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/03 16:16:46 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	unsigned long int	result;
	size_t				i;
	int					znak;

	result = 0;
	i = 0;
	znak = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13) || str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		znak = -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57) && str[i] != '\0')
		result = result * 10 + (str[i++] - 48);
	if (result > 9223372036854775807 && znak == -1)
		return (0);
	else if (result == 9223372036854775807 && znak == -1)
		return (1);
	else if (result > 9223372036854775807 && znak == 1)
		return (-1);
	return ((int)result * znak);
}
