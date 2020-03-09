/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_a_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:37:08 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 19:58:27 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	push_a(t_stack *a, t_stack *b)
{
	if (b->used_size == 0)
		return ;
	a->used_size++;
	a->arr[a->used_size - 1].index = b->arr[b->used_size - 1].index;
	a->arr[a->used_size - 1].val = b->arr[b->used_size - 1].val;
	b->arr[b->used_size - 1].index = -1;
	b->used_size--;
	ft_printf("pa\n");
}

void 	rotate_a(t_stack *a)
{
	rotate_stk(a);
	ft_printf("ra\n");
}
