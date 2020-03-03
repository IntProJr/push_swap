/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:00:58 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/03 18:09:30 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

//static int	bonus_flag(char *argv[], t_op *val)
//{
//	char		*tmp;
//
//	if (argv[2] && (ft_strcmp(argv[2], "-v") == 0 ||
//		ft_strcmp(argv[2], "-vz") == 0))
//		return (-1);
//	if (ft_strcmp(argv[1], "-v") == 0)
//	{
//		val->v_flag = 1;
//		tmp = (val)->line;
//		ft_chr_and_fill(&tmp, '-', 30);
//	}
//	return (0);
//}

/*
** check_args: проверка на наличии входных параметров
** parse_stack: проверка валидности параметров, заполнение stack_a
** push_swap: основная функция сортировки стеков
*/

int			main(int argc, char *argv[])
{
	t_op		val;
	int 		*stack_a;

	stack_a = NULL;
	val.v_flag = 0;
	if (argc == 1 || check_args(argv, argc) == 0)
		return (ft_printf("Error\n"));
//	if (ft_strcmp(argv[1], "-v") == 0 || ft_strcmp(argv[1], "-vz") == 0)
//	{
//		if ((bonus_flag(argv, &val) == -1) ||
//		)
//	}


	return (0);
}
