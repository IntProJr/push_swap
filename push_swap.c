/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:02:52 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/10 18:58:37 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int 	find_min_actions(t_stack *b)
{
	int	j;
	int min;

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

void	sort_stacks(t_stack *stack_a, t_stack *stack_b, int hold_min, int hold_max)
{
	kick_to_b_except(stack_a, stack_b, hold_min, hold_max);
	count_moves(stack_a, stack_b);
}

void	push_swap(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int hold_min;
	int hold_max;

	if ((stack_a = create_stack_argv(argc, argv)) == NULL)
		return;
	if (check_errors(stack_a) == -1 || sorting(stack_a) == 0)
	{
		if (stack_a)
			del_stack(stack_a);
		return;
	}
	stack_b = create_second_stack(stack_a);
	quick_sort(stack_b->array, 0, stack_b->used_size - 1);
	change_index(stack_a, stack_b);
	hold_min = stack_b->array[stack_a->used_size / 3].index;
	hold_max = stack_b->array[stack_a->used_size - stack_a->used_size / 3].index;
	set_to_zero_stack(stack_b);
	if (stack_a->used_size >= 2 && stack_a->used_size <= 5)
		sort_small(stack_a, stack_b);
	else if (stack_a->used_size > 5)
		sort_stacks(stack_a, stack_b, hold_min, hold_max);
	del_stack(stack_a);
	del_stack(stack_b);
}