/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:31:25 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:07:33 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_utils.h"

t_node	*ft_lstlast(t_list *lst)
{
	t_node	*node;

	node = lst->head;
	while (node->next)
		node = node->next;
	return (node);
}

t_node	*ft_lstnew(int n)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (!new)
		ft_puterr(NULL);
	new->n = n;
	return (new);
}

t_node	*ft_lstnew_str(char *str)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (!new)
		ft_puterr(NULL);
	new->str = str;
	return (new);
}

void	ft_lstadd_front(t_list *lst, t_node *new)
{
	new->next = lst->head;
	lst->head = new;
}

void	ft_lstadd_back(t_list *lst, t_node *new)
{
	new->next = NULL;
	if (!lst->head)
		lst->head = new;
	else
		ft_lstlast(lst)->next = new;
}
