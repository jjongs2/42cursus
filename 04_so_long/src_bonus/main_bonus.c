/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:38:15 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/12 15:45:04 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		ft_puterr(ARG_ERR);
	map = ft_verify_map(argv[1]);
	ft_init_map(&map);
	mlx_hook(map.win, KEY_PRESS, 0, ft_press_key, &map);
	mlx_hook(map.win, DESTROY_NOTIFY, 0, ft_exit_game, &map);
	mlx_loop_hook(map.mlx, ft_animate, &map);
	mlx_loop(map.mlx);
	return (0);
}
