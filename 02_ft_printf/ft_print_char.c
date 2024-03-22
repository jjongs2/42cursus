/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:39:19 by kijsong           #+#    #+#             */
/*   Updated: 2022/07/23 12:06:17 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	ft_fill_char(t_info *info, int len)
{
	char	c;

	c = ' ';
	if (info->zero == TRUE && info->dot == FALSE)
		c = '0';
	while (len < info->width)
	{
		info->count += write(1, &c, 1);
		len++;
	}
}

void	ft_print_char(t_info *info)
{
	char	c;

	c = (char)va_arg(info->ap, int);
	if (info->width > 0 && info->minus == FALSE)
		ft_fill_char(info, 1);
	info->count += write(1, &c, 1);
	if (info->width > 0 && info->minus == TRUE)
		ft_fill_char(info, 1);
}

void	ft_print_percent_sign(t_info *info)
{
	if (info->width > 0 && info->minus == FALSE)
		ft_fill_char(info, 1);
	info->count += write(1, "%", 1);
	if (info->width > 0 && info->minus == TRUE)
		ft_fill_char(info, 1);
}

void	ft_print_str(t_info *info)
{
	char	*s;
	int		len;

	s = va_arg(info->ap, char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (len >= INT_MAX)
	{
		info->error = TRUE;
		return ;
	}
	if (len > info->precision && info->dot == TRUE)
		len = info->precision;
	if (info->width > 0 && info->minus == FALSE)
		ft_fill_char(info, len);
	info->count += write(1, s, len);
	if (info->width > 0 && info->minus == TRUE)
		ft_fill_char(info, len);
}
