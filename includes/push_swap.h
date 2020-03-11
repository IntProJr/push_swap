/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:20:47 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/11 15:03:32 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/headers/libft.h"

typedef struct	s_num
{
	int		value;
	int		index;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		v_flag;
	int		swap;
	int		total_moves;
}				t_num;

typedef struct	s_stack
{
	t_num	*array;
	int		size;
	int		used_size;
	int		min;
	int		max;
	char	name;
}				t_stack;

typedef struct	s_commands
{
	char				*command;
	void				(*fun_for_a)(t_stack *a);
	void				(*fun_for_b)(t_stack *b);
	void				(*fun_for_two)(t_stack *a, t_stack *b);
	struct s_commands	*next;
}				t_commands;

int 		check_args(int argc, char *argv[]);
int			validate_arg(char *str);
int			validate_args(char **arr);
void		push_swap(int argc, char **argv);
t_stack		*create_stack_argv(int argc, char **argv);
int 		check_errors(t_stack *stack_a);
void		num_initialization(t_num *n);
t_num		*copy_argv_to_stack(char **array, t_stack *stack);
int 		sorting(t_stack *stack_a);
int 		duplication(t_stack *stack_a);
void		del_stack(t_stack *stack);
void		find_max_min(t_stack *stack);
t_stack 	*create_second_stack(t_stack *stack_a);
void		quick_sort(t_num *array, int low, int high);
void		change_index(t_stack *stack_a, t_stack *stack_b);
void		set_to_zero_stack(t_stack *stack_b);
void 		push_b(t_stack *a, t_stack *b);
void		rotate_a(t_stack *a);
void 		rotate_stk(t_stack *stk);
void 		count_moves(t_stack *a, t_stack *b);
int 		find_min_actions(t_stack *b);
void		rev_rotate_stk(t_stack *stk);
void		sort_small(t_stack *a, t_stack *b);
void		swap_top(t_stack *stk);
void		set_to_zero_moves(t_num *n);
void		rev_rotate_a(t_stack *a);
void		rotate_b(t_stack *b);
void		rev_rotate_b(t_stack *b);
void		rotate_rr(t_stack *a, t_stack *b);
void		rev_rotate_r(t_stack *a, t_stack *b);
void		push_a(t_stack *a, t_stack *b);
void		swap_a(t_stack *a);
void		do_moves(t_stack *a, t_stack *b);
void 		kick_val_to_top(t_stack *a, int val);
void		del_arrays(char **arr, t_stack *stack_a);
void		sort_three(t_stack *a);
int 		more_sort(t_stack *stack_a, int mid);
void		kick_to_b_except(t_stack *stack_a, t_stack *stack_b,
						 int hold_min, int hold_max);
int 		range_sort(t_stack *stack_a, int bottom, int top);
int 		less_sort(t_stack *stack_a, int mid);
int 		find_over_value(t_stack *stack_a);
void		checker(int argc, char *argv[]);
t_commands	*add_command(t_commands *head, char *line, int fun);
int		validate_commands(char *line);
void		delete_commands_list(t_commands *head);
void	swap_ss_stcks(t_stack *a, t_stack *b);
void	rotate_rr_stcks(t_stack *a, t_stack *b);
void	rev_rotate_stcks(t_stack *a, t_stack *b);
void	push_stack_a(t_stack *a, t_stack *b);
void	push_stack_b(t_stack *a, t_stack *b);



# endif
