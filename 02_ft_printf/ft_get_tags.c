/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_tags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:03:16 by kijsong           #+#    #+#             */
/*   Updated: 2022/07/21 02:03:16 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char **s)
{
	int	n;

	n = 0;
	while (**s >= '0' && **s <= '9')
	{
		n = (n * 10) + **s - '0';
		(*s)++;
	}
	return (n);
}

void	ft_tags_init(t_info *info)
{
	info->error = FALSE;
	info->minus = FALSE;
	info->zero = FALSE;
	info->dot = FALSE;
	info->hash = FALSE;
	info->space = FALSE;
	info->plus = FALSE;
	info->width = 0;
	info->precision = 0;
}

void	ft_ignore_tags(t_info *info)
{
	if (info->minus == TRUE && info->zero == TRUE)
		info->zero = FALSE;
	if (info->plus == TRUE && info->space == TRUE)
		info->space = FALSE;
}

const char	*ft_get_tags(const char *s, t_info *info)
{
	while (ft_strchr(FLAGS, *s) != NULL)
	{
		if (*s == '#')
			info->hash = TRUE;
		else if (*s == '-')
			info->minus = TRUE;
		else if (*s == '0')
			info->zero = TRUE;
		else if (*s == '+')
			info->plus = TRUE;
		else if (*s == ' ')
			info->space = TRUE;
		s++;
	}
	ft_ignore_tags(info);
	info->width = ft_atoi(&s);
	if (*s == '.')
	{
		s++;
		info->dot = TRUE;
		info->zero = FALSE;
		info->precision = ft_atoi(&s);
	}
	return (s);
}
