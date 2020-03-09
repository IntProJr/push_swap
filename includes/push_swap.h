/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:20:47 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 20:07:23 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/headers/libft.h"

typedef struct	s_num
{
	int	val;
	int	index;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	v_flag;
	int	swap;
	int	total_moves;
}				t_num;

typedef struct	s_stack
{
	t_num	*arr;
	int		size;
	int		used_size;
	int		min;
	int		max;
	char	name;
}				t_stack;


int 		check_args(int argc, char *argv[]);
int			validate_arg(char *str);
int			validate_args(char **arr);
void	push_swap(int argc, char **argv);
t_stack		*create_argv_stack(int argc, char **argv);
int 	check_errors(t_stack *a);
void		init_num(t_num *n);
t_num		*copy_argv_to_stack(char **arr, t_stack *stack);
int 	is_it_sort(t_stack *a);
int 	is_it_dup(t_stack *a);
void		del_stack(t_stack *stack);
void		get_min_max(t_stack *stk);
t_stack 	*create_second_stack(t_stack *a);
void	quick_sort(t_num *arr, int low, int high);
void		change_index(t_stack *a, t_stack *b);
void		set_to_zero_stack(t_stack *b);
void 	push_b(t_stack *a, t_stack *b);
void 	rotate_a(t_stack *a);
void 	rotate_stk(t_stack *stk);
void count_moves(t_stack *a, t_stack *b);
int 	find_min_actions(t_stack *b);
void	rev_rotate_stk(t_stack *stk);
void		sort_small(t_stack *a, t_stack *b);


# endif
