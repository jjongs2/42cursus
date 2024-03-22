/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:28:24 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/24 21:08:40 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_nbrlen(long long n, const char *base)
{
	int	len;
	int	base_len;

	len = (n <= 0);
	base_len = ft_strlen(base);
	while (n)
	{
		len++;
		n /= base_len;
	}
	return (len);
}

void	ft_putnbr(long long n, const char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= base_len)
		ft_putnbr(n / base_len, base);
	write(1, &base[n % base_len], 1);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

	n = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = (*str == '-') - (*str == '+');
	if (sign)
		str++;
	else
		sign = -1;
	while (*str >= '0' && *str <= '9')
		n = n * 10 - (*str++ - '0');
	return (n * sign);
}
