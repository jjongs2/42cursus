/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:36:28 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/21 19:12:03 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_utils.h"

int	main(int argc, char *argv[])
{
	t_frame	frame;

	ft_memset(&frame, 0, sizeof(frame));
	frame.a = ft_verify(argc, argv);
	ft_scale(&frame.a);
	ft_sort(&frame, &frame.a, frame.a.size, 0);
	ft_optimize(&frame);
	return (0);
}
