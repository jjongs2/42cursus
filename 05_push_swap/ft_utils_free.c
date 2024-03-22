/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:10:41 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:10:41 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_utils.h"

void	*ft_free(void **p)
{
	free(*p);
	*p = NULL;
	return (NULL);
}

void	ft_puterr(void *p)
{
	ft_free(&p);
	ft_putstr_fd("Error", 2);
	exit(1);
}
