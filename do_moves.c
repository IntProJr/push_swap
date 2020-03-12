/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:38:13 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		find_function(t_num val)
{
	if (val.ra > 0)
		return (1);
	if (val.rb > 0)
		return (2);
	if (val.rra > 0)
		return (3);
	if (val.rrb > 0)
		return (4);
	if (val.rr > 0)
		return (5);
	if (val.rrr > 0)
		return (6);
	else
		return (7);
}

int		do_move(t_stack *stk, int counter, void (*f)(t_stack *))
{
	while (counter > 0)
	{
		(*f)(stk);
		counter--;
	}
	return (0);
}

int		do_m_b(t_stack *a, t_stack *b, int c, void (*f)(t_stack *, t_stack *))
{
	while (c > 0)
	{
		(*f)(a, b);
		c--;
	}
	return (0);
}

void	do_moves(t_stack *a, t_stack *b)
{
	int	min_moves;

	min_moves = find_min_actions(b);
	if (find_function(b->array[min_moves]) == 1)
		b->array[min_moves].ra = do_move(a, b->array[min_moves].ra, rotate_a);
	if (find_function(b->array[min_moves]) == 2)
		b->array[min_moves].rb = do_move(b, b->array[min_moves].rb, rotate_b);
	if (find_function(b->array[min_moves]) == 3)
		b->array[min_moves].rra = do_move(a, b->array[min_moves].rra,
				rev_rotate_a);
	if (find_function(b->array[min_moves]) == 4)
		b->array[min_moves].rrb = do_move(b, b->array[min_moves].rrb,
				rev_rotate_b);
	if (find_function(b->array[min_moves]) == 5)
		b->array[min_moves].rr = do_m_b(a, b, b->array[min_moves].rr,
				rotate_rr);
	if (find_function(b->array[min_moves]) == 6)
		b->array[min_moves].rrr = \
		do_m_b(a, b, b->array[min_moves].rrr, rev_rotate_r);
	if (find_function(b->array[min_moves]) == 7)
		push_a(a, b);
}
