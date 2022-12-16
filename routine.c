/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:58:44 by shbi              #+#    #+#             */
/*   Updated: 2022/12/16 04:49:50 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *ph)
{
	if (pthread_mutex_lock(&ph->forks))
	{
		ft_putstr_fd("Error: mutex lock eat\n", 1);
		return ;
	}
	print_with_mutex("has taken a fork\n", ph);
	if (ph->index != ph->input->nbr_philo - 1)
	{
		if (pthread_mutex_lock(&ph->next->forks))
		{
			ft_putstr_fd("Error: mutex lock eat\n", 1);
			return ;
		}
		print_with_mutex("has taken a fork\n", ph);
	}
	else
	{
		if (pthread_mutex_lock(&ph->head->forks))
		{
			ft_putstr_fd("Error: mutex lock eat\n", 1);
			return ;
		}
		print_with_mutex("has taken a fork\n", ph->head);
	}
	ph->c_eat++;
	if (ph->c_eat == ph->input->nbr_tte_must)
		ph->input->c_ph_eat++;
	print_with_mutex("is eating\n", ph);
	ph->last_time = get_time();
	my_usleep(ph->input->tte);
	if (pthread_mutex_unlock(&ph->forks))
	{
		ft_putstr_fd("Error: mutex unlock eat\n", 1);
		return ;
	}
	if (ph->index != ph->input->nbr_philo - 1)
	{
		if (pthread_mutex_unlock(&ph->next->forks))
		{
			ft_putstr_fd("Error: mutex unlock eat\n", 1);
			return ;
		}
	}
	else
	{
		if (pthread_mutex_unlock(&ph->head->forks))
		{
			ft_putstr_fd("Error: mutex unlock eat\n", 1);
			return ;
		}
	}
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
