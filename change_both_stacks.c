/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_both_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:19:50 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 20:16:37 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		change_index(t_stack *a, t_stack *b)
{
	int 	i;
	int 	j;

	i = a->used_size - 1;
	j = b->used_size - 1;
	while (i >= 0)
	{
		j = b->used_size - 1;
		while (j >= 0)
		{
			if (a->arr[i].val == b->arr[j].val)
				a->arr[i].index = b->arr[j].index;
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
