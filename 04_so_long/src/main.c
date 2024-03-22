/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:21:15 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/12 13:36:35 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		ft_puterr(ARG_ERR);
	map = ft_verify_map(argv[1]);
	ft_init_map(&map);
	mlx_hook(map.win, KEY_PRESS, 0, ft_press_key, &map);
	mlx_hook(map.win, DESTROY_NOTIFY, 0, ft_exit_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
