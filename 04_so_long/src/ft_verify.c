/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 01:31:20 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/13 02:36:57 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include "../include/so_long.h"
#include "../include/ft_utils.h"

static int	ft_verify_name(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	return (len >= 4 && !ft_strncmp(filename + len - 4, ".ber", 4));
}

static t_map	ft_get_map(int fd)
{
	t_map	map;
	char	*line;
	char	*str_old;

	ft_memset(&map, 0, sizeof(map));
	map.str = ft_calloc(1, sizeof(char));
	while (1)
	{
		line = get_next_line(fd);
		if (!map.row)
			map.col = ft_strlen(line);
		else if (!line)
			break ;
		if (map.col != ft_strlen(line))
			ft_puterr(MAP_ERR);
		map.row++;
		str_old = map.str;
		map.str = ft_strjoin(map.str, line);
		ft_free(&str_old);
		ft_free(&line);
	}
	return (map);
}

static int	ft_verify_elem(t_map *map)
{
	size_t	i;
	size_t	cnt[256];

	i = -1;
	while (++i < 256)
		cnt[i] = 0;
	i = -1;
	while (map->str[++i])
	{
		if (map->str[i] != '1')
		{
			if (i < map->col)
				return (0);
			if ((i % map->col == 0 || i % map->col == map->col - 1))
				return (0);
			if (i / map->col == map->row - 1)
				return (0);
		}
		cnt[(unsigned char)map->str[i]]++;
	}
	map->item = cnt['C'];
	return ((cnt['0'] + cnt['1'] + cnt['C'] + cnt['E'] + cnt['P'] == i) \
			&& cnt['C'] >= 1 && cnt['E'] >= 1 && cnt['P'] == 1);
}

t_map	ft_verify_map(char *filename)
{
	t_map	map;
	int		fd;

	if (!ft_verify_name(filename))
		ft_puterr(NAME_ERR);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_puterr(OPEN_ERR);
	map = ft_get_map(fd);
	close(fd);
	if (map.row * IMG_SIZE > INT_MAX || map.col * IMG_SIZE > INT_MAX)
		ft_puterr(SIZE_ERR);
	if (!ft_verify_elem(&map))
		ft_puterr(ELEM_ERR);
	return (map);
}
