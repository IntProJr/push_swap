/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:43:25 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/13 17:23:31 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/ft_printf.h"

void		ooo(char *decimal, t_printf *p)
{
	if (decimal[p->precision - 1] != '9' && p->drob >= 0.5)
		decimal[p->precision - 1] += 1;
	else if (decimal[p->precision - 1] == '9' && p->drob >= 0.5)
	{
		while (p->precision > 0 && decimal[p->precision - 1] == '9')
		{
			decimal[p->precision - 1] = '0';
			p->precision--;
		}
		decimal[p->precision - 1] += 1;
	}
}

static void	print_f_longdouble(char *integer, char *decimal, t_printf p)
{
	int i;

	i = 0;
	ooo(decimal, &p);
	while (integer[i])
		write(1, &integer[i++], 1);
	if (decimal[0] != '\0' || p.hash)
		write(1, ".", 1);
	i = 0;
	while (decimal[i])
		write(1, &decimal[i++], 1);
}

char		*decimal_f(long double nb, t_printf *p, char *integer_f)
{
	char	*s;
	int		i;

	i = 0;
	nb = nb < 0 ? -nb : nb;
	nb -= ft_atof(integer_f);
	if (!(s = (char *)ft_memalloc(p->precision + 1)))
		exit(1);
	while (i < p->precision)
	{
		nb *= 10;
		if (nb > 0)
			s[i] = (int)nb + '0';
		else
			s[i] = '0';
		i++;
		nb -= (int)nb;
	}
	p->drob = nb;
	return (s);
}

char		*integer_f(long double nb)
{
	char		*s;
	char		*ptr;
	int			len;
	int			i;
	long double temp;

	len = len_f(nb);
	if (!(s = (char *)ft_memalloc(len + 1)))
		exit(1);
	ptr = s;
	while (len > 0)
	{
		i = len - 1;
		temp = nb;
		while (i-- > 0)
			temp /= 10;
		*ptr++ = (int)temp + '0';
		temp = (int)temp;
		while (++i < len - 1)
			temp *= 10;
		nb -= temp;
		--len;
	}
	return (s);
}

int			write_f(t_printf p, char *integer, char *dec, long double nb)
{
	int len;
	int	char_printed;

	char_printed = 0;
	len = ft_strlen(integer) + ft_strlen(dec) + 1;
	if (dec[0] == '\0' && !p.hash)
		len--;
	if ((p.znak_plus || p.space) && nb >= 0)
		char_printed += 1;
	if (p.space && nb >= 0)
		ft_putchar(' ');
	char_printed += len;
	char_printed += printing_width(p, char_printed);
	if (p.znak_plus > 0)
		ft_putchar('+');
	if (p.znak_plus < 0)
		ft_putchar('-');
	char_printed += print_zero_padding(p, char_printed);
	print_f_longdouble(integer, dec, p);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}
