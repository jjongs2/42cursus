/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:38:33 by yoson             #+#    #+#             */
/*   Updated: 2022/09/18 17:40:11 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "philo_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len--)
		*p++ = c;
	return (b);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	rem;
	size_t	len;
	ssize_t	cnt;

	if (!s || fd < 0)
		return ;
	rem = ft_strlen(s);
	while (rem)
	{
		len = rem;
		if (len > SSIZE_MAX)
			len = SSIZE_MAX;
		cnt = write(fd, s, len);
		if (cnt < 0)
			ft_puterr("write() failed");
		s += cnt;
		rem -= cnt;
	}
}

void	ft_puterr(char *err_msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(err_msg, 2);
	write(2, "\n", 1);
	exit(1);
}
