/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:09:32 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		check_errors(t_stack *stack_a)
{
	if (duplication(stack_a) == 1 || (stack_a != NULL &&
	stack_a->array == NULL))
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (stack_a == NULL || stack_a->used_size == 1)
		return (-1);
	return (0);
}
