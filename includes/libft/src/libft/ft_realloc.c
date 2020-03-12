/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 17:06:33 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_realloc(void *src, size_t old_size, size_t new_size)
{
	void	*dst;

	if (src == NULL)
		return (NULL);
	dst = NULL;
	if (new_size != 0)
	{
		if ((dst = malloc(new_size)) == NULL)
			return (NULL);
		ft_memcpy(dst, src, old_size);
	}
	free(src);
	return (dst);
}
