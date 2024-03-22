/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:59:46 by kijsong           #+#    #+#             */
/*   Updated: 2022/07/23 14:11:52 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_sign(t_info *info, int n)
{
	if (info->space == TRUE && n >= 0)
		return (1);
	if (info->plus == TRUE || n < 0)
		return (1);
	return (0);
}

void	ft_print_dec(t_info *info, long long n, int is_uint)
{
	char	c;
	int		len;

	c = ' ';
	if (info->zero == TRUE)
		c = '0';
	len = ft_nbrlen(info, n, DEC);
	info->width -= ft_max(info->precision, len);
	if (is_uint == FALSE)
		info->width -= ft_check_sign(info, n);
	if (info->minus == FALSE)
	{
		if (info->zero == TRUE && is_uint == FALSE)
			info->count += ft_print_sign(info, n);
		info->count += ft_putnchar(c, info->width);
	}
	if (info->zero == FALSE && is_uint == FALSE)
		info->count += ft_print_sign(info, n);
	info->count += ft_putnchar('0', info->precision - len) + len;
	if (len > 0)
		ft_putnbr_base(n, DEC);
	if (info->minus == TRUE)
		info->count += ft_putnchar(' ', info->width);
}

void	ft_print_int(t_info *info)
{
	int		n;

	n = va_arg(info->ap, int);
	ft_print_dec(info, n, FALSE);
}

void	ft_print_uint(t_info *info)
{
	unsigned int	n;

	n = va_arg(info->ap, unsigned int);
	ft_print_dec(info, n, TRUE);
}
