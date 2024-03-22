/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:34:56 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/25 14:35:43 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_utils.h"

void	ft_kill(pid_t pid, int signum)
{
	if (kill(pid, signum) == -1)
		ft_puterr("Error: Invalid PID");
}

void	ft_sigaction(int signum, const t_sa *action, t_sa *old_action)
{
	if (sigaction(signum, action, old_action) == -1)
		ft_puterr("Error: Sigaction failed\n");
}
