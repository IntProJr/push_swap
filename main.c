/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:00:58 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/03 16:44:10 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		main(int argc, char *argv[])
{
	t_op		val;
	int 		*stack_a;

	stack_a = NULL;
	val.v_flag = 0;
	if (argc == 1 || check_args(argv, argc) == 0)
		return (ft_printf("Error\n"));

	return (0);
}
