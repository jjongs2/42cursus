/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:11:43 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/18 17:38:31 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>
#include "philo_bonus.h"

void	kill_child(t_info *info, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (kill(info->pid[i], SIGTERM))
			ft_puterr("kill() failed");
	}
}

static void	monitor_must_eat(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
		sem_wait(info->must_eat_philo);
	sem_wait(info->print);
	sem_post(info->stop);
}

static void	monitor_stop(t_info *info)
{
	sem_wait(info->stop);
	kill_child(info, info->num_of_philo);
}

static void	monitor(t_info *info)
{
	pthread_t	tid[2];
	int			error;
	int			i;

	error = 0;
	if (info->must_eat)
	{
		error |= pthread_create(&tid[0], NULL, (void *)monitor_must_eat, info);
		if (!error)
			pthread_detach(tid[0]);
	}
	error |= pthread_create(&tid[1], NULL, (void *)monitor_stop, info);
	if (error)
	{
		kill_child(info, info->num_of_philo);
		ft_puterr("pthread_create() failed");
	}
	pthread_detach(tid[1]);
	i = -1;
	while (++i < info->num_of_philo)
		waitpid(info->pid[i], NULL, 0);
}

void	philosophers(t_info *info)
{
	struct timeval	now;
	int				i;

	i = -1;
	gettimeofday(&now, NULL);
	info->start_time = now.tv_sec * 1000 + now.tv_usec / 1000;
	while (++i < info->num_of_philo)
	{
		info->philo.id = i + 1;
		info->pid[i] = fork();
		if (info->pid[i] == 0)
			act(info);
		else if (info->pid[i] == -1)
		{
			kill_child(info, i - 1);
			ft_puterr("fork() failed");
		}
	}
	monitor(info);
}
