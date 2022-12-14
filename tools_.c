/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:26:06 by shbi              #+#    #+#             */
/*   Updated: 2022/12/09 19:02:19 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		ft_putchar_fd(0, fd);
	else
		while (*s)
			ft_putchar_fd(*s++, fd);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long int	r;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	r = 0;
	while ((*str >= '0' && *str <= '9') && r < 2147483648)
		r = (*str++ - '0') + (r * 10);
	r = r * sign;
	if (r < -2147483648)
		return (-1);
	else if (r > 2147483647)
		return (0);
	return ((int)r);
}
