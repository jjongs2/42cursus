/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:09:31 by kijsong           #+#    #+#             */
/*   Updated: 2022/07/23 13:13:52 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addrlen(uintptr_t addr)
{
	int	len;

	if (addr == 0)
		return (1);
	len = 0;
	while (addr > 0)
	{
		len++;
		addr /= 16;
	}
	return (len);
}

void	ft_putaddr(uintptr_t addr)
{
	if (addr >= 16)
		ft_putaddr(addr / 16);
	ft_putnchar(HEX[addr % 16], 1);
}

void	ft_print_addr(t_info *info)
{
	uintptr_t	addr;
	int			len;

	addr = va_arg(info->ap, uintptr_t);
	len = ft_addrlen(addr);
	info->width -= len + 2;
	if (info->minus == FALSE)
		info->count += ft_putnchar(' ', info->width);
	info->count += write(1, "0x", 2) + len;
	ft_putaddr(addr);
	if (info->minus == TRUE)
		info->count += ft_putnchar(' ', info->width);
}
