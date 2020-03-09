/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:19:58 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 16:19:58 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		del_stack(t_stack *stack)
{
	if (stack->arr)
	{
		free(stack->arr);
		stack->arr = NULL;
	}
	if (stack)
	{
		free(stack);
		stack = NULL;
	}
}