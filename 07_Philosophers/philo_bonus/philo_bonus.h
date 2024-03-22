/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:14:33 by yoson             #+#    #+#             */
/*   Updated: 2022/09/18 20:47:01 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>

typedef struct s_philo
{
	int		id;
	int		eat_cnt;
	time_t	last_eat;
}			t_philo;

typedef struct s_info
{
	int			num_of_philo;
	time_t		time_to_die;
	time_t		time_to_eat;
	time_t		time_to_sleep;
	int			must_eat;
	time_t		start_time;
	t_philo		philo;
	pid_t		*pid;
	sem_t		*must_eat_philo;
	sem_t		*stop;
	sem_t		*fork;
	sem_t		*print;
	pthread_t	tid;
}				t_info;

int		ft_atoi(const char *str);
void	*ft_malloc(size_t size);
void	*ft_calloc(size_t count, size_t size);

void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_puterr(char *err_msg);

time_t	timestamp_in_ms(time_t start_time);
void	msleep(time_t time);

void	init_info(t_info *info, char *argv[]);
void	philosophers(t_info *info);
void	act(t_info *info);
void	kill_child(t_info *info, int count);

#endif
