/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:56:45 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 18:56:16 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_2(t_frame *frame, t_list *lst)
{
	const int	a = lst->head->n;
	const int	b = lst->head->next->n;

	if (lst->is_a ^ (a < b))
		ft_op_swap(frame, lst);
	return (2);
}

static int	ft_sort_3_only(t_frame *frame, t_list *lst)
{
	const int	a = lst->head->n;
	const int	b = lst->head->next->n;
	const int	c = lst->head->next->next->n;

	if ((lst->is_a && a > c && c > b) || \
			(!lst->is_a && a < c && c < b))
		ft_op_rot(frame, lst);
	else if (!lst->is_a && b < c && c < a)
	{
		ft_op_push(frame, lst);
		ft_op_swap(frame, lst);
	}
	else
	{
		if (lst->is_a ^ (a < b))
			ft_op_swap(frame, lst);
		if (lst->is_a ^ (b < c))
			ft_op_rrot(frame, lst);
		if (!ft_is_sorted(lst, 3) && (lst->is_a ^ (a < b)))
			ft_op_swap(frame, lst);
	}
	return (lst->size);
}

static void	ft_r_s_rr(t_frame *frame, t_list *lst)
{
	ft_op_rot(frame, lst);
	ft_op_swap(frame, lst);
	ft_op_rrot(frame, lst);
}

static int	ft_sort_3(t_frame *frame, t_list *lst, int size)
{
	const int	a = lst->head->n;
	const int	b = lst->head->next->n;
	const int	c = lst->head->next->next->n;

	if (!lst->is_a && b < c && c < a)
	{
		ft_op_push(frame, lst);
		ft_op_swap(frame, lst);
		size--;
	}
	else
	{
		if (lst->is_a ^ (a < b))
			ft_op_swap(frame, lst);
		if (!ft_is_sorted(lst, 3))
			ft_r_s_rr(frame, lst);
		if (!ft_is_sorted(lst, 3) && (lst->is_a ^ (b < c)))
			ft_op_swap(frame, lst);
	}
	return (size);
}

int	ft_sort_few(t_frame *frame, t_list *lst, int size)
{
	if (size == 2)
		return (ft_sort_2(frame, lst));
	if (size == 3 && lst->size == 3)
		return (ft_sort_3_only(frame, lst));
	return (ft_sort_3(frame, lst, size));
}
