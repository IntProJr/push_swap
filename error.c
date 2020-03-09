/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:09:32 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 16:09:32 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int 	check_errors(t_stack *a)
{
	if (is_it_dup(a) == 1 || (a != NULL && a->arr == NULL))
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (a == NULL || a->used_size == 1)
		return (-1);
	return (0);
}
