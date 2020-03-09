/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:58:43 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 16:01:38 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int			find_max(t_stack *stk)
{
	int 	i;
	int 	max;

	i = stk->used_size - 1;
	max = stk->arr[i].index;
	while(i >= 0)
	{
		if (max < stk->arr[i].index)
			max = stk->arr[i].index;
		i--;
	}
	return (max);
}

int 		find_min(t_stack *stk)
{
	int 	i;
	int 	min;

	i = stk->used_size - 1;
	min = st->arr[i].index;
	while (i >= 0)
	{
		if (min > st->arr[i].index)
			min = stk->arr[i].index;
		i--;
	}
	return (min);
}
void		get_min_max(t_stac *stk)
{
	stk->min = find_min(stk);
	stk->max = find_max(stk);
}