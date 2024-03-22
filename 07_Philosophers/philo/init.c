/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:01:12 by yoson             #+#    #+#             */
/*   Updated: 2022/09/19 10:51:59 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

static int	init_mutex(t_info *info)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	while (!ret && ++i < info->num_of_philo)
		ret |= pthread_mutex_init(&info->fork[i], NULL);
	ret |= pthread_mutex_init(&info->mutex, NULL);
	return (ret);
}

static void	init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		philo = &info->philo[i];
		philo->id = i + 1;
		philo->left_fork = i;
		philo->right_fork = (i + 1) % info->num_of_philo;
		philo->info = info;
	}
}

int	init_info(t_info *info, char *argv[])
{
	ft_memset(info, 0, sizeof(t_info));
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = -1;
	if (!info->num_of_philo || !info->time_to_die || \
		!info->time_to_eat || !info->time_to_sleep || \
		!info->must_eat)
		return (ft_puterr("Invalid argument"));
	info->fork = malloc(info->num_of_philo * sizeof(pthread_mutex_t));
	info->philo = ft_calloc(info->num_of_philo, sizeof(t_philo));
	if (!info->fork || !info->philo || init_mutex(info))
		return (ft_puterr("Out of memory"));
	init_philo(info);
	return (0);
}
