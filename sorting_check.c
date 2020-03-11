/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:40:28 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/10 21:21:49 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int 	range_sort(t_stack *stack_a, int bottom, int top)
{
	int 	i;

	if (stack_a == NULL)
		return (-1);
	i = stack_a->used_size - 1;
	while (i >= 0)
	{
		if (stack_a->array[i].index != stack_a->min &&
		stack_a->array[i].index != stack_a->max)
		{
			if (stack_a->array[i].index > bottom &&
			stack_a->array[i].index < top)
				return (-1);
		}
		i--;
	}
	return (0);
}

int 	more_sort(t_stack *stack_a, int mid)
{
	int 	i;

	if (stack_a == NULL)
		return (-1);
	i = stack_a->used_size - 1;
	while (i >= 0)
	{
		if (stack_a->array[i].index != stack_a->max &&
		stack_a->array[i].index >= mid)
			return (-1);
		i--;
	}
	return (0);
}

int 	less_sort(t_stack *stack_a, int mid)
{
	int 	i;

	if (stack_a == NULL)
		return (-1);
	i = stack_a->used_size - 1;
	while (i >= 0)
	{
		if (stack_a->array[i].index != stack_a->min &&
		stack_a->array[i].index <= mid)
			return (-1);
		i--;
	}
	return (0);
}

int 	sorting(t_stack *stack_a)
{
	int		i;

	if (stack_a == NULL)
		return (-1);
	i = stack_a->used_size - 1;
	while (i > 0)
	{
		if (stack_a->array[i].value > stack_a->array[i - 1].value)
			return (1);
		i--;
	}
	return (0);
}

int		duplication(t_stack *stack_a)
{
	int	i;
	int	j;
	int	duplicate;

	if (stack_a == NULL)
		return (-1);
	i = stack_a->used_size - 1;
	j = 0;
	duplicate = 0;
	while (i >= 0)
	{
		j = 0;
		duplicate = 0;
		while (j < stack_a->used_size)
		{
			if (stack_a->array[i].value == stack_a->array[j].value)
				duplicate++;
			j++;
		}
		if (duplicate > 1)
			return (1);
		i--;
	}
	return (0);
}