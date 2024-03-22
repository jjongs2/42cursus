/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:01:02 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:14:48 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_thanos_push(t_frame *frame, t_list *lst, int push, int pivot)
{
	int	rot;

	rot = 0;
	while (push > 0)
	{
		if (lst->is_a ^ (lst->head->n > pivot))
		{
			ft_op_push(frame, lst);
			push--;
			continue ;
		}
		if (push == 1)
		{
			if (lst->is_a ^ (lst->head->next->n > pivot))
			{
				ft_op_swap(frame, lst);
				ft_op_push(frame, lst);
				break ;
			}
		}
		ft_op_rot(frame, lst);
		rot++;
	}
	return (rot);
}

static void	ft_thanos(t_frame *frame, t_list *lst, int size, int pivot)
{
	int	rot;
	int	push;

	frame->first = 0;
	if (!frame->b.size)
		frame->first = 1;
	push = size / 2 + size % 2 * (lst->is_a ^ 1);
	rot = ft_thanos_push(frame, lst, push, pivot);
	if (lst->size > size - push)
	{
		while (rot-- > 0)
			ft_op_rrot(frame, lst);
	}
}

void	ft_sort(t_frame *frame, t_list *lst, int size, int pivot)
{
	if (size == 2 || size == 3)
		size = ft_sort_few(frame, lst, size);
	if (ft_is_sorted(lst, size))
	{
		while (!lst->is_a && size-- > 0)
			ft_op_push(frame, lst);
		return ;
	}
	if (lst->is_a)
		pivot += size / 2;
	else
		pivot -= size / 2 + size % 2;
	ft_thanos(frame, lst, size, pivot);
	ft_sort(frame, &frame->a, size / 2 + size % 2, pivot);
	ft_sort(frame, &frame->b, size / 2, pivot);
}
