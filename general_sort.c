/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:33:26 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 16:01:38 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Перемещает значения внутри стека 'a' до конечной сортировки от min к max
** pos: считает количество элементов, которые нужно переместить
*/

static void		push_min_to_start(t_stack **a,
									 t_stack **b, t_op *val, int size)
{
	void		(*f)(t_stack**);
	t_stack		*ptr;
	int			pos;

	ptr = *a;
	pos = 0;
	if (!ptr)
		return ;
	while (ptr->value != val->min)
	{
		ptr = ptr->next;
		pos++;
	}
	f = (pos <= (size / 2)) ? option_r : option_rr;
	while ((*a)->value != val->min)
		(f == option_r) ? take_stack_op(a, b, val, "ra")
						: take_stack_op(a, b, val, "rra");
}

static int 		find_place_for_insert(int *ptr_a_pos, int value,
				const int *stack, int size)
{
	int		i;

	i = 0;
	while (!(value > stack[i] && value < stack[i + 1])
		&& i < (size - 1))
		i++;
	(!(value > stack[i] && value < stack[i + 1])) ? ((*ptr_a_pos) = 0)
			: ((*ptr_a_pos) = i + 1);
	return (i);
}

/*
** заполняет структуру actions, чтобы выбрать дальнейший метод сортировки
** move_a == 1: выполняется действие ra если выполняются условия
** move_b == 1: выполняется действие rb если выполняются условия
** ptr_a_pos + ptr_b_pos == 1: применяется сортировка в одном из стеков
*/

static void		check_relevance_current(t_actions *acts,
										   int *stack_a, int value, int position)
{
	int			move_a;
	int			move_b;
	int			ptr_a_pos;
	int			ptr_b_pos;
	int			i;

	i = find_place_for_insert(&ptr_a_pos, value,
							  stack_a, acts->val->size_a);
	move_a = (i <= acts->val->size_a / 2) ? 1 : -1;
	ptr_a_pos = (i <= acts->val->size_a / 2)
				? ptr_a_pos : acts->val->size_a - (i + 1);
	move_b = (position <= acts->val->size_b / 2) ? 1 : -1;
	ptr_b_pos = (position <= acts->val->size_b / 2)
				? position : acts->val->size_b - position;
	if ((ptr_a_pos + ptr_b_pos) < (acts->a_pos + acts->b_pos))
	{
		acts->a_pos = ptr_a_pos;
		acts->b_pos = ptr_b_pos;
		acts->move_a = move_a;
		acts->move_b = move_b;
	}
}

/*
** перемещаем значения из структуры a во временный массив intов, зануляем.
** check_relevance_current: возвращает заполненную структуру actions.
*/

static void		count_actions(t_stack *a, t_stack *b,
					t_op *val, t_actions *acts)
{
	int		stack_a[500];
	int		position;
	int		i;

	i = 0;
	ft_bzero(stack_a, sizeof(int) * 500);
	position = 0;
	acts->a_pos = val->size_a + 1;
	acts->b_pos = val->size_b + 1;
	while (a != NULL)
	{
		stack_a[i++] = a->value;
		a = a->next;
	}
	while (val->size_b > 0 && b)
	{
		check_relevance_current(acts, stack_a, b->value, position++);
		b = b->next;
		if (acts->a_pos + acts->b_pos == 1)
			break ;
	}
}

/*
** count_actions: возвращает возможные дейтсвия в стеке а или стеке б,
** если перемещения внутри стеков не нужны, то выполняется действие pa.
** pa: возьмём первый элемент вверху b и поместим его вверх a.
*/

void			sorting_inserts(t_stack **a, t_stack **b,
								t_op *val, int size)
{
	t_actions	acts;
	int			scrolling;

	acts.val = val;
	while ((*b) != NULL)
	{
		count_actions(*a, *b, val, &acts);
		scrolling = acts.a_pos;
		while (scrolling > 0)
		{
			(acts.move_a == 1) ? take_stack_op(a, b, val, "ra")
							   : take_stack_op(a, b, val, "rra");
			scrolling--;
		}
		scrolling = acts.b_pos;
		while (scrolling > 0)
		{
			(acts.move_b == 1) ? take_stack_op(a, b, val, "rb")
							   : take_stack_op(a, b, val, "rrb");
			scrolling--;
		}
		take_stack_op(a, b, val, "pa");
	}
	push_min_to_start(a, b, val, size);
}