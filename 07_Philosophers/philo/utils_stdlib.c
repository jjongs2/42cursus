/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stdlib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:28:50 by yoson             #+#    #+#             */
/*   Updated: 2022/09/14 11:28:48 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "philo.h"

int	ft_atoi(const char *str)
{
	time_t	n;

	n = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (ft_strlen(str) > 10)
		return (0);
	while (*str >= '0' && *str <= '9')
		n = n * 10 + (*str++ - '0');
	if (*str || n > INT_MAX)
		return (0);
	return (n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	size *= count;
	p = malloc(size);
	if (!p)
		return (NULL);
	return (ft_memset(p, 0, size));
}
