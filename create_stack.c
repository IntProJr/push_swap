/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:15:00 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/10 18:29:11 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		set_to_zero_moves(t_num *n)
{
	n->ra = 0;
	n->rb = 0;
	n->rr = 0;
	n->rra = 0;
	n->rrb = 0;
	n->rrr = 0;
	n->swap = 0;
	n->total_moves = 0;
}

void		num_initialization(t_num *n)
{
	n->value = -1;
	n->index = -1;
	n->ra = 0;
	n->rb = 0;
	n->rr = 0;
	n->rra = 0;
	n->rrb = 0;
	n->rrr = 0;
	n->swap = 0;
	n->total_moves = 0;
}

void		del_arrays(char **arr, t_stack *stack_a)
{
	del_matrix(arr);
	free(arr);
	free(stack_a);
	ft_printf("Error\n");
}

t_stack		*create_stack_argv(int argc, char *argv[])
{
	t_stack	*stack_a;
	char	**array;

	array = NULL;
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (argc == 2)
	{
		array = ft_strsplit(argv[1], ' ');
		stack_a->array = copy_argv_to_stack(array, stack_a);
	}
	else if (argc > 2)
		stack_a->array = copy_argv_to_stack(argv, stack_a);
	if (stack_a->array == NULL)
	{
		del_arrays(array, stack_a);
		return (NULL);
	}
	stack_a->name = 'a';
	find_max_min(stack_a);
	if (array)
		del_matrix(array);
	free(array);
	return (stack_a);
}

t_stack		*create_second_stack(t_stack *stack_a)
{
	t_stack		*stack_b;
	int			i;
	t_num		num;

	i = stack_a->size - 1;
	stack_b = (t_stack*)malloc(sizeof(t_stack));
	stack_b->array = (t_num*)malloc(sizeof(t_num) * stack_a->size);
	stack_b->name = 'b';
	stack_b->used_size = 0;
	stack_b->size = stack_a->size;
	stack_b->min = -1;
	stack_b->max = -1;
	while (i >= 0)
	{
		num_initialization(&num);
		stack_b->array[i] = num;
		stack_b->array[i].value = stack_a->array[i].value;
		stack_b->array[i].index = stack_a->array[i].index;
		i--;
		stack_b->used_size++;
	}
	return (stack_b);
}
