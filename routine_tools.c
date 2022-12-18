/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 06:25:02 by shbi              #+#    #+#             */
/*   Updated: 2022/12/18 13:11:37 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		time_res;

	gettimeofday(&time, NULL);
	time_res = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (time_res);
}

void	print_with_mutex(char *str, t_philo *ph)
{
	pthread_mutex_lock(&ph->input->print_mutex);
	printf("%lld	%d	%s", get_time() - ph->input->start_time,
		ph->index + 1, str);
	pthread_mutex_unlock(&ph->input->print_mutex);
}

void	my_usleep(long long time)
{
	long long	time_exact;

	time_exact = time + get_time();
	while (get_time() <= time_exact)
		usleep(50);
}

int	watcher(t_philo	**philo)
{
	t_philo	*ph;

	ph = *philo;
	while (1)
	{
		if (ph->input->c_ph_eat == ph->input->nbr_philo)
		{
			pthread_mutex_lock(&ph->input->print_mutex);
			return (1);
		}
		else if (ph->input->ttd < (get_time() - ph->last_time))
		{
			pthread_mutex_lock(&ph->input->print_mutex);
			usleep(1000);
			printf("%lld	%d	is dead\n", get_time() - ph->input->start_time,
				ph->index + 1);
			return (1);
		}
		ph = ph->next;
	}
}
