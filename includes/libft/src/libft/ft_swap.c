/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:06:06 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/04 16:06:06 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void		ft_swap(int *stack, int left, int right)
{
	int		tmp;

	tmp = stack[left];
	stack[left] = stack[right];
	stack[right] = tmp;
}
