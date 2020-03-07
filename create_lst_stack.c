/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:15:00 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/04 16:19:03 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Считает количество элементов структуры
*/

size_t			ft_lstcount(t_stack *lst)
{
	size_t		i;

	i = 0;
	while (lst != NUll)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
** Удаляем структуру
*/

void			free_stack_list(t_stack *stack)
{
	t_stack		*ptr;

	if (!stack)
		return ;
	while (stack != NULL)
	{
		ptr = stack->next;
		free(stack);
		stack = ptr;
	}
}

/*
** Добавляем новый элемент в структуру
*/

void			add_to_stack(t_stack ** alst, t_stack *new)
{
	t_stack		*ptr;

	ptr = *alst;
	if (!ptr)
	{
		*alst = new;
		(*alst)->prev = NULL;
	}
	else
	{
		if (ptr->prev != NULL)
			ptr = ptr->prev;
		ptr->next = new;
		new->next = NULL;
		new->prev = ptr;
		(*alst)->prev = new;
	}
}
/*
** Создаём двунаправленную структуру: value: цифра, pos: место при сортировке
** stack_a не отсортирован, order отсортирован
** Функция возвращает готовый список из заданных цифр с позициями для сортировки
*/

t_stack			*stack_as_list(int *stack_a, int *order, int size)
{
	t_stack		*lst_stack;
	t_stack		*cur_value;
	int 		i;
	int 		pos;

	i = 0;
	lst_stack = NULL;
	while (i < size)
	{
		if (!(cur_value = (t_stack *)malloc((sizeof(t_stack)))))
			return (NULL);
		pos = 0;
		cur_value->value = stack_a[i];
		cur_value->next = NULL;
		while (cur_value->value != order[pos])
			pos++;
		cur_value->pos = pos + 1;
		add_to_stack(&lst_stack, cur_value);
		i++;
	}
	free(order);
	free(stack_a);
	return (lst_stack);
}
