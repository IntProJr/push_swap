/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:18:33 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/ft_printf.h"

int	precision(char *str)
{
	int		i;
	char	tmp[ft_strlen(str)];
	int		j;

	i = 0;
	ft_memset(tmp, '\0', ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			ft_memset(tmp, '\0', ft_strlen(str));
			j = 0;
			i++;
			while (ft_strchr("0123456789", str[i]) && str[i] != '\0')
				tmp[j++] = str[i++];
		}
		else
			i++;
	}
	if (ft_strchr(str, '.') && ((ft_strcmp(tmp, "0") == 0 ||
		ft_strcmp(tmp, "00") == 0 || ft_strcmp(tmp, "000") == 0 ||
		ft_strcmp(tmp, "0000") == 0 || ft_strcmp(tmp, "00000") == 0) ||
		tmp[0] == '\0'))
		return (-1);
	return (ft_atoi(tmp));
}
