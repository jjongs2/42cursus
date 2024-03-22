/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:54:05 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/22 11:49:36 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include "../00_Libft/include/ft_stdlib.h"
#include "../00_Libft/include/ft_string.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

typedef struct s_line
{
	char	*str;
	char	*old_str;
	size_t	old_len;
	size_t	new_len;
	int		read_cnt;
	int		lf;
}			t_line;

#endif
