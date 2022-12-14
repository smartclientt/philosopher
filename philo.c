/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:05:19 by shbi              #+#    #+#             */
/*   Updated: 2022/12/14 03:17:25 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int mails = 0;

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (mails < 2000000)
	{
		// pthread_mutex_lock(&ph->forks);
		mails++;
		// pthread_mutex_unlock(&ph->forks);
	}
	return (NULL);
}

int	destroy_mutex(t_philo **philo)
{
	t_philo	*ph;

	ph = *philo;
	while (ph)
	{
		if (pthread_mutex_destroy(&ph->forks))
		{
			ft_putstr_fd("Error: destroy mutex list\n", 2);
			return (0);
		}
		ph = ph->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_input	input;
	t_philo	*philo;

	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		if (!check_args(ac, av))
			return (1);
		init_input(&input, ac, av);
		if (!create_philo_list(&philo, &input))
			return (1);
		if (!create_threads(&philo))
			return (1);
		if (!destroy_mutex(&philo))
			return (1);
		printf("mails == %d\n", mails);
	}
	// printf("tte =  %d | ttd = %d | tts = %d | nbr_philo = %d\n", input.tte, philo->input->ttd, input.tts, input.nbr_philo);
	return (0);
}
