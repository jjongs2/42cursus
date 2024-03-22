/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:19:31 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/30 04:01:26 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	buf[12];

	ft_itoa(n, buf, 10);
	return (ft_putstr_fd(buf, fd));
}
