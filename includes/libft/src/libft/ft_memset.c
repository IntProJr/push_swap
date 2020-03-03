/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:40:13 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/03 16:16:46 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memset(void *destination, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char*)destination;
	i = 0;
	if (len)
	{
		while (i < len)
		{
			p[i] = c;
			i++;
		}
	}
	return (destination);
}
