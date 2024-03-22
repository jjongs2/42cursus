/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:16:30 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:08:17 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static size_t	ft_wordcnt(char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (cnt);
		cnt++;
		while (*s != c && *s)
			s++;
	}
	return (cnt);
}

static char	**ft_wordgen(char *s, char c, size_t cnt, char **split)
{
	size_t	i;
	char	*p;

	i = 0;
	while (i < cnt)
	{
		while (*s == c)
			s++;
		p = ft_strchr(s, c);
		if (!p)
			p = ft_strchr(s, '\0');
		split[i] = ft_substr(s, 0, p - s);
		if (!split[i])
			ft_puterr(NULL);
		s = p;
		i++;
	}
	return (split);
}

char	**ft_split(char *s, char c)
{
	size_t	cnt;
	char	**split;

	cnt = ft_wordcnt(s, c);
	if (!cnt)
		ft_puterr(NULL);
	split = ft_calloc(cnt + 1, sizeof(char *));
	if (!split)
		ft_puterr(NULL);
	return (ft_wordgen(s, c, cnt, split));
}

void	ft_wordclr(char **split)
{
	size_t	i;

	i = -1;
	while (split[++i])
		ft_free((void *)&split[i]);
	ft_free((void *)&split);
}
