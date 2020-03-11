/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:12:19 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/11 19:35:56 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		partition(t_num *array, int low, int high)
{
	int pivot;
	int i;
	int	j;

	i = (low - 1);
	pivot = array[high].value;
	j = low;
	while (j <= high)
	{
		if (array[j].value > pivot)
		{
			i++;
			swap(&array[i].value, &array[j].value);
		}
		j++;
	}
	swap(&array[i + 1].value, &array[high].value);
	return (i + 1);
}

void	quick_sort(t_num *array, int low, int high)
{
	int	pivot;

 	if (low < high)
	{
		pivot = partition(array, low, high);
		quick_sort(array, low, pivot - 1);
		quick_sort(array, pivot + 1, high);
	}
}
