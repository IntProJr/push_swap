/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:02:52 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 18:09:12 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int hold_min;
	int hold_max;

	if ((a = create_argv_stack(argc, argv)) == NULL)
		return;
	if (check_errors(a) == -1 || is_it_sort(a) == 0)
	{
		if (a)
			del_stack(a);
		return;
	}
	b = create_second_stack(a);
	quick_sort(b->arr, 0, b->used_size - 1);
	change_index(a, b);
	hold_min = b->arr[a->used_size / 3].index;
	hold_max = b->arr[a->used_size - a->used_size / 3].index;
	set_to_zero_stack(b);
	if (a->used_size >= 2 && a->used_size <= 5)
		sort_small(a, b);
}