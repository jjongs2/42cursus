/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:05:37 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:17:03 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "ft_utils.h"

void	ft_save_cmd(t_frame *frame, char *str)
{
	ft_lstadd_back(&frame->cmd, ft_lstnew_str(str));
	if (frame->cmd.size++ == INT_MAX)
		ft_puterr(NULL);
}

void	ft_op_swap(t_frame *frame, t_list *lst)
{
	ft_lst_swap(lst);
	if (lst->is_a)
		ft_save_cmd(frame, "sa");
	else
		ft_save_cmd(frame, "sb");
	if (frame->a.size >= 2 && frame->b.size >= 2)
		ft_op_ss(frame, lst);
}

void	ft_op_push(t_frame *frame, t_list *from)
{
	ft_lst_push(frame, from);
	if (!from->is_a)
		ft_save_cmd(frame, "pa");
	else
		ft_save_cmd(frame, "pb");
}

void	ft_op_rot(t_frame *frame, t_list *lst)
{
	ft_lst_rot(lst);
	if (lst->is_a)
		ft_save_cmd(frame, "ra");
	else
		ft_save_cmd(frame, "rb");
	if (frame->first)
		ft_op_rr(frame);
}

void	ft_op_rrot(t_frame *frame, t_list *lst)
{
	ft_lst_rrot(lst);
	if (lst->is_a)
		ft_save_cmd(frame, "rra");
	else
		ft_save_cmd(frame, "rrb");
	if (frame->first)
		ft_op_rrr(frame);
}
