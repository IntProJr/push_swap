/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:02:52 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/04 16:44:31 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"


/*
** переносим значения, кроме min и max в стек б, сортируя его по middle
** pb: первый элемент сверху стека а помещают в верх стека б.
** rb: сдвинуть все элементы стека b на 1. Первый элемент становится последним.
** ra: первый элемент стека a становится последним.
** sa: поменять местами первые 2 элемента в верхней части стека a.
*/

stacic void		creat_stack_b(t_stack **a, t_stack **b,
				t_op *values, int size)
{
	int		digit;
	int		count;

	count = 0;
	while (count < size)
	{
		digit = (*a)->value;
		if (digit != values->max && digit != values->min)
		{
			take_stack_op(a, b, values, "pb");
			count++;
			if (digit >= values->middle)
				take_stack_op(a, b, values, "rb");
		}
		else
			take_stack_op(a, b, values, "ra");
	}
	if ((*a)->value != values->max)
		take_stack_op(a, b, values, "sa");
}

/*
** get_min_max_middle: заполняет структуру min, max и middle значениями
** val->order: отсортирован от мин к макс значению методом быстрой сортировки
** stack_a: не отсортирован, значения идут в заданном через аргументы порядке
** creat_stack_b: переносит все значения, кроме min и max в стек b
*/

int 	push_swap(int *stack_a, int size, t_op *val)
{
	t_stack		*a;
	t_stack		*b;

	b = NULL;
	val->size_a = size;
	val->size_b = 0;
	if (!(stack_a = get_min_max_middle(val, stack_a, size)))
		return(-1);
	if (!(a = stack_as_list(stack_a, val->order, size)))
	{
		free_stack_list(a);
		return (-1);
	}

	if (size == 5 || size == 3)
		sort_little_count(&a, &b, val, size);
	else
	{
		creat_stack_b(&a, &b, val,(size - 2));
		sorting_inserts(&a, &b, val, size);
	}
	free_stack_list(a);
	return (1);
}