/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 21:53:30 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 22:00:13 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void 	kick_val_to_top(t_stack *a, int val)
{
	int		i;

	i = 0;
	while (i < a->used_size && a->arr[i].index != val)
		i++;
	if (i < a->used_size / 2)
	{
		while (a->arr[a->used_size - 1].index != val)
			rev_rotate_a(a);
	}
	else
	{
		while (a->arr[a->used_size - 1]. index != val)
			rotate_a(a);
	}
}