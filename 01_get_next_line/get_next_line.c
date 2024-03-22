/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:53:58 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/22 11:49:47 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

static void	ft_get_line(t_line *line, char buf[])
{
	line->old_str = line->str;
	line->old_len = ft_strlen(line->old_str);
	line->new_len = ft_strcspn(buf, "\n");
	if (buf[line->new_len] == '\n')
	{
		line->lf = 1;
		line->new_len++;
	}
	line->str = ft_calloc(1, line->old_len + line->new_len + 1);
	ft_memcpy(line->str, line->old_str, line->old_len);
	ft_memcpy(line->str + line->old_len, buf, line->new_len);
	ft_free((void *)&line->old_str);
}

char	*get_next_line(int fd)
{
	t_line		line;
	static char	buf[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0)
		return (NULL);
	ft_memset(&line, 0, sizeof(line));
	line.str = ft_calloc(1, 1);
	ft_get_line(&line, buf);
	while (!line.lf)
	{
		ft_memset(buf, 0, BUFFER_SIZE);
		line.read_cnt = read(fd, buf, BUFFER_SIZE);
		if (line.read_cnt <= 0)
			return (ft_free((void *)&line.str));
		ft_get_line(&line, buf);
	}
	ft_memcpy(buf, buf + line.new_len, BUFFER_SIZE - line.new_len + 1);
	return (line.str);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./get_next_line.h", O_RDONLY);
	// while (!usleep(100000))
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		write(1, line, ft_strlen(line));
		ft_free((void *)&line);
	}
	return (0);
}
