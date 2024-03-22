/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:08:01 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/25 14:35:59 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <unistd.h>

# define DEC "0123456789"

typedef struct sigaction	t_sa;

void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_puterr(const char *err_msg);

int		ft_atoi(const char *str);
int		ft_nbrlen(long long n, const char *base);
void	ft_putnbr(long long n, const char *base);

int		ft_printf(const char *s, ...);

void	ft_kill(pid_t pid, int signum);
void	ft_sigaction(int signum, const t_sa *action, t_sa *old_action);

#endif
