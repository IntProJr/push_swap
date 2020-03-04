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
//	if (val->v_flag == 2)
//		ft_vz(a, b, val, "");
	if (size == 5 || size == 3)
		sort_little_count(&a, &b, val, size);
	else
	{
		creat_st
	}



}