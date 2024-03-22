/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:14:33 by yoson             #+#    #+#             */
/*   Updated: 2022/09/19 10:51:38 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_cnt;
	int				stop;
	time_t			last_eat;
	pthread_t		tid;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				must_eat_philo;
	int				stop;
	time_t			start_time;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mutex;
}					t_info;

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_puterr(char *err_msg);

time_t	timestamp_in_ms(time_t start);
void	msleep(time_t time);

int		init_info(t_info *info, char *argv[]);
int		philosophers(t_info *info);
void	act(t_philo *philo);

#endif
