/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:28:44 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/14 14:13:06 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>

time_t	timestamp_in_ms(time_t start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000 - start);
}

void	msleep(time_t msec)
{
	time_t	start;

	start = timestamp_in_ms(0);
	while (timestamp_in_ms(0) < start + msec)
		usleep(100);
}
