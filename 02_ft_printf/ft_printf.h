/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:09:06 by kijsong           #+#    #+#             */
/*   Updated: 2022/07/23 13:46:04 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1
# define FLAGS "-0# +"
# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

typedef struct s_info
{
	va_list		ap;
	int			error;
	int			count;
	int			minus;
	int			zero;
	int			dot;
	int			hash;
	int			space;
	int			plus;
	long long	width;
	long long	precision;
}				t_info;

int			ft_putnchar(char c, int n);
int			ft_putstr(char *s);
char		*ft_strchr(const char *s, int c);
int			ft_strlen(const char *s);

int			ft_max(int a, int b);
int			ft_nbrlen(t_info *info, long long n, const char *base);
int			ft_print_sign(t_info *info, int n);
void		ft_putnbr_base(long long n, const char *base);

void		ft_tags_init(t_info *info);
const char	*ft_get_tags(const char *s, t_info *info);

void		ft_print_char(t_info *info);
void		ft_print_str(t_info *info);
void		ft_print_addr(t_info *info);
void		ft_print_int(t_info *info);
void		ft_print_uint(t_info *info);
void		ft_print_hex_lower(t_info *info);
void		ft_print_hex_upper(t_info *info);
void		ft_print_percent_sign(t_info *info);

int			ft_printf(const char *s, ...);

#endif
