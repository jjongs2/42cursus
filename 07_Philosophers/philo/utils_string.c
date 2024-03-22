/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:38:33 by yoson             #+#    #+#             */
/*   Updated: 2022/09/14 11:42:11 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

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
			return ;
		s += cnt;
		rem -= cnt;
	}
}

int	ft_puterr(char *err_msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(err_msg, 2);
	write(2, "\n", 1);
	return (1);
}
