/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:29:36 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 18:36:05 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		sort_three(t_stack *a)
{
	int 	top;
	int 	mid;
	int 	bottom;

	top = 2;
	mid = 1;
	bottom = 0;
	if ((a->max == a->arr[top].index && a->min == a->arr[mid].index) ||
			(a->min == a->arr[bottom].index && a->max == a->arr[mid].index) ||
			(a->min == a->arr[top].index && a->max == a->arr[bottom].index))
		swap_a(a);
}

void		kick_from_b(t_stack *a, t_stack *b)
{
	while (b->used_size > 0)
	{
		count_moves(a, b);
		do_moves(a, b);
	}
}

void		sort_small(t_stack *a, t_stack *b)
{
	int 	i;

	i = a->used_size - 1;
	while (a->used_size > 3)
	{
		if (a->arr[i].index != a->min && a->arr[i].index != a->max)
		{
			push_b(a, b);
			i = a->used_size - 1;
		}
		else
			rotate_a(a);
	}
	sort_three(a);
	if (b->used > 0)
	{
		kick_from_b(a, b);
		kick_val_to_top(a, a->max);
	}
}
