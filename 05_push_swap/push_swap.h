/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:41:48 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:31:30 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				n;
	char			*str;
	struct s_node	*next;
}					t_node;

typedef struct s_list
{
	int		size;
	int		is_a;
	t_node	*head;
}			t_list;

typedef struct s_frame
{
	t_list	a;
	t_list	b;
	t_list	cmd;
	int		first;
}			t_frame;

t_node	*ft_lstlast(t_list *lst);
t_node	*ft_lstnew(int n);
t_node	*ft_lstnew_str(char *str);
void	ft_lstadd_front(t_list *lst, t_node *new);
void	ft_lstadd_back(t_list *lst, t_node *new);
void	ft_lst_swap(t_list *lst);
void	ft_lst_push(t_frame *frame, t_list *from);
void	ft_lst_rot(t_list *lst);
void	ft_lst_rrot(t_list *lst);

void	ft_save_cmd(t_frame *frame, char *str);
void	ft_op_ss(t_frame *frame, t_list *lst);
void	ft_op_rr(t_frame *frame);
void	ft_op_rrr(t_frame *frame);
void	ft_op_swap(t_frame *frame, t_list *lst);
void	ft_op_push(t_frame *frame, t_list *from);
void	ft_op_rot(t_frame *frame, t_list *lst);
void	ft_op_rrot(t_frame *frame, t_list *lst);

t_list	ft_verify(int argc, char *argv[]);
void	ft_scale(t_list *a);
int		ft_sort_few(t_frame *frame, t_list *lst, int size);
int		ft_is_sorted(t_list *lst, int size);
void	ft_sort(t_frame *frame, t_list *lst, int size, int pivot);
void	ft_rm_push(char *cmd[], int start, int push[], int i);
void	ft_rm_rot(char *cmd[], int start, int rot[], int i);
int		ft_merge_pair(char *cmd[], int i);
void	ft_optimize(t_frame *frame);

#endif
