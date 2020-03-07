/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:33:26 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/07 16:09:58 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void 		sorting_inserts(t_stack **a, t_stack **b,
					t_op *val, int size)
{
	t_actions		acts;
	int				scrolling;

	acts.val = val;
	while ((*b) != NULL)
	{
		count_actions(*a, *b, val, &acts);
		scrolling = acts.a_pos;
		while (scrolling > 0)
		{
			(acts.move_a == 1) ? take_stack_op(a, b, val, "ra")
				:take_stack_op(a, b, val, "rra");
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