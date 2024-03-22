/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:42:54 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/25 14:58:10 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_utils.h"

static void	ft_send_signal(char c, int pid)
{
	int	bit;

	bit = 128;
	while (bit > 0)
	{
		if (c & bit)
			ft_kill(pid, SIGUSR1);
		else
			ft_kill(pid, SIGUSR2);
		usleep(150);
		bit >>= 1;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		ft_puterr("Usage: ./client <server PID> <message>");
	pid = ft_atoi(argv[1]);
	while (1)
	{
		ft_send_signal(*argv[2], pid);
		if (*argv[2]++ == '\0')
			return (0);
	}
}
