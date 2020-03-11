/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_both_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:19:50 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/11 19:10:02 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	change_index(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;

	i = stack_a->used_size - 1;
	j = stack_b->used_size - 1;
	while (i >= 0)
	{
		j = stack_b->used_size - 1;
		while (j >= 0)
		{
			if (stack_a->array[i].value == stack_b->array[j].value)
				stack_a->array[i].index = stack_b->array[j].index;
			j--;
		}
		i--;
	}
}

void	swap_ss(t_stack *a, t_stack *b)
{
	if (a->used_size < 2 || b->used_size < 2)
		return ;
	swap_top(a);
	swap_top(b);
	ft_printf("ss\n");
}

void	rotate_rr(t_stack *a, t_stack *b)
{
	rotate_stk(a);
	rotate_stk(b);
	ft_printf("rr\n");
}

void	rev_rotate_r(t_stack *a, t_stack *b)
{
	rev_rotate_stk(a);
	rev_rotate_stk(b);
	ft_printf("rrr\n");
}
