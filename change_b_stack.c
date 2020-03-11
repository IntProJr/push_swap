/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_b_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:32:41 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 19:58:27 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	swap_b(t_stack *b)
{
	if (b->used_size < 2)
		return ;
	swap_top(b);
	ft_printf("sb\n");
}

void	push_stack_b(t_stack *a, t_stack *b)
{
	if (a->used_size == 0)
		return ;
	b->used_size++;
	b->array[b->used_size - 1].index = a->array[a->used_size - 1].index;
	b->array[b->used_size - 1].value = a->array[a->used_size - 1].value;
	a->array[a->used_size - 1].index = -1;
	a->used_size--;
}

void	push_b(t_stack *a, t_stack *b)
{
	if (a->used_size == 0)
		return ;
	b->used_size++;
	b->array[b->used_size - 1].index = a->array[a->used_size - 1].index;
	b->array[b->used_size - 1].value = a->array[a->used_size - 1].value;
	a->array[a->used_size - 1].index = -1;
	a->used_size--;
	ft_printf("pb\n");
}

void	rotate_b(t_stack *b)
{
	rotate_stk(b);
	ft_printf("rb\n");
}

void	rev_rotate_b(t_stack *b)
{
	rev_rotate_stk(b);
	ft_printf("rrb\n");
}