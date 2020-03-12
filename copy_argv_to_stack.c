/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_argv_to_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:51:10 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		value_validation(long value, char *line)
{
	if ((value = ft_atoi(line)) > 2147483647 || value <= -2147483648 ||
		(value > 0 && line[0] == '-') ||
		(value <= 0 && line[0] != '-' && line[0] != '0'))
		return (-1);
	return (0);
}

int		get_len_array(char **array)
{
	int		len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

int		check_num(char **array, int len, int value, t_stack *stack)
{
	if (!(check_valid_number(array[len], (int)value)))
	{
		return (1);
	}
	if (value == 0 && array[len][0] != '0')
	{
		ft_printf("Error\n");
		return (1);
	}
	if (value_validation(value, array[len]) == -1)
	{
		free(stack->array);
		return (1);
	}
	return (0);
}

t_num	*copy_argv_to_stack(char **array, t_stack *stack)
{
	t_num	number;
	long	value;
	int		i;
	int		len;

	i = 0;
	len = get_len_array(array);
	stack->size = len;
	stack->array = (t_num *)malloc(sizeof(t_num) * stack->size);
	while (--len >= 0)
	{
		num_initialization(&number);
		value = ft_atoi(array[len]);
		if (check_num(array, len, value, stack) == 1)
		{
			free(stack->array);
			return (NULL);
		}
		number.value = (int)value;
		number.index = i + 1;
		stack->array[i++] = number;
	}
	stack->used_size = i;
	return (stack->array);
}
