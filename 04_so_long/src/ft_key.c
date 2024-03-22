/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 03:45:39 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/12 13:46:35 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/so_long.h"
#include "../include/ft_utils.h"

static void	ft_game_clear(t_map *map)
{
	printf("===========\n");
	printf("GAME CLEAR!\n");
	printf("Your Record: %d\n", ++map->move);
	exit(0);
}

int	ft_exit_game(t_map *map)
{
	mlx_destroy_image(map->mlx, map->win);
	exit(0);
}

int	ft_press_key(int key, t_map *map)
{
	int	cur;
	int	next;

	if (key == KEY_ESC)
		ft_exit_game(map);
	if (key != KEY_A && key != KEY_S && key != KEY_D && key != KEY_W)
		return (0);
	cur = ft_strchr(map->str, 'P') - map->str;
	next = cur + ((key == KEY_D) - (key == KEY_A)) \
			+ map->col * ((key == KEY_S) - (key == KEY_W));
	if (map->str[next] == 'C')
		map->score++;
	else if (map->str[next] == 'E' && map->score == map->item)
		ft_game_clear(map);
	if (map->str[next] == 'E' || map->str[next] == '1')
		return (0);
	map->str[next] = 'P';
	map->str[cur] = '0';
	printf("Move: %d\n", ++map->move);
	ft_draw_map(map);
	return (0);
}
