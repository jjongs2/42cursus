/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:22:09 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/12 15:33:43 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stddef.h>
# include "../mlx/mlx.h"

# define ARG_ERR "Invalid argument\n"
# define NAME_ERR "Wrong file name\n"
# define OPEN_ERR "No such file or directory\n"
# define MAP_ERR "Invalid map\n"
# define SIZE_ERR "Map too large\n"
# define ELEM_ERR "Invalid map element\n"	

# define IMG_SIZE 64
# define IMG_COUNT 2
# define WHITE 0xFFFFFF

enum e_event
{
	KEY_PRESS = 2,
	DESTROY_NOTIFY = 17
};

enum e_key
{	
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_ESC = 53
};

typedef struct s_map
{
	size_t	row;
	size_t	col;
	char	*str;
	void	*mlx;
	void	*win;
	void	*img[256][IMG_COUNT];
	int		item;
	int		score;
	int		move;
	int		frame;
}			t_map;

t_map	ft_verify_map(char *file_name);
void	ft_puterr(char *s);
void	ft_draw_map(t_map *map);
void	ft_init_map(t_map *map);
int		ft_press_key(int key, t_map *map);
int		ft_exit_game(t_map *map);
int		ft_animate(t_map *map);

#endif
