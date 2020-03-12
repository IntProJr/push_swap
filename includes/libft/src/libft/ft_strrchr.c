/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:29:17 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *position_c;

	position_c = NULL;
	while (*s)
	{
		if (*s == (char)c)
			position_c = ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	if (c == '\0')
		return ((char*)s);
	else
		return (position_c);
}
