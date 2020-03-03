/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:09:14 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/02 12:09:14 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
