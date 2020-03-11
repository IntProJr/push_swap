/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:17:39 by fmasha-h          #+#    #+#             */
/*   Updated: 2020/03/11 19:39:02 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = a->size - 1;
	j = a->size - 1;
	ft_printf("-----------------------\n");
	while (i >= 0 && j >= 0)
	{
		if (IS_EMPTY(a->array[i].index) == 0)
			ft_printf("%d %-17d", a->array[i].index, a->array[i].value);
		if (IS_EMPTY(a->array[i].index) == -1)
			ft_printf("%-17c", '-');
		if (IS_EMPTY(b->array[j].index) == 0)
			ft_printf("%d %d", b->array[i].index, b->array[i].value);
		if (IS_EMPTY(b->array[j].index) == -1)
			ft_printf("%3c", '-');
		ft_printf("\n");
		j--;
		i--;
	}
	ft_printf("-----------------------\n");
	ft_printf("%c %17c\n", a->name, b->name);
	ft_printf("-----------------------\n");
}
