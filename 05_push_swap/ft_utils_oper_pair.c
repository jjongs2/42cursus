/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_op_pair.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:56:39 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 17:03:21 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_op_ss(t_frame *frame, t_list *lst)
{
	t_list	*oppo;
	int		a;
	int		b;

	oppo = &frame->a;
	if (lst->is_a)
		oppo = &frame->b;
	a = oppo->head->n;
	b = oppo->head->next->n;
	if (oppo->is_a ^ (a < b))
	{
		ft_lst_swap(oppo);
		if (oppo->is_a)
			ft_save_cmd(frame, "sa");
		else
			ft_save_cmd(frame, "sb");
	}
}

void	ft_op_rr(t_frame *frame)
{
	int		a;
	int		b;

	if (frame->b.size >= 2)
	{
		a = frame->b.head->n;
		b = ft_lstlast(&frame->b)->n;
		if (a < b)
		{
			ft_lst_rot(&frame->b);
			ft_save_cmd(frame, "rb");
		}
	}
}

void	ft_op_rrr(t_frame *frame)
{
	int		a;
	int		b;

	if (frame->b.size >= 2)
	{
		a = frame->b.head->n;
		b = ft_lstlast(&frame->b)->n;
		if (a < b)
		{
			ft_lst_rrot(&frame->b);
			ft_save_cmd(frame, "rrb");
		}
	}
}
