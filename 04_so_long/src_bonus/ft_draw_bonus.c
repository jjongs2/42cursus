/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:38:15 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/12 17:02:52 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"
#include "../include_bonus/ft_utils_bonus.h"

static char	*ft_name_img(int type, int i)
{
	char	*filename;

	if (type == 'P')
		filename = ft_strdup("./image/player/0.xpm");
	else
		filename = ft_strdup("./image/enemy/0.xpm");
	if (i)
		filename[ft_strlen(filename) - 5] = '0' + i;
	return (filename);
}

static void	ft_init_img(void *img[][IMG_COUNT], void *mlx)
{
	int		wid;
	int		hei;
	int		i;
	char	*filename;

	img['0'][0] = mlx_xpm_file_to_image(mlx, "./image/space.xpm", &wid, &hei);
	img['1'][0] = mlx_xpm_file_to_image(mlx, "./image/wall.xpm", &wid, &hei);
	img['C'][0] = mlx_xpm_file_to_image(mlx, "./image/item.xpm", &wid, &hei);
	img['E'][0] = mlx_xpm_file_to_image(mlx, "./image/exit.xpm", &wid, &hei);
	i = -1;
	while (++i < IMG_COUNT)
	{
		filename = ft_name_img('P', i);
		img['P'][i] = mlx_xpm_file_to_image(mlx, filename, &wid, &hei);
		ft_free(&filename);
	}
	i = -1;
	while (++i < IMG_COUNT)
	{
		filename = ft_name_img('X', i);
		img['X'][i] = mlx_xpm_file_to_image(mlx, filename, &wid, &hei);
		ft_free(&filename);
	}
}

void	ft_draw_map(t_map *map)
{
	size_t			r;
	size_t			c;
	int				frame;
	unsigned char	i;

	r = -1;
	while (++r < map->row)
	{
		c = -1;
		while (++c < map->col)
		{
			i = (unsigned char)map->str[r * map->col + c];
			if (i == 'P' || i == 'X')
				frame = (map->frame / 5) % IMG_COUNT;
			else
				frame = 0;
			mlx_put_image_to_window(map->mlx, map->win, \
								map->img[i][frame], c * IMG_SIZE, r * IMG_SIZE);
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
