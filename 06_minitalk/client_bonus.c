/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:50:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/25 16:52:07 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "ft_utils.h"

int	g_size;

static void	ft_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Server received %d byte", g_size);
		if (g_size > 1)
			write(1, "s", 1);
		write(1, "\n", 1);
		exit(0);
	}
}

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
	int	idx;

	if (argc != 3)
		ft_puterr("Usage: ./client <server PID> <message>\n");
	pid = ft_atoi(argv[1]);
	idx = 0;
	while (1)
	{
		ft_send_signal(argv[2][idx], pid);
		if (argv[2][idx++] == '\0')
			break ;
		g_size = idx;
	}
	signal(SIGUSR1, ft_handler);
	while (1)
		pause();
	return (0);
}
