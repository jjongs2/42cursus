/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:40:11 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:17:14 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "push_swap.h"
#include "get_next_line.h"

static int	ft_verify_cmd(char *cmd)
{
	char		*pos;
	const char	*type = "\0sa\0sb\0ss\0pa\0pb\0ra\0rb\0rr\0rra\0rrb\0rrr";

	pos = ft_strnstr(type, cmd, 37);
	if (!pos)
		ft_puterr(NULL);
	return (pos - type - 1);
}

static void	ft_init_table(void *f[])
{
	int	i;

	i = -1;
	while (++i < 33)
		f[i] = NULL;
	f[0] = ft_lst_swap;
	f[3] = ft_lst_swap;
	f[6] = ft_lst_swap;
	f[15] = ft_lst_rot;
	f[18] = ft_lst_rot;
	f[21] = ft_lst_rot;
	f[24] = ft_lst_rrot;
	f[28] = ft_lst_rrot;
	f[32] = ft_lst_rrot;
}

static void	ft_command(t_frame *frame, char *cmd, void *f[], int idx)
{
	int		i;
	void	(*func)(t_list *);
	t_list	*lst;

	i = 0;
	while (cmd[i + 1])
		i++;
	lst = &frame->b;
	if ((cmd[0] == 'p') ^ (cmd[i] == 'a'))
		lst = &frame->a;
	func = f[idx];
	if (!func)
		ft_lst_push(frame, lst);
	else
	{
		func(lst);
		if (cmd[i] != 'a' && cmd[i] != 'b')
			func(&frame->a);
	}
}

static void	ft_check(t_frame *frame)
{
	int		size;
	char	*line;
	void	*f[33];

	ft_init_table(f);
	size = frame->a.size;
	line = get_next_line(0);
	while (line)
	{
		ft_command(frame, line, f, ft_verify_cmd(line));
		line = get_next_line(0);
	}
	if (frame->a.size == size && ft_is_sorted(&frame->a, frame->a.size))
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
}

int	main(int argc, char *argv[])
{
	t_frame	frame;

	ft_memset(&frame, 0, sizeof(frame));
	frame.a = ft_verify(argc, argv);
	ft_scale(&frame.a);
	ft_check(&frame);
	return (0);
}
