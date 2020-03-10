/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:29:36 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 21:52:52 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = 2;
	mid = 1;
	bottom = 0;
	if ((a->max == a->array[top].index && a->min == a->array[mid].index) ||
		(a->min == a->array[bottom].index && a->max == a->array[mid].index) ||
		(a->min == a->array[top].index && a->max == a->array[bottom].index))
		swap_a(a);
	if (a->max == a->array[mid].index && a->min == a->array[top].index)
		rotate_a(a);
	if (a->min == a->array[mid].index && a->max == a->array[bottom].index)
		rev_rotate_a(a);
}

void	kick_from_b(t_stack *a, t_stack *b)
{
	while (b->used_size > 0)
	{
		count_moves(a, b);
		do_moves(a, b);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	i;

	i = a->used_size - 1;
	while (a->used_size > 3)
	{
		if (a->array[i].index != a->min && a->array[i].index != a->max)
		{
			push_b(a, b);
			i = a->used_size - 1;
		}
		else
			rotate_a(a);
	}
	sort_three(a);
	if (b->used_size > 0)
	{
		kick_from_b(a, b);
		kick_val_to_top(a, a->max);
	}
}
