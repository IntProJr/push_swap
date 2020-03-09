/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_and_middle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:05:45 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 16:01:38 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Быстрая сортировка: метод сортировки, основанный на принципе обмена.
** В массиве выбирается разрешающий элемент, в данном случае серединный.
** Производятся перестановки элементов, где слева от них находятся элементы,
** меньшие разрешающего, и справа — большие. Массив сортируется по возрастанию.
*/

void		quick_sort(int *stack, int left, int right)
{
	int low;
	int high;
	int median;

	low = right;
	high = left;
	median = stack[(low + high) / 2];
	while (high <= low)
	{
		while (stack[high] < median)
			high++;
		while (stack[low] > median)
			low--;
		if (high <= low)
			ft_swap(stack, high++, low--);
	}
	if (left < low)
		quick_sort(stack, left, low);
	if (right > high)
		quick_sort(stack, high, right);
}

/*
** stack_a: отсортикованный, проверяяем соседние значения на дупликат
*/

static int 	check_duplicates(const int *stack_a, int size)
{
	int 	i;

	i = 0;
	while (i < (size - 1))
	{
		if (stack_a[i] == stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

/*
** quick_sort: метод сортировки, основанный на принципе обмена.
** check_duplicates: ищет одинаковые цифры в отсортированном массиве.
** заполняем структуру min, max и middle значениями из сортированного массива.
** функция возвращает НЕ отсортированный массив
*/

int			*get_min_max_middle(t_op *val, int *stack_a, int size)
{
	int		*ptr;
	int 	i;

	i = 0;
	if (!(ptr = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		ptr[i] = *stack_a;
		i++;
	}
	quick_sort(stack_a, 0, size - 1);
	val->order = stack_a;
	if (check_duplicates(stack_a, size - 1))
	{
		free(stack_a);
		free(ptr);
		ft_printf("Error\n");
		return (NULL);
	}
	val->min = stack_a[0];
	val->second_min = (size == 1) ? stack_a[0] : stack_a[1];
	val->middle = stack_a[size / 2];
	val->max = stack_a[size - 1];
	return (ptr);
}

/*
** Проверка наличия первого аргумента, функция вернёт '0' при отсутствии
** параметров или non-printable characters
*/

int 		check_args(int argc, char *argv[])
{
	int 		i;
	int 		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] > 32 && argv[i][j] < 127)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}