/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_len_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:19:04 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/07 15:18:37 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

size_t	ft_ptr_len_base(size_t ptr, unsigned int base)
{
	size_t	len;

	len = 1;
	while (ptr >= base)
	{
		ptr /= base;
		len++;
	}
	return (len);
}
