/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_to_zero_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:27:05 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 18:27:05 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		set_to_zero_stack(t_stack *b)
{
	int		i;
	i = b->used_size - 1;
	while (i >= 0)
	{
		b->arr[i].val = 0;
		b->arr[i].index = -1;
		i--;
	}
	b->used_size = 0;
}
