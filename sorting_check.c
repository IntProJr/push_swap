/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:40:28 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		range_sort(t_stack *a, int bottom, int top)
{
	int	i;

	if (a == NULL)
		return (-1);
	i = a->used_size - 1;
	while (i >= 0)
	{
		if (a->array[i].index != a->min && a->array[i].index != a->max)
		{
			if (a->array[i].index > bottom && a->array[i].index < top)
				return (-1);
		}
		i--;
	}
	return (0);
}

int		more_sort(t_stack *a, int med)
{
	int	i;

	if (a == NULL)
		return (-1);
	i = a->used_size - 1;
	while (i >= 0)
	{
		if (a->array[i].index != a->max && a->array[i].index >= med)
			return (-1);
		i--;
	}
	return (0);
}

int		less_sort(t_stack *a, int med)
{
	int	i;

	if (a == NULL)
		return (-1);
	i = a->used_size - 1;
	while (i >= 0)
	{
		if (a->array[i].index != a->min && a->array[i].index <= med)
			return (-1);
		i--;
	}
	return (0);
}

int		sorting(t_stack *a)
{
	int	i;

	if (a == NULL)
		return (-1);
	i = a->used_size - 1;
	while (i > 0)
	{
		if (a->array[i].value > a->array[i - 1].value)
			return (1);
		i--;
	}
	return (0);
}

int		duplication(t_stack *a)
{
	int	i;
	int	j;
	int	f;

	if (a == NULL)
		return (-1);
	i = a->used_size - 1;
	j = 0;
	f = 0;
	while (i >= 0)
	{
		j = 0;
		f = 0;
		while (j < a->used_size)
		{
			if (a->array[i].value == a->array[j].value)
				f++;
			j++;
		}
		if (f > 1)
			return (1);
		i--;
	}
	return (0);
}
