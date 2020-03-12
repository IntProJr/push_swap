/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:02:52 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		find_min_actions(t_stack *b)
{
	int	j;
	int	min;

	j = b->used_size - 1;
	min = j;
	while (j >= 0)
	{
		if (b->array[min].total_moves > b->array[j].total_moves)
			min = j;
		j--;
	}
	return (min);
}

void	sort_stacks(t_stack *a, t_stack *b, int hold_min, int hold_max)
{
	kick_to_b_except(a, b, hold_min, hold_max);
	count_moves(a, b);
	while (b->used_size > 0)
	{
		count_moves(a, b);
		do_moves(a, b);
	}
	kick_val_to_top(a, a->max);
}

void	push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		hold_min;
	int		hold_max;

	if ((a = create_stack_argv(argc, argv)) == NULL)
		return ;
	if (check_errors(a) == -1 || sorting(a) == 0)
	{
		if (a)
			del_stack(a);
		return ;
	}
	b = create_second_stack(a);
	quick_sort(b->array, 0, b->used_size - 1);
	change_index(a, b);
	hold_min = b->array[a->used_size / 3].index;
	hold_max = b->array[a->used_size - a->used_size / 3].index;
	set_to_zero_stack(b);
	if (a->used_size >= 2 && a->used_size <= 5)
		sort_small(a, b);
	else if (a->used_size > 5)
		sort_stacks(a, b, hold_min, hold_max);
	del_stack(a);
	del_stack(b);
}
