/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:54:02 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/20 17:21:12 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/ft_utils.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len--)
		*p++ = c;
	return (b);
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

char	*ft_substr(const char *s, size_t start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s || !len)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_calloc(1, sizeof(char)));
	if (len > s_len - start)
		len = s_len - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	while (len--)
		sub[len] = s[start + len];
	return (sub);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = ft_calloc(len + 1, sizeof(char));
	if (!join)
		return (NULL);
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	return (join - len);
}

char	*ft_free(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}
