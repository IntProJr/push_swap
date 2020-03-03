/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_multi_chr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:19:17 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/07 15:18:37 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_str_multi_chr(char *str, char *c)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (c[j])
		{
			if (str[i] == c[j])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
