/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:14:36 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/04 17:49:56 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		ft_v(t_stack *a, t_stack *b, t_op *val,char *opt)
{
	int 	count_a;
	int 	count_b;

	count_a = 0;
	count_b = 0;
	val->size_a = (int)(ft_lstcount(a));
	val->size_b = (int)(ft_lstcount((b));
	ft_printf("    Command   -   %s", opt);
	ft_printf("%s", "   stack a :     stack b :   \n");
	ft_printf(" _______________     _______________  \n");
	while (count_a < val->size_a || count_b < val->size_b)
	{
		(count_a++ < val->size_a) ? ft_printf(("|% 11d |", a->value))
					: ft_printf(" |             ");
		a = (count_a <= val->size_a) ? (a->next) : 0;
		(count_b++ < val->size_b) ? ft_printf("|% 11d | \n", b->value)
					: ft_printf(" |             ");
		b = (count_b <= val->size_b) ? (b->next) : 0;
		ft_printf("|_____________|  |___________|");
	}
	ft_printf("\n");
}
