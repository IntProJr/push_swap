/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:51:51 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 16:01:38 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int 		check_args(int argc, char *argv[])
{
	int 		i;
	int 		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] > 32 && argv[i][j] < 127)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] && str[i] == ' ') || str[i] == '\t')
			i++;
		if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			i++;
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (i);
}

int	validate_args(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if ((validate_arg(arr[i])) == (-1))
			return (-1);
		i++;
	}
	return (i);
}