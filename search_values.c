/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:50:56 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		find_over_value(t_stack *stack_a)
{
	int		i;
	int		mean;

	i = 0;
	mean = 0;
	while (i < stack_a->used_size)
	{
		mean += stack_a->array[i].index;
		i++;
	}
	mean /= stack_a->used_size;
	return (mean);
}
