/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:20:47 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/07 15:20:25 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/headers/libft.h"

typedef struct		s_stack
{
	int 			value;
	int 			pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_op
{
	int 			max;
	int 			min;
	int				second_min;
	int				middle;
	int 			size_a;
	int 			size_b;
	int 			v_flag;
	int 			size;
	int 			pow;
	int 			*order;
	char 			bloc[200];
	char 			line[30];
	char 			spaces[200];
}					t_op;

typedef struct		s_actions
{
	int 			a_pos;
	int 			b_pos;
	int 			move_a;
	int 			move_b;
	t_op			*val;
}					t_actions;


int					check_args(char *argv[], int argc);
int					parse_stack(char **a, int **stack_a, char programm);
int					*get_min_max_middle(t_op *val, int *stack_a, int size);
t_stack				*stack_as_list(int *stack_a, int *order, int size);
void				free_stack_list(t_stack *stack);
void				sort_little_count(t_stack **a, t_stack **b, t_op *val,
					int size);
size_t				ft_lstcount(t_stack *lst);
void				ft_v(t_stack *a, t_stack *b, t_op *val,char *opt);

void				take_stack_op(t_stack **a, t_stack **b, t_op *val, char *opt);
void				option_rr(t_stack **stack);
void				option_r(t_stack **stack);
void				run_together(t_stack **stack, t_stack **stack_b,
					void (f)(t_stack **));
void				option_p(t_stack **stack_a, t_stack **stack_b);
void 				option_s(t_stack **stack);



# endif
