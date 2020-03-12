/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stack_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:40:18 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	swap_nums(t_num *a, t_num *b)
{
	t_num	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_top(t_stack *stk)
{
	if (stk->used_size < 2)
		return ;
	swap_nums(&(stk->array[stk->used_size - 1]), \
		&(stk->array[stk->used_size - 2]));
}

void	rotate_stk(t_stack *stk)
{
	t_num	tmp;
	int		i;

	if (stk->used_size < 1)
		return ;
	i = stk->used_size - 1;
	tmp = stk->array[i];
	while (i > 0)
	{
		stk->array[i].index = stk->array[i - 1].index;
		stk->array[i].value = stk->array[i - 1].value;
		i--;
	}
	stk->array[i].value = tmp.value;
	stk->array[i].index = tmp.index;
}

void	rev_rotate_stk(t_stack *stk)
{
	t_num	tmp;
	int		i;

	i = 0;
	tmp.index = stk->array[i].index;
	tmp.value = stk->array[i].value;
	while (i < stk->used_size - 1)
	{
		stk->array[i].index = stk->array[i + 1].index;
		stk->array[i].value = stk->array[i + 1].value;
		i++;
	}
	stk->array[i].value = tmp.value;
	stk->array[i].index = tmp.index;
}
