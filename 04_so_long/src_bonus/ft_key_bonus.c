/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 03:45:39 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/12 21:35:32 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include_bonus/so_long_bonus.h"
#include "../include_bonus/ft_utils_bonus.h"

static void	ft_game_clear(t_map *map)
{
	printf("GAME CLEAR!\n");
	printf("Your Record: %d\n", ++map->move);
	exit(0);
}

int	ft_exit_game(t_map *map)
{
	mlx_destroy_image(map->mlx, map->win);
	exit(0);
}

static void	ft_lose_game(t_map *map)
{
	printf("YOU LOSE..\n");
	ft_exit_game(map);
}

static void	ft_move_enemy(t_map *map)
{
	int	cur;
	int	next;

	cur = ft_strchr(map->str, 'X') - map->str;
	next = cur + ((map->move % 4 == 0) - (map->move % 4 == 2)) \
			+ map->col * ((map->move % 4 == 3) - (map->move % 4 == 1));
	if (map->str[next] != '0')
		return ;
	map->str[next] = 'X';
	map->str[cur] = '0';
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
	else if (map->str[next] == 'X')
		ft_lose_game(map);
	else if (map->str[next] == 'E' && map->score == map->item)
		ft_game_clear(map);
	if (map->str[next] == 'E' || map->str[next] == '1')
		return (0);
	map->str[next] = 'P';
	map->str[cur] = '0';
	map->move++;
	ft_move_enemy(map);
	ft_draw_map(map);
	return (0);
}
