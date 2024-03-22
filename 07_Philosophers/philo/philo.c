/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:53:37 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/18 18:35:47 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include "philo.h"

static void	monitor(t_info *info)
{
	time_t	now;
	int		i;

	msleep(15);
	while (1)
	{
		i = -1;
		pthread_mutex_lock(&info->mutex);
		while (++i < info->num_of_philo)
		{
			now = timestamp_in_ms(info->start_time);
			if (now > info->philo[i].last_eat + info->time_to_die)
			{
				printf("%zu %d died\n", now, info->philo[i].id);
				info->stop = 1;
				break ;
			}
		}
		if (info->stop)
			break ;
		pthread_mutex_unlock(&info->mutex);
		usleep(300);
	}
	pthread_mutex_unlock(&info->mutex);
}

int	philosophers(t_info *info)
{
	t_philo			*philo;
	struct timeval	now;
	int				i;

	i = -1;
	gettimeofday(&now, NULL);
	info->start_time = now.tv_sec * 1000 + now.tv_usec / 1000;
	while (++i < info->num_of_philo)
	{
		philo = &info->philo[i];
		if (pthread_create(&philo->tid, NULL, (void *)act, philo))
			return (ft_puterr("pthread_create() failed"));
	}
	monitor(info);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_join(info->philo[i].tid, NULL);
	return (0);
}
