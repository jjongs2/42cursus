/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:31:31 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:02:10 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

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
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	while (*s2 && n--)
	{
		i = 0;
		while ((const unsigned char)s1[i] == (const unsigned char)s2[i])
		{
			if (*(s1 - 1))
				break ;
			if (!s2[i++])
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
