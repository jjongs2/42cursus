/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:13:09 by kijsong           #+#    #+#             */
/*   Updated: 2022/07/23 12:13:15 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnchar(char c, int n)
{
	int	cnt;

	cnt = 0;
	while (n-- > 0)
		cnt += write(1, &c, 1);
	return (cnt);
}

int	ft_putstr(char *s)
{
	int	cnt;

	cnt = 0;
	while (*s != '\0')
		cnt += write(1, s++, 1);
	return (cnt);
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
