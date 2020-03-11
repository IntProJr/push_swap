/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 21:53:30 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/11 19:54:07 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	kick_less_values(t_stack *a, t_stack *b, int value)
{
	int	i;

	i = a->used_size - 1;
	while (less_sort(a, value) == -1)
	{
		i = a->used_size - 1;
		if (a->array[i].index != a->min && a->array[i].index != a->max &&
			a->array[i].index <= value)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

void	kick_more_values(t_stack *a, t_stack *b, int value)
{
	int	i;

	i = a->used_size - 1;
	while (more_sort(a, value) == -1)
	{
		i = a->used_size - 1;
		if (a->array[i].index != a->min && a->array[i].index != a->max &&
			a->array[i].index >= value)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

void	kick_values_in_range(t_stack *a, t_stack *b, int bottom, int top)
{
	int	i;

	i = a->used_size - 1;
	while (range_sort(a, bottom, top) == -1)
	{
		i = a->used_size - 1;
		if (a->array[i].index != a->min && a->array[i].index != a->max &&
			a->array[i].index > bottom && a->array[i].index < top)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

void	kick_to_b_except(t_stack *a, t_stack *b, int h_min, int h_max)
{
	ft_printf("%d %d\n", h_max, h_min);
	kick_more_values(a, b, h_max);
	print_stack(a, b);
	kick_values_in_range(a, b, h_min, h_max);
	print_stack(a, b);
	kick_less_values(a, b, h_min);
	print_stack(a, b);
}

void	kick_val_to_top(t_stack *a, int val)
{
	int	i;

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
		while (a->array[a->used_size - 1].index != val)
			rotate_a(a);
	}
}
