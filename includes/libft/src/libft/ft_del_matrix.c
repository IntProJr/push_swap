/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:47:05 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 16:47:05 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void		del_matrix(char **matrix)
{
	int 	i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i])
			free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
}
