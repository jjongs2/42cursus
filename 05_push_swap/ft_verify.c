/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:32:08 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 22:49:57 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_utils.h"

static int	ft_verify_atoi(char *str)
{
	ssize_t	n;
	size_t	len;
	int		sign;

	n = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = (*str == '-') - (*str == '+');
	if (sign)
		str++;
	else
		sign = -1;
	len = ft_strlen(str);
	if (!len || len > 10)
		ft_puterr(NULL);
	while (*str >= '0' && *str <= '9')
		n = n * 10 - (*str++ - '0');
	if (*str || n < INT_MIN || n * sign > INT_MAX)
		ft_puterr(NULL);
	return (n * sign);
}

t_list	ft_verify(int argc, char *argv[])
{
	t_list	a;
	ssize_t	idx;
	int		num;

	if (argc <= 1)
		exit(0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv++;
	ft_memset(&a, 0, sizeof(a));
	idx = -1;
	while (argv[++idx])
	{
		num = ft_verify_atoi(argv[idx]);
		ft_lstadd_back(&a, ft_lstnew(num));
	}
	if (argc == 2)
		ft_wordclr(argv);
	if (!idx || idx > INT_MAX)
		ft_puterr(NULL);
	a.size = idx;
	a.is_a = 1;
	return (a);
}
