/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:52:34 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/12 13:52:34 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include_bonus/so_long_bonus.h"
#include "../include_bonus/ft_utils_bonus.h"

static int	ft_nbrlen(size_t n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_display_move(t_map *map)
{
	static char	*display;
	int			move;
	int			len;

	if (!display)
		display = ft_strdup("Movement: 0         ");
	move = map->move;
	len = 10 + ft_nbrlen(move);
	while (move)
	{
		display[--len] = move % 10 + '0';
		move /= 10;
	}
	mlx_string_put(map->mlx, map->win, 10, 20, WHITE, display);
}

int	ft_animate(t_map *map)
{
	ft_draw_map(map);
	map->frame++;
	ft_display_move(map);
	return (0);
}
