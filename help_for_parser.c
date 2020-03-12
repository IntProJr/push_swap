/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:47:18 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		check_for_digits(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '\0')
		if (!ft_isdigit(str[i]))
		{
			if ((str[i] == '-' || str[i] == '+') && i == 0)
				continue;
			else
				return (0);
		}
	return (1);
}

int		check_valid_number(char *num_str, int num)
{
	if ((num == 0 && num_str[0] != '0' && num_str[1] != '0') ||
		!check_for_digits(num_str))
		return (0);
	return (1);
}
