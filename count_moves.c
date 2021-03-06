/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:48:03 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		find_max_between_mins(t_stack *a, t_num val)
{
	t_num		max_min;
	t_num		min;
	int			i;

	i = 0;
	max_min.index = -1;
	min.index = -1;
	while (i < a->used_size)
	{
		if (a->array[i].index < val.index)
		{
			min = a->array[i];
			if (max_min.index < min.index)
				max_min = min;
		}
		i++;
	}
	i = 0;
	while (a->array[i].index != max_min.index)
		i++;
	return (i);
}

t_num	count_stack_a_moves(t_stack *a, t_num val)
{
	int j;
	int half;

	j = find_max_between_mins(a, val);
	half = a->used_size / 2;
	if (j >= half)
	{
		if (j != a->used_size - 1)
			val.ra = a->used_size - j - 1;
		else
			val.ra = 0;
	}
	else if (j < half)
	{
		if (j == 0 || j == -1)
			val.rra = 1;
		else
			val.rra = j + 1;
	}
	return (val);
}

t_num	count_moves_for_num(t_stack *a, t_stack *b, t_num val, int i)
{
	int half;
	int j;

	set_to_zero_moves(&val);
	j = a->used_size - 1;
	half = b->used_size / 2;
	if (i < half)
		val.rrb = i + 1;
	else if (i >= half)
		val.rb = b->used_size - 1 - i;
	val = count_stack_a_moves(a, val);
	val = unit_moves(val);
	return (val);
}

void	count_moves(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_b->used_size - 1;
	while (i >= 0)
	{
		stack_b->array[i] = count_moves_for_num(stack_a,
				stack_b, stack_b->array[i], i);
		i--;
	}
}
