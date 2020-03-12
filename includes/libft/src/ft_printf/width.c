/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:18:06 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width(char *str)
{
	int		i;
	int		j;
	char	*tmp;
	char	*before;
	int		width;

	i = 0;
	j = 0;
	width = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[i] != '\0')
	{
		before = ft_strndup(str, i);
		if (ft_strchr("0123456789", str[i]) && !ft_strchr(before, '.'))
		{
			tmp[j] = str[i];
			j++;
		}
		free(before);
		i++;
	}
	width = ft_atoi(tmp);
	free(tmp);
	return (width);
}
