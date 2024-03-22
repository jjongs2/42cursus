/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:34:34 by kijsong           #+#    #+#             */
/*   Updated: 2022/07/20 15:34:34 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

#define BUF_SIZE 10

void	ft_func_init(void *f[])
{
	f['c'] = ft_print_char;
	f['s'] = ft_print_str;
	f['p'] = ft_print_addr;
	f['d'] = ft_print_int;
	f['i'] = ft_print_int;
	f['u'] = ft_print_uint;
	f['x'] = ft_print_hex_lower;
	f['X'] = ft_print_hex_upper;
	f['%'] = ft_print_percent_sign;
}

int	ft_vfprintf(int fd, const char *fmt, va_list ap)
{
	int		ret;
	void	*f[256];
	int		(*func)(va_list, char *);
	char	*dup;
	char	buf[BUF_SIZE];
	size_t	ps;

	ft_func_init(memset(f, 0, sizeof(f)));
	dup = strdup(fmt);
	while (*fmt)
	{
		memset(buf, 0, BUF_SIZE);
		ps = strcspn(fmt, "%");
		memcpy(buf, fmt, min(ps, BUF_SIZE));
		fmt += ps;
		if (buf[BUF_SIZE - 1])
			cnt = write(fd, buf, BUF_SIZE);
		if (*fmt == '%')
		{
			func = f[*++fmt];
			func(ap, buf);	
		}
	}
	free(dup);
	return (ret);
}

int	ft_fprintf(int fd, const char *fmt, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, fmt);
	ret = ft_vfprintf(fd, fmt, ap);
	va_end(ap);
	return (ret);
}
