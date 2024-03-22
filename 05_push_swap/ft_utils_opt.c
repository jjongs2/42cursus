/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:34:54 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:14:25 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_rm_push(char *cmd[], int start, int push[], int i)
{
	while (push[i] && push[i ^ 1])
	{
		if (push[i] < push[i ^ 1])
		{
			cmd[start--] = NULL;
			cmd[start--] = NULL;
		}
		else
		{
			cmd[start++] = NULL;
			cmd[start++] = NULL;
		}
		push[i]--;
		push[i ^ 1]--;
	}
}

void	ft_rm_rot(char *cmd[], int start, int rot[], int i)
{
	int	rev;

	rev = (i < 0);
	if (rev)
		i *= -1;
	while (rot[i] && rot[i + 2])
	{
		if ((rev && rot[i] > rot[i + 2]) || (!rev && rot[i] < rot[i + 2]))
		{
			cmd[start--] = NULL;
			cmd[start--] = NULL;
		}
		else
		{
			cmd[start++] = NULL;
			cmd[start++] = NULL;
		}
		rot[i]--;
		rot[i + 2]--;
	}
	rot[i] = 0;
	rot[i + 2] = 0;
}

int	ft_merge_pair(char *cmd[], int i)
{
	if ((!ft_strcmp(cmd[i], "sa") && !ft_strcmp(cmd[i + 1], "sb")) \
		|| (!ft_strcmp(cmd[i], "sb") && !ft_strcmp(cmd[i + 1], "sa")))
	{
		cmd[i++] = "ss";
		cmd[i] = NULL;
	}
	else if ((!ft_strcmp(cmd[i], "ra") && !ft_strcmp(cmd[i + 1], "rb")) \
			|| (!ft_strcmp(cmd[i], "rb") && !ft_strcmp(cmd[i + 1], "ra")))
	{
		cmd[i++] = "rr";
		cmd[i] = NULL;
	}
	else if ((!ft_strcmp(cmd[i], "rra") && !ft_strcmp(cmd[i + 1], "rrb")) \
			|| (!ft_strcmp(cmd[i], "rrb") && !ft_strcmp(cmd[i + 1], "rra")))
	{
		cmd[i++] = "rrr";
		cmd[i] = NULL;
	}
	if (!cmd[i])
		return (1);
	return (0);
}
