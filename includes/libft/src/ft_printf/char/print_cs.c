/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:42:48 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:59 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/ft_printf.h"

static int	printing_string_null(int printed_char, t_printf p)
{
	int prec;

	prec = p.precision;
	printed_char += 6;
	printed_char += printing_width(p, printed_char);
	printed_char += print_zero_padding(p, printed_char);
	if (prec > 0)
		ft_putnstr("(null)", prec);
	else if (prec != -1)
		ft_putstr("(null)");
	return (printed_char);
}

static int	printing_string(int char_printed, t_printf p, char *str)
{
	const int	prec = p.precision;

	if (str || prec != 0)
	{
		if (!str)
			if ((str = (char*)malloc(sizeof(char) * 7)))
				str = "(null)";
		if (prec == 0 && ft_strlen(str) > 0)
			char_printed += (int)ft_strlen(str);
		else if (str && prec > 0 && prec < (int)ft_strlen(str))
			char_printed += prec;
		else if (str && prec > 0)
			char_printed += (int)ft_strlen(str);
		char_printed += printing_width(p, char_printed);
		char_printed += print_zero_padding(p, char_printed);
		if (prec > 0)
			ft_putnstr(str, prec);
		else if (prec != -1)
			ft_putstr(str);
	}
	else
		char_printed += printing_string_null(char_printed, p);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}

int			printing_only_char(int printed_char, t_printf p)
{
	printed_char += 1;
	printed_char += printing_width(p, printed_char);
	printed_char += print_zero_padding(p, printed_char);
	ft_putchar(p.conversion_percent);
	printed_char += print_width_minus(p, printed_char);
	return (printed_char);
}

static int	printing_char(int printed_char, t_printf p, char c)
{
	printed_char += 1;
	printed_char += printing_width(p, printed_char);
	printed_char += print_zero_padding(p, printed_char);
	ft_putchar(c);
	printed_char += print_width_minus(p, printed_char);
	return (printed_char);
}

int			printing_string_char(va_list *arg, t_printf p)
{
	int		printed_char;
	char	c;
	char	*string;

	printed_char = 0;
	if (p.conversion_percent == 'c')
	{
		c = (char)va_arg(*arg, int);
		printed_char += printing_char(printed_char, p, c);
	}
	else if (p.conversion_percent == 's')
	{
		string = (char *)va_arg(*arg, char *);
		printed_char += printing_string(printed_char, p, string);
	}
	return (printed_char);
}
