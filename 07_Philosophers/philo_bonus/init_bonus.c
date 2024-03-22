/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:01:12 by yoson             #+#    #+#             */
/*   Updated: 2022/09/18 20:47:05 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static sem_t	*init_sem(char *name, int oflag, mode_t mode, unsigned int val)
{
	sem_t	*sem;

	sem = sem_open(name, oflag, mode, val);
	if (sem == SEM_FAILED)
		ft_puterr("sem_open() failed");
	sem_unlink(name);
	return (sem);
}

void	init_info(t_info *info, char *argv[])
{
	ft_memset(info, 0, sizeof(t_info));
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = 0;
	info->pid = ft_calloc(info->num_of_philo, sizeof(pid_t));
	info->must_eat_philo = init_sem("must_eat_philo", O_CREAT, S_IRWXU, 0);
	info->stop = init_sem("stop", O_CREAT, S_IRWXU, 0);
	info->fork = init_sem("fork", O_CREAT, S_IRWXU, info->num_of_philo);
	info->print = init_sem("print", O_CREAT, S_IRWXU, 1);
}
