/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_and_middle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:05:45 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/03 17:15:33 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Проверка наличия первого аргумента, функция вернёт '0' при отсутствии
** параметров или non-printable characters
*/

int 		check_args(char *argv[], int argc)
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