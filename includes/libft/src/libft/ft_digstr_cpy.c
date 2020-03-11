/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digstr_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:55:26 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/04 12:55:26 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int		*ft_digstr_cpy(int *stack, int size)
{
	int		*s_a;
	int		i;

	i = 0;
	s_a = NULL;
	s_a = (int *)malloc(sizeof(int) * size);
	if (s_a)
		return (NULL);
	while (i < size)
	{
		s_a[i] = stack[i];
		i++;
	}
	return (s_a);
}
