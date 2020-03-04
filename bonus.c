/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:14:36 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/04 17:49:56 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	output_alig(int a_size, int b_size, int size)
{
	int		cr;

	if (a_size >= b_size)
		cr = size - a_size;
	else if (b_size > a_size)
		cr = size - b_size;
	else
		cr = 0;
	while (cr > 0)
	{
		ft_printf("\n");
		cr--;
	}
}

static int 	a_side_output(t_stack **a, t_op *val,
			int *a_size, int *b_size)
{
	const char	*format;
	int 		sp;
	int 		len;

	len = 0;
	if ((*a)->pos == val->size_a + val->size_b)
		format = "\33[01;38;05;199m%d %.*s\033[0m";
	else if (*a && (*a)->next && (((*a)->next)->pos - (*a)->pos == 1))
		format = "\33[01;38;05;77m%d %.*s\033[0m";
	else if (*a && (*a)->prev && ((*a)->pos - ((*a)->prev)->pos == 1))
		format = "\33[01;38;05;77m%d %.*s\033[0m";
	else
		format = "%d %.*s";
	if ((sp = val->pow - take_power((*a)->pos)) > 0)
		len = ft_printf("%.*s", (sp), val->spaces);
	len += ft_printf(format, (*a)->pos, (*a)->pos, val->bloc);
	if (*format == '\033')
		len -= ((*a)->pos == val->size) ? 19 : 18;
	len += ft_printf(format)


}

void		ft_vz(t_stack *a, t_stack *b, t_op *val, char *opt)
{
	const char 	*speed;
	int 		len;
	int 		sz;
	int 		a_size;
	int 		b_size;

	speed = (val->size < 70) ? "sleep 0.07" : "sleep 0.01";
	a_size = val->size_a;
	b_size = val->size_b;
	sz = val->size + 30;
	system(speed);
	system("clear");
	output_alig(a_size, b_size, val->size);
	while (a_size > b_size && a)
		a_side_output(&a, val, &a_size, &b_size);
	while (a_size < b_size && b)
		b_side_output(&b, val, sz, &b_size);
	while (b_size > 0 && a_size > 0 && a && b)
	{
		len = a_side_output(&a, val, &a_size, &b_size);
		b_side_output(&b, val, (sz - len), &b_size);
	}
	ft_printf("CMD: %s", opt);
}
