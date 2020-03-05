/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:48:47 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/05 15:59:40 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** sa: поменяйте местами первые 2 элемента в верхней части стека а
** sb: поменяйте местами первые 2 элемента в верхней части стека b
*/

void 	option_s(t_stack **stack)
{
	t_stack		*ptr;

	if (!(*stack && (*stack)->next))
		return ;
	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	ptr->next = *stack;
	ptr->prev = ((*stack)->next != NULL) ? (*stack)->prev : *stack;
	if ((*stack)->next != NULL)
		((*stack)->next)->prev = *stack;
	(*stack)->prev = ptr;
	*stack = ptr;
}