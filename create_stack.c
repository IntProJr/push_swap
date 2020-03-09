/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:15:00 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 16:41:26 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		init_num(t_num *n)
{
	n->val = -1;
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

void		del_arrays(char **arr, t_stack *a)
{
	del_matrix(arr);
	free(arr);
	free(a);
	ft_printf("Error\n");
}

t_stack		*create_argv_stack(int argc, char *argv[])
{
	t_stack		*a;
	char		**arr;

	arr = NULL;
	a = (t_stack *)malloc(sizeof(t_stack));
	if (argc == 2)
	{
		arr = ft_strsplit(argv[1], ' ');
		a->arr = copy_argv_to_stack(arr, a);
	}
	else if (argc > 2)
		a->arr = copy_argv_to_stack(argv, a);
	if(a->arr == NULL)
	{
		del_arrays(arr, a);
		return (NULL);
	}
	a->name = 'a';
	get_min_max(a);


}
