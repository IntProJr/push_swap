/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_b_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:32:41 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 18:36:05 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void 	push_b(t_stack *a, t_stack *b)
{
	if (a->used_size == 0)
		return ;
	b->used_size++;
	b->arr[b->used_size - 1].index = a->arr[a->used_size - 1].index;
	b->arr[b->used_size - 1].val = a->arr[a->used_size - 1].val;
	a->arr[a->used_size - 1].index = -1;
	a->used_size--;
	ft_printf("pb\n");
}
