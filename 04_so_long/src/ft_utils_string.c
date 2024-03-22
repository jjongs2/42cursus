/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:23:41 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/12 13:30:38 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*(const unsigned char *)s == (unsigned char)c)
			return ((char *)s);
		if (!*s)
			break ;
		s++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	while (n--)
	{
		c1 = *(const unsigned char *)s1++;
		c2 = *(const unsigned char *)s2++;
		if (!c1 || c1 != c2)
			return (c1 - c2);
	}
	return (0);
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
			return ;
		s += cnt;
		rem -= cnt;
	}
}

void	ft_puterr(char *err_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_msg, 2);
	exit(1);
}
