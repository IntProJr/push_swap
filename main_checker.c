/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:12:47 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/11 14:18:51 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_commands		*read_input(t_stack *a, t_stack *b)
{
	char		*line;
	t_commands	*head;
	int			fun;

	line = NULL;
	head = (t_commands*)malloc(sizeof(t_commands));
	head->next = NULL;
	head->command = NULL;
	while ((get_next_line(0, &line)) > 0)
	{
		if ((fun = validate_commands(line)) == -1)
		{
			ft_printf("Error\n");
			delete_commands_list(head);
			free(head->command);
			free(head);
			free(line);
			return (NULL);
		}
	}
}

void		checker(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	t_commands	*head;

	head = NULL;
	a = create_stack_argv(argc, argv);
	if (check_errors(a) == -1)
	{
		del_stack(a);
		return ;
	}
	b = create_second_stack(a);
	set_to_zero_stack(b);
	if ((head = read_input(a, b) == NULL))
	{
		del_stack(a);
		del_stack(b);
		return ;
	}
	free(head->command);
	free(head);
	del_stack(a);
	del_stack(b);
}

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
		checker(argc, argv);
	return (0);
}