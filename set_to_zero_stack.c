/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_to_zero_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:27:05 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/10 19:59:02 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		set_to_zero_stack(t_stack *stack_b)
{
	int		i;
	i = stack_b->used_size - 1;
	while (i >= 0)
	{
		stack_b->array[i].value = 0;
		stack_b->array[i].index = -1;
		i--;
	}
	stack_b->used_size = 0;
}
