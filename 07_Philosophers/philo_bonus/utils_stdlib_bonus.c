/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stdlib_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:28:50 by yoson             #+#    #+#             */
/*   Updated: 2022/09/14 15:26:56 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	time_t	n;

	n = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (ft_strlen(str) >= 19)
		ft_puterr("Invalid argument");
	while (*str >= '0' && *str <= '9')
		n = n * 10 + (*str++ - '0');
	if (*str || !n)
		ft_puterr("Invalid argument");
	if (n > INT_MAX)
		ft_puterr("Value too large for defined data type");
	return (n);
}

void	*ft_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		ft_puterr("Out of memory");
	return (p);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	size *= count;
	p = ft_malloc(size);
	return (ft_memset(p, 0, size));
}
