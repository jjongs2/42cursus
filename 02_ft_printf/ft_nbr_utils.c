/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:30:52 by kijsong           #+#    #+#             */
/*   Updated: 2022/07/22 11:30:52 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_nbrlen(t_info *info, long long n, const char *base)
{
	int	len;
	int	base_len;

	if (n == 0)
	{
		if (info->dot == TRUE && info->precision == 0)
			return (0);
		return (1);
	}
	len = 0;
	base_len = ft_strlen(base);
	while (n != 0)
	{
		len++;
		n /= base_len;
	}
	return (len);
}

int	ft_print_sign(t_info *info, int n)
{
	if (n < 0)
		return (write(1, "-", 1));
	if (info->plus == TRUE)
		return (write(1, "+", 1));
	if (info->space == TRUE)
		return (write(1, " ", 1));
	return (0);
}

void	ft_putnbr_base(long long n, const char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n < 0)
		n *= -1;
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
	ft_putnchar(base[n % base_len], 1);
}
