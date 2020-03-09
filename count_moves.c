/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:48:03 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 18:48:03 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_num 	count_moves_for_num(t_stack *a, t_stack *b, t_num val, int i)
{
	int half;
	int j;

	set_to_zero_moves(&val);
	j = a->used_size - 1;
	half = b->used_size / 2;
	if (i < half)
		val.rb = b->used_size - 1 - i;
	val = count_stack_a_moves(a, val);
	val = unit_moves(val);
	return (val);
}

void count_moves(t_stack *a, t_stack *b)
{
	int 	i;

	i = b->used->size - 1;
	while (i >= 0)
	{
		b->arr[i] = count_moves_for_num(a, b, b->arr[i], i);
		i--;
	}
}