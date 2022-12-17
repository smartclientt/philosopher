/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:05:19 by shbi              #+#    #+#             */
/*   Updated: 2022/12/17 17:10:17 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->index % 2 == 0)
		usleep(ph->input->tte);
	while (1)
	{
		eating(ph);
		sleeping(ph);
		thinking(ph);
	}
	return (NULL);
}

int	destroy_mutex(t_philo **philo)
{
	t_philo	*ph;
	t_philo	*head;
	int		i;

	ph = *philo;
	head = *philo;
	i = 0;
	while (i < ph->input->nbr_philo)
	{
		pthread_mutex_destroy(&ph->forks);
		ph = ph->next;
		i++;
	}
	if (pthread_mutex_destroy(&head->input->print_mutex))
	{
		pthread_mutex_unlock(&head->input->print_mutex);
		pthread_mutex_destroy(&head->input->print_mutex);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_input	input;
	t_philo	*temp;
	t_philo	*philo;
	int		i;

	i = 0;
	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		if (!check_args(ac, av))
			return (1);
		init_input(&input, ac, av);
		pthread_mutex_init(&input.data_race_mutex, NULL);
		if (!create_philo_list(&philo, &input))
			return (1);
		if (!create_threads(&philo))
			return (1);
		watcher(&philo);
		// if (!destroy_mutex(&philo))
		// 	return (1);
		while (i < philo->input->nbr_philo)
		{
			temp = philo->next;
			free(philo);
			philo = temp;
			i++;
		}
	}
	return (0);
}
