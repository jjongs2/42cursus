/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:41:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/25 16:52:45 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_utils.h"

static void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;

	(void)context;
	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else if (signum == SIGUSR2)
		c = (c << 1) | 0;
	if (++bit == 8)
	{
		write(1, &c, 1);
		if (!c)
		{
			usleep(300);
			ft_kill(info->si_pid, SIGUSR1);
		}
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	t_sa	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	ft_sigaction(SIGUSR1, &sa, NULL);
	ft_sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
