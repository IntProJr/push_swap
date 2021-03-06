/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:16:21 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_ptr(size_t nb)
{
	char *str;

	str = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(str[nb]);
	else
	{
		ft_print_ptr(nb / 16);
		ft_putchar(str[nb % 16]);
	}
}

int			print_ptr(int char_printed, va_list *arg, t_printf p)
{
	void	*ptr;
	int		prec;
	int		p_len;

	prec = 0;
	ptr = va_arg(*arg, void *);
	p_len = ft_ptr_len_base((size_t)ptr, 16);
	if (!(p.precision == -1 && ptr == 0))
		char_printed += p_len;
	char_printed += 2;
	if (p.precision > 0)
		prec = p.precision - (ptr < 0 ? p_len - 1 : p_len);
	char_printed += printing_width(p, char_printed + (prec > 0 ? prec : 0));
	ft_putstr("0x");
	char_printed += print_zero_padding(p, char_printed);
	char_printed += print_precision(p, (int)ptr, p_len);
	if (!(p.precision == -1 && ptr == 0))
		ft_print_ptr((size_t)ptr);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}
