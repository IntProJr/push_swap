/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:00:58 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int			main(int argc, char *argv[])
{
	if (argc == 1 || check_args(argc, argv) == 0)
		return (ft_printf("Error non printable\n"));
	if (argc == 2)
	{
		if ((validate_arg(argv[1])) == -1)
		{
			ft_printf("Error validation arg\n");
			exit(0);
		}
	}
	else if (argc > 2)
	{
		if ((validate_args(++argv)) == -1)
		{
			ft_printf("Error validation args\n");
			exit(0);
		}
	}
	if (argc >= 2)
		push_swap(argc, argv);
	return (0);
}
