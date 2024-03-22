/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:27:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/18 18:38:29 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "philo_bonus.h"

static void	lock_print(t_info *info, t_philo *philo, char *msg)
{
	sem_wait(info->print);
	printf(msg, timestamp_in_ms(info->start_time), philo->id);
	sem_post(info->print);
}

static void	philo_eat(t_info *info, t_philo *philo)
{
	time_t	now;

	sem_wait(info->fork);
	lock_print(info, philo, "%zu %d has taken a fork\n");
	sem_wait(info->fork);
	lock_print(info, philo, "%zu %d has taken a fork\n");
	sem_wait(info->print);
	now = timestamp_in_ms(info->start_time);
	printf("%zu %d is eating\n", now, philo->id);
	philo->last_eat = now;
	if (++philo->eat_cnt == info->must_eat)
		sem_post(info->must_eat_philo);
	sem_post(info->print);
	msleep(info->time_to_eat);
	sem_post(info->fork);
	sem_post(info->fork);
}

static void	monitor_dead(t_info *info)
{
	time_t	now;

	msleep(15);
	while (1)
	{
		now = timestamp_in_ms(info->start_time);
		if (now > info->philo.last_eat + info->time_to_die)
		{
			sem_wait(info->print);
			printf("%zu %d died\n", now, info->philo.id);
			sem_post(info->stop);
			break ;
		}
		usleep(300);
	}
}

void	act(t_info *info)
{
	t_philo		*philo;
	time_t		time_to_think;

	if (pthread_create(&info->tid, NULL, (void *)monitor_dead, info))
		return (ft_puterr("pthread_create() failed"));
	pthread_detach(info->tid);
	philo = &info->philo;
	if (!(philo->id & 1))
		msleep(15);
	while (1)
	{
		philo_eat(info, philo);
		lock_print(info, philo, "%zu %d is sleeping\n");
		msleep(info->time_to_sleep);
		lock_print(info, philo, "%zu %d is thinking\n");
		time_to_think = philo->last_eat + info->time_to_die \
						- timestamp_in_ms(info->start_time);
		if (time_to_think > 0)
			msleep(time_to_think * 0.5);
	}
}
