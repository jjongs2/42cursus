/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:27:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/19 10:56:15 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "philo.h"

static void	lock_print(t_info *info, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&info->mutex);
	if (!info->stop)
		printf(msg, timestamp_in_ms(info->start_time), philo->id);
	else if (!philo->stop)
		philo->stop = 1;
	pthread_mutex_unlock(&info->mutex);
}

static void	philo_eat(t_info *info, t_philo *philo)
{
	time_t	now;

	pthread_mutex_lock(&info->fork[philo->left_fork]);
	lock_print(info, philo, "%zu %d has taken a fork\n");
	pthread_mutex_lock(&info->fork[philo->right_fork]);
	lock_print(info, philo, "%zu %d has taken a fork\n");
	pthread_mutex_lock(&info->mutex);
	now = timestamp_in_ms(info->start_time);
	if (!info->stop)
		printf("%zu %d is eating\n", now, philo->id);
	philo->last_eat = now;
	if (++philo->eat_cnt == info->must_eat)
	{
		if (++info->must_eat_philo == info->num_of_philo)
			info->stop = 1;
	}
	pthread_mutex_unlock(&info->mutex);
	msleep(info->time_to_eat);
	pthread_mutex_unlock(&info->fork[philo->left_fork]);
	pthread_mutex_unlock(&info->fork[philo->right_fork]);
}

static int	outsider(t_info *info, t_philo *philo)
{
	if (philo->left_fork != philo->right_fork)
		return (0);
	printf("%zu 1 has taken a fork\n", timestamp_in_ms(info->start_time));
	return (1);
}

void	act(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (outsider(info, philo))
		return ;
	if (philo->id & 1)
		msleep(15);
	while (!philo->stop)
	{
		philo_eat(info, philo);
		lock_print(info, philo, "%zu %d is sleeping\n");
		msleep(info->time_to_sleep);
		lock_print(info, philo, "%zu %d is thinking\n");
	}
}
