/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stack_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:40:18 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 18:40:18 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void 	rotate_stk(t_stack *stk)
{
	t_num	tmp;
	int 	i;

	i = stk->used_size - 1;
	tmp = stk->arr[i];
	while (i > 0)
	{
		stk->arr[i].index = stk->arr[i - 1].index;
		stk->arr[i].val = stk->arr[i - 1].val;
		i--;
	}
	stk->arr[i].val = tmp.val;
	stk->arr[i].index = tmp.index;
}