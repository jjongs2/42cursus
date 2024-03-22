/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_oper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:56:35 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:19:38 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

int	ft_is_sorted(t_list *lst, int size)
{
	t_node	*node;

	node = lst->head;
	while (node->next && --size > 0)
	{
		if (lst->is_a ^ (node->n < node->next->n))
			return (0);
		node = node->next;
	}
	return (1);
}

void	ft_lst_swap(t_list *lst)
{
	t_node	*swap;

	if (lst->size < 2)
		return ;
	swap = lst->head->next;
	lst->head->next = swap->next;
	ft_lstadd_front(lst, swap);
}

void	ft_lst_push(t_frame *frame, t_list *from)
{
	t_list	*to;
	t_node	*push;

	if (!from->size)
		return ;
	to = &frame->a;
	if (from->is_a)
		to = &frame->b;
	push = from->head;
	from->head = from->head->next;
	ft_lstadd_front(to, push);
	from->size--;
	to->size++;
}

void	ft_lst_rot(t_list *lst)
{
	t_node	*rot;

	if (lst->size < 2)
		return ;
	rot = lst->head;
	lst->head = lst->head->next;
	ft_lstadd_back(lst, rot);
}

void	ft_lst_rrot(t_list *lst)
{
	t_node	*rrot;
	t_node	*node;

	if (lst->size < 2)
		return ;
	rrot = ft_lstlast(lst);
	node = lst->head;
	while (lst->head->next->next)
		lst->head = lst->head->next;
	lst->head->next = NULL;
	rrot->next = node;
	lst->head = rrot;
}
