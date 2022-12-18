/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:05:19 by shbi              #+#    #+#             */
/*   Updated: 2022/12/18 17:03:54 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->index % 2 != 0)
		my_usleep(ph->input->tte);
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
	return (1);
}

int	main(int ac, char **av)
{
	t_input	*input;
	t_philo	*philo;

	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		input = malloc(sizeof(t_input));
		if (!check_args(ac, av))
			return (1);
		init_input(input, ac, av);
		if (!create_philo_list(&philo, input))
			return (1);
		if (!create_threads(&philo))
			return (1);
		watcher(&philo);
		destroy_mutex(&philo);
		free(input);
	}
	return (0);
}
