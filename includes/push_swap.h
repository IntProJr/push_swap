/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:20:47 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/03 18:35:15 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/headers/libft.h"

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

int					check_args(char *argv[], int argc);
int					parse_stack(char **a, int **stack_a, char programm);





# endif
