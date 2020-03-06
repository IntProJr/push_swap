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
** Сравниваются между собой три значения: текущее, следующее и предыдущее
** Запомнинаем минимальное и среднее значение среди них.
*/

static void			define_mid_and_min(t_stack **a, int *middle, int *min)
{
	if (((*a)->next)->value > (*a)->value
		&& (*a)->value < ((*a)->prev)->value)
	{
		(*min) = (*a)->value;
		(*middle) = (((*a)->next)->value > ((*a)->prev)->value)
					? ((*a)->prev)->value : ((*a)->next)->value;
	}
	else if ((*a)->value > ((*a)->next)->value
			 && ((*a)->next)->value < ((*a)->prev)->value)
	{
		(*min) = ((*a)->next)->value;
		(*middle) = ((*a)->value > ((*a)->prev)->value)
					? ((*a)->prev)->value : (*a)->value;
	}
	else if (((*a)->prev)->value < ((*a)->next)->value
			 && ((*a)->prev)->value < (*a)->value)
	{
		(*min) = ((*a)->prev)->value;
		(*middle) = ((*a)->value > ((*a)->next)->value)
					? ((*a)->next)->value : (*a)->value;
	}
}

/*
** сортируем три числа стека 'а' между собой, внизу max число, вверху min.
** define_mid_and_min: возвращает min и middle значение из трёх цифр стека а
** sa: поменяйте местами первые 2 элемента в верхней части стека a.
** ra: первый элемент становиться последним, rra: последний элемент - первым.
*/

static void			sort_three_digit(t_stack **a, t_stack **b, t_op *values)
{
	int				min;
	int				middle;

	define_mid_and_min(a, &middle, &min);
	if ((*a)->value > ((*a)->next)->value && ((*a)->prev)->value == middle)
		take_stack_op(a, b, values, "ra");
	else if ((*a)->value < ((*a)->next)->value
			 && ((*a)->prev)->value == middle)
	{
		take_stack_op(a, b, values, "rra");
		take_stack_op(a, b, values, "sa");
	}
	else if ((*a)->value < ((*a)->next)->value
			 && ((*a)->prev)->value == min)
		take_stack_op(a, b, values, "rra");
	else if ((*a)->value > ((*a)->next)->value
			 && ((*a)->prev)->value == min)
	{
		take_stack_op(a, b, values, "sa");
		take_stack_op(a, b, values, "rra");
	}
	else if ((*a)->value > ((*a)->next)->value
			 && ((*a)->prev)->value != min
			 && ((*a)->prev)->value != middle)
		take_stack_op(a, b, values, "sa");
}

/*
** В стек b перекладываем минимальное и следующие минимальное число
** Считаем количество чисел до нужного min, если шагов сделано больше двух,
** то выполняем команду 'rra', если один и более, то команду 'ra'.
*/

void				push_min_to_b(t_stack **a, t_stack **b, t_op *val)
{
	t_stack			*ptr;
	char			*opt;
	int				steps;

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
	take_stack_op(a, b, val, "pb");
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