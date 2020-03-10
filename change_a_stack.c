/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_a_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:37:08 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 21:19:47 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	swap_a(t_stack *a)
{
	if (a->used_size < 2)
		return ;
	swap_top(a);
	ft_printf("sa\n");
}

void	push_a(t_stack *a, t_stack *b)
{
	if (b->used_size == 0)
		return ;
	a->used_size++;
	a->array[a->used_size - 1].index = b->array[b->used_size - 1].index;
	a->array[a->used_size - 1].value = b->array[b->used_size - 1].value;
	b->array[b->used_size - 1].index = -1;
	b->used_size--;
	ft_printf("pa\n");
}

void 	rotate_a(t_stack *a)
{
	rotate_stk(a);
	ft_printf("ra\n");
}

void	rev_rotate_a(t_stack *a)
{
	rev_rotate_stk(a);
	ft_printf("rra\n");
}