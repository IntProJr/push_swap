/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stacks_no_output.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:58:51 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	swap_ss_stcks(t_stack *a, t_stack *b)
{
	if (a->used_size < 2 || b->used_size < 2)
		return ;
	swap_top(a);
	swap_top(b);
}

void	rotate_rr_stcks(t_stack *a, t_stack *b)
{
	rotate_stk(a);
	rotate_stk(b);
}

void	rev_rotate_stcks(t_stack *a, t_stack *b)
{
	rev_rotate_stk(a);
	rev_rotate_stk(b);
}
