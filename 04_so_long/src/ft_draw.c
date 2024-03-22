/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 03:04:36 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/12 14:34:58 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_init_img(void *img[], void *mlx)
{
	int		wid;
	int		hei;

	img['0'] = mlx_xpm_file_to_image(mlx, "./image/space.xpm", &wid, &hei);
	img['1'] = mlx_xpm_file_to_image(mlx, "./image/wall.xpm", &wid, &hei);
	img['C'] = mlx_xpm_file_to_image(mlx, "./image/item.xpm", &wid, &hei);
	img['P'] = mlx_xpm_file_to_image(mlx, "./image/player.xpm", &wid, &hei);
	img['E'] = mlx_xpm_file_to_image(mlx, "./image/exit.xpm", &wid, &hei);
}

void	ft_draw_map(t_map *map)
{
	size_t			r;
	size_t			c;
	unsigned char	i;

	r = -1;
	while (++r < map->row)
	{
		c = -1;
		while (++c < map->col)
		{
			i = (unsigned char)map->str[r * map->col + c];
			mlx_put_image_to_window(map->mlx, map->win, \
									map->img[i], c * IMG_SIZE, r * IMG_SIZE);
		}
	}
}

void	ft_init_map(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, \
				map->col * IMG_SIZE, map->row * IMG_SIZE, "so_long");
	ft_init_img(map->img, map->mlx);
	ft_draw_map(map);
}
