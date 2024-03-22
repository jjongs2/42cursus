/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:32:25 by kijsong           #+#    #+#             */
/*   Updated: 2022/07/23 14:22:35 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

void	ft_print_hex(t_info *info, long long n, const char *base)
{
	int		len;

	if (n == 0)
		info->hash = FALSE;
	len = ft_nbrlen(info, n, base);
	info->width -= ft_max(info->precision, len) + info->hash * 2;
	if (info->minus == FALSE && info->zero == FALSE)
		info->count += ft_putnchar(' ', info->width);
	if (info->hash == TRUE)
	{
		if (base[10] == 'a')
			info->count += write(1, "0x", 2);
		else
			info->count += write(1, "0X", 2);
	}
	if (info->minus == FALSE && info->zero == TRUE)
		info->count += ft_putnchar('0', info->width);
	info->count += ft_putnchar('0', info->precision - len) + len;
	if (len > 0)
		ft_putnbr_base(n, base);
	if (info->minus == TRUE)
		info->count += ft_putnchar(' ', info->width);
}

void	ft_print_hex_lower(t_info *info)
{
	unsigned int	n;

	n = va_arg(info->ap, unsigned int);
	ft_print_hex(info, n, HEX);
}

void	ft_print_hex_upper(t_info *info)
{
	unsigned int	n;

	n = va_arg(info->ap, unsigned int);
	ft_print_hex(info, n, HEX_UP);
}
