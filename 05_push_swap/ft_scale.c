/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:30:46 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:15:19 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_utils.h"

static void	ft_int_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	ft_next_pivot(int *arr, int left, int right)
{
	int	mid;
	int	pivot;
	int	idx_l;
	int	idx_r;

	mid = (left + right) / 2;
	ft_int_swap(arr + left, arr + mid);
	pivot = arr[left];
	idx_l = left;
	idx_r = right;
	while (idx_l < idx_r)
	{
		while (pivot < arr[idx_r])
			idx_r--;
		while (idx_l < idx_r && pivot >= arr[idx_l])
			idx_l++;
		ft_int_swap(arr + idx_l, arr + idx_r);
	}
	arr[left] = arr[idx_l];
	arr[idx_l] = pivot;
	return (idx_l);
}

static void	ft_qsort(int *arr, int left, int right)
{
	int	pivot;

	if (left >= right)
		return ;
	pivot = ft_next_pivot(arr, left, right);
	ft_qsort(arr, left, pivot - 1);
	ft_qsort(arr, pivot + 1, right);
}

static int	ft_lower_bound(int *arr, int size, int val)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (arr[mid] < val)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

void	ft_scale(t_list *a)
{
	int		idx;
	int		*arr;
	t_node	*node;

	arr = ft_calloc(a->size, sizeof(int));
	if (!arr)
		ft_puterr(NULL);
	idx = -1;
	node = a->head;
	while (node)
	{
		arr[++idx] = node->n;
		node = node->next;
	}
	ft_qsort(arr, 0, idx);
	idx = 0;
	node = a->head;
	while (idx++ < a->size)
	{
		if (idx < a->size && arr[idx - 1] == arr[idx])
			ft_puterr(arr);
		node->n = ft_lower_bound(arr, a->size, node->n) + 1;
		node = node->next;
	}
	ft_free((void *)&arr);
}
