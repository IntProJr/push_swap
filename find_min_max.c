/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:58:43 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		find_min(t_stack *stack)
{
	int		i;
	int		min;

	i = stack->used_size - 1;
	min = stack->array[i].index;
	while (i >= 0)
	{
		if (min > stack->array[i].index)
			min = stack->array[i].index;
		i--;
	}
	return (min);
}

int		find_max(t_stack *stack)
{
	int		i;
	int		max;

	i = stack->used_size - 1;
	max = stack->array[i].index;
	while (i >= 0)
	{
		if (max < stack->array[i].index)
			max = stack->array[i].index;
		i--;
	}
	return (max);
}

void	find_max_min(t_stack *stack)
{
	stack->min = find_min(stack);
	stack->max = find_max(stack);
}
