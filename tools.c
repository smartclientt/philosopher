/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:18:28 by shbi              #+#    #+#             */
/*   Updated: 2022/12/16 00:12:55 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= 0)
		{
			ft_putstr_fd("Error: input\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	create_threads(t_philo **philo)
{
	int		i;
	t_philo	*ph;

	i = 0;
	ph = *philo;
	while (i < ph->input->nbr_philo)
	{
		ph->start_time = get_time();
		if (pthread_create(&(ph->ph_th), NULL, routine, ph))
		{
			ft_putstr_fd("Error: create threads\n", 2);
			return (0);
		}
		if (i + 1 != ph->input->nbr_philo)
			ph = ph->next;
		i++;
	}
	i = 0;
	ph = *philo;
	while (i < ph->input->nbr_philo)
	{
		if (pthread_detach(ph->ph_th))
		{
			ft_putstr_fd("Error: create threads\n", 2);
			return (0);
		}
		if (i + 1 != ph->input->nbr_philo)
			ph = ph->next;
		i++;
	}
	return (1);
}

int	create_philo_list(t_philo **philo, t_input *input)
{
	int		i;
	t_philo	*ph;

	i = 0;
	while (i < input->nbr_philo)
	{
		ft_lstadd_end(philo, ft_lstnew(input, i));
		if (!philo)
		{
			ft_putstr_fd("Error: creation philo list\n", 2);
			return (0);
		}
		i++;
	}
	ph = *philo;
	i = 0;
	while (i < input->nbr_philo)
	{
		if (pthread_mutex_init(&ph->forks, NULL))
		{
			ft_putstr_fd("Error: initial mutex\n", 2);
			return (0);
		}
		if (!ph->next)
			ph->next = ph->head;
		ph = ph->next;
		i++;
	}
	return (1);
}

void	init_input(t_input *input, int ac, char **av)
{
	input->nbr_philo = ft_atoi(av[1]);
	input->ttd = ft_atoi(av[2]);
	input->tte = ft_atoi(av[3]);
	input->tts = ft_atoi(av[4]);
	if (ac == 6)
		input->nbr_tte_must = ft_atoi(av[5]);
	else
		input->nbr_tte_must = -1;
	input->c_ph_eat = 0;
	if (pthread_mutex_init(&input->print_mutex, NULL))
	{
		ft_putstr_fd("Error: initial print mutex\n", 2);
		return ;
	}
}
