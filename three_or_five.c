/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_or_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:20:09 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/04 19:36:03 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** В стек b перекладываем минимальное и следующие минимальное число
** Считаем количество чисел до нужного min, если шагов сделано больше двух,
** то выполняем команду 'rra', если один и более, то команду 'ra'.
*/

void		push_min_to_b(t_stack **a, t_stack **b, t_op *val)
{
	t_stack		*ptr;
	char 		*opt;
	int 		steps;

	opt = "ra";
	steps = 0;
	ptr = *a;
	while (ptr->value != val->min)
	{
		ptr = ptr->next;
		steps++;
	}
	if (steps > 2)
	{
		steps = val->size_a - steps;
		opt = "rra";
	}
	while (steps > 0)
	{
		take_stack_op(a, b, val, opt);
		steps--;
	}
	take_stack_opt
}

/*
** Сортировка трёх или пяти чисел.
** push_min_to_b: два числа min и следующие min переносим в стек b.
** sort_three_digit: сортировка трёх чисел в стеке 'a'
** pb: возьмите первый элемент вверху b и поместите его вверх a.
*/

void		sort_little_count(t_stack **a, t_stack **b, t_op *val,
			int size)
{
	if (size == 5)
	{
		push_min_to_b(a, b, val);
		val->min = val->second_min;
		push_min_to_b(a, b, val);
	}
	sort_three_digit(a, b, val);
	if (size == 5)
	{
		take_stack_op(a, b, val, "pa");
		take_stack_op(a, b, val, "pa");
	}
}