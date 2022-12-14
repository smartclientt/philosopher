/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:05:22 by shbi              #+#    #+#             */
/*   Updated: 2022/12/14 01:18:19 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_input
{
	int				nbr_philo;
	int				ttd;
	int				tts;
	int				tte;
	int				nbr_tte_must;
}	t_input;

typedef struct s_philo
{
	pthread_mutex_t	forks;
	int				index;
	t_input			*input;
	pthread_t		ph_th;
	struct s_philo	*next;
}	t_philo;

// tools
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);

// list tools
t_philo	*ft_free(t_philo **lst);
t_philo	*ft_lstnew(t_input *input, int index);
void	ft_lstadd_end(t_philo **lst, t_philo *new);


// parcing
int		check_args(int ac, char **av);

// algo tools
void	init_input(t_input *input, int ac, char **av);
int		create_philo_list(t_philo **philo, t_input *input);
int		create_threads(t_philo **philo);
int		destroy_mutex(t_philo **philo);
void	*routine(void *arg);

#endif
