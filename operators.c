/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:48:47 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/07 15:11:21 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** rra: сдвинуть вниз все элементы a на 1. Последний элемент становится первым.
** rrb: сдвинуть все элементы b на 1. Последний элемент становится первым.
*/

void	option_rr(t_stack **stack)
{
	t_stack		*new_first;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	new_first = (*stack)->prev;
	new_first->next = *stack;
	(new_first->prev)->next = NULL;
	(*stack)->prev = new_first;
	*stack = new_first;

}

/*
** Первый элемент стека становится последним.
*/

void	option_r(t_stack **stack)
{
	t_stack		*new_first;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	new_first = (*stack)->next;
	(*stack)->next = NULL;
	((*stack)->prev)->next = *stack;
	*stack = new_first;
}

void	run_together(t_stack **stack, t_stack **stack_b,
		void (f)(t_stack **))
{
	f(stack_a);
	f(stack_b);

}

/*
**pa: первый элемент в верхней части b помещают в верх стека a.
**pb: первый элемент в верхней части a помещают в верх стека b.
*/

void	option_p(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*ptr;

	if (!(stack_a))
		return ;
	ptr = (*stack_a)->next;
	if (ptr)
		ptr->prev = (*stack_a)->prev;
	(*stack_a)->next = (*stack_b != NULL) ? *stack_b : NULL;
	(*stack_b)->prev = (*stack_b != NULL) ? (*stack_b)->prev : NULL;
	(*stack_b != NULL) ? (*stack_b)->prev = (*stack_a) : NULL;
	*stack_b = *stack_a;
	if ((*stack_b)->next && ((*stack_b)->next)->next == NULL)
		(*stack_b)->prev = (*stack_b)->next;
	*stack_a = ptr;
}

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