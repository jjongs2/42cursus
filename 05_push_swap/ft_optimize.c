/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 06:51:16 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:33:02 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_utils.h"
#include "push_swap.h"

static int	ft_opt_push(char *cmd[], int idx)
{
	int	i;
	int	start;
	int	push[2];

	ft_memset(push, 0, sizeof(push));
	start = idx--;
	while (*cmd[++idx] == 'p')
	{
		i = cmd[idx][1] - 'a';
		push[i]++;
		if (push[i] == push[i ^ 1] || *cmd[idx + 1] != 'p')
		{
			if (push[i] < push[i ^ 1])
				start = idx;
			ft_rm_push(cmd, start, push, i);
			start = idx;
		}
	}
	return (--idx);
}

static int	ft_opt_rot(char *cmd[], int idx)
{
	int	i;
	int	rev;
	int	start;
	int	rot[4];

	ft_memset(rot, 0, sizeof(rot));
	start = idx--;
	while (*cmd[++idx] == 'r')
	{
		rev = (cmd[idx][1] == 'r');
		i = cmd[idx][1 + rev] - 'a';
		rot[i + rev * 2]++;
		if (rot[i ^ 1] || rot[(i ^ 1) + 2] || *cmd[idx + 1] != 'r')
		{
			if (*cmd[idx + 1] == 'r')
				i ^= 1;
			if (rev ^ (rot[i] < rot[i + 2]))
				start = idx;
			i *= (rev == 0) - (rev == 1);
			ft_rm_rot(cmd, start, rot, i);
			start = idx;
		}
	}
	return (--idx);
}

static void	ft_optimize_cmd(char *cmd[], int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (*cmd[i] == 'p')
			i = ft_opt_push(cmd, i);
		else if (ft_merge_pair(cmd, i))
			i++;
		else if (*cmd[i] == 'r')
			i = ft_opt_rot(cmd, i);
	}
}

static void	ft_putcmd(char *cmd[], int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (cmd[i])
			ft_putstr_fd(cmd[i], 1);
	}
}

void	ft_optimize(t_frame *frame)
{
	int		size;
	char	**cmd;
	t_node	*node;

	cmd = malloc((frame->cmd.size + 1) * sizeof(char *));
	if (!cmd)
		ft_puterr(NULL);
	size = 0;
	node = frame->cmd.head;
	while (node)
	{
		cmd[size++] = node->str;
		node = node->next;
	}
	cmd[size] = "";
	if (size >= 2)
		ft_optimize_cmd(cmd, size);
	ft_putcmd(cmd, size);
	ft_free((void *)&cmd);
}
