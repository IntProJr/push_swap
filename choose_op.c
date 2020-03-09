/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:40:36 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 18:00:38 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** ra | rb: первый элемент стека становится последним.
** pa | pb: первый элемент в верхней части a (b) помещают в верх стека b (a)
** sa | sb: поменяйте местами первые 2 элемента в верхней части стека a (b)
** rra| rrb: сдвинуть вниз все элементы. Последний элемент становится первым.
** ss | rr | rrr: применить одновременно к обоим стекам
*/

void	choose_op(t_stack **a, t_stack **b, char *op)
{
	if (ft_strcmp("sa", op) == 0)
		option_s(a);
	else if (ft_strcmp("sb", op) == 0)
		option_s(b);
	else if (ft_strcmp("ss", op) == 0)
		run_together(a, b, option_s);
	else if (ft_strcmp("pa", op) == 0)
		option_p(b, a);
	else if (ft_strcmp("ra", op) == 0)
		option_r(a);
	else if (ft_strcmp("rb", op) == 0)
		option_r(b);
	else if (ft_strcmp("rr", op) == 0)
		run_together(a, b, option_r);
	else if (ft_strcmp("rra", op) == 0)
		option_rr(a);
	else if (ft_strcmp("rrb", op) == 0)
		option_rr(b);
	else if (ft_strcmp("rrr", op) == 0)
		run_together(a, b, option_rr);
	else
		exit(ft_printf("Error with choose operations"));

}

/*
** size_b/size_a: изменяем в зависимости от выбора опции
** после применения нужного типа сортировки применяем визуализацию
*/

void 	take_stack_op(t_stack **a, t_stack **b, t_op *val, char *opt)
{
	if (opt[0] == 'p')
	{
		if (opt[1] == 'a')
		{
			val->size_b--;
			val->size_a++;
		}
		else if (opt[1] == 'b')
		{
			val->size_b++;
			val->size_a--;
		}
	}
	choose_op(a, b, opt);
	if (val->v_flag == 1)
		ft_v(*a, *b, val, opt);
	else
		ft_printf("%s\n", opt);
}
