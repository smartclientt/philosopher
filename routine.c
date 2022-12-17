/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:58:44 by shbi              #+#    #+#             */
/*   Updated: 2022/12/17 17:12:51 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->forks);
	print_with_mutex("has taken a fork\n", ph);
	pthread_mutex_lock(&ph->next->forks);
	print_with_mutex("has taken a fork\n", ph);
	ph->c_eat++;
	if (ph->c_eat == ph->input->nbr_tte_must)
		ph->input->c_ph_eat++;
	print_with_mutex("is eating\n", ph);
	ph->last_time = get_time();
	my_usleep(ph->input->tte);
	pthread_mutex_unlock(&ph->forks);
	pthread_mutex_unlock(&ph->next->forks);
}

void	sleeping(t_philo *ph)
{
	print_with_mutex("is sleeping\n", ph);
	my_usleep(ph->input->tts);
}

void	thinking(t_philo *ph)
{
	print_with_mutex("is thinking\n", ph);
}
