/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:16:34 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/03 16:37:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	parsing_format(va_list *arg, char *format)
{
	size_t	printed_char;

	printed_char = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			printed_char += parsing_percent(arg, &format);
		else
		{
			ft_putchar(*format);
			printed_char++;
		}
		if (*format != '\0')
			format++;
	}
	return (printed_char);
}

int				ft_printf(const char *format, ...)
{
	va_list		arg;
	size_t		printed_char;

	va_start(arg, format);
	printed_char = parsing_format(&arg, (char *)format);
	va_end(arg);
	return (printed_char);
}
