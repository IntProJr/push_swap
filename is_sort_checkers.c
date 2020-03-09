/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort_checkers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:12:41 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 16:12:41 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int 	is_it_sort(t_stack *a)
{
	int		i;

	if (a == NULL)
		return (-1);
	i = a->used_size - 1;
	while (i > 0)
	{
		if (a->arr[i].val > a->arr[i - 1].val)
			return (1);
		i--;
	}
	return (0);
}

int 	is_it_dup(t_stack *a)
{
	int		i;
	int 	j;
	int 	duplicate;

	if (a == NULL)
		return (-1);
	i = a->used_size - 1;
	j = 0;
	duplicate = 0;
	while (i >= 0)
	{
		j = 0;
		f = 0;
		while (j < a->used_size)
		{
			if (a->arr[i].val == a->arr[j].val)
				duplicate++;
			j++;
		}
		if (duplicate > 1)
			return (1);
		i--;
	}
	return (0);
}