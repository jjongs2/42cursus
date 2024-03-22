/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:18:27 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/24 20:57:15 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_utils.h"

static int	ft_print_int(va_list ap)
{
	int		n;

	n = va_arg(ap, int);
	ft_putnbr(n, DEC);
	return (ft_nbrlen(n, DEC));
}

static int	ft_print_str(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

static int	ft_read_str(va_list ap, const char *s)
{
	int		cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'd')
				cnt += ft_print_int(ap);
			else if (*s == 's')
				cnt += ft_print_str(ap);
		}
		else
			cnt += write(1, s, 1);
		s++;
	}
	return (cnt);
}

int	ft_printf(const char *s, ...)
{
	int		cnt;
	va_list	ap;

	va_start(ap, s);
	cnt = ft_read_str(ap, s);
	va_end(ap);
	return (cnt);
}
