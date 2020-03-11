/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 21:53:30 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/11 13:45:16 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	kick_less_values(t_stack *stack_a, t_stack *stack_b, int value)
{
	int 	i;

	i = stack_a->used_size - 1;
	while (less_sort(stack_a, value) == -1)
	{
		i = stack_a->used_size - 1;
		if (stack_a->array[i].index != stack_a->min &&
		stack_a->array[i].index != stack_a->max &&
		stack_a->array[i].index <= value)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
}



void	kick_more_values(t_stack *stack_a, t_stack *stack_b, int value)
{
	int i;

	i = stack_a->used_size - 1;
	while (more_sort(stack_a, value) == -1)
	{
		i = stack_a->used_size - 1;
		if (stack_a->array[i].index != stack_a->min &&
		stack_a->array[i].index != stack_a->max &&
		stack_a->array[i].index >= value)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
}

void	kick_values_in_range(t_stack *stack_a, t_stack *stack_b,
		int bottom, int top)
{
	int		i;

	i = stack_a->used_size - 1;
	while(range_sort(stack_a, bottom, top) == -1)
	{
		i = stack_a->used_size - 1;
		if (stack_a->array[i].index != stack_a->min &&
		stack_a->array[i].index != stack_a->max &&
		stack_a->array[i].index > bottom && stack_a->array[i].index < top)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
}

void	kick_to_b_except(t_stack *stack_a, t_stack *stack_b,
		int hold_min, int hold_max)
{
	int 	i;
	int		over_value;

	over_value = find_over_value(stack_a);
	i = stack_a->used_size - 1;
	kick_more_values(stack_a, stack_b, hold_max);
	kick_values_in_range(stack_a, stack_b, hold_min, hold_max);
	kick_less_values(stack_a, stack_b, hold_min);


}

void 	kick_val_to_top(t_stack *a, int val)
{
	int		i;

	i = 0;
	while (i < a->used_size && a->array[i].index != val)
		i++;
	if (i < a->used_size / 2)
	{
		while (a->array[a->used_size - 1].index != val)
			rev_rotate_a(a);
	}
	else
	{
		while (a->array[a->used_size - 1]. index != val)
			rotate_a(a);
	}
}