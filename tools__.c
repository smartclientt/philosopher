/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:37:46 by shbi              #+#    #+#             */
/*   Updated: 2022/12/14 01:21:22 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_free(t_philo **lst)
{
	if (*lst)
	{
		free(*lst);
		*lst = NULL;
	}
	return (*lst);
}

t_philo	*ft_lstnew(t_input *input, int index)
{
	t_philo	*new_node;

	new_node = (t_philo *)malloc(sizeof(t_philo));
	if (!new_node)
		return (NULL);
	new_node->input = input;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_end(t_philo **lst, t_philo *new)
{
	t_philo	*tmp;

	if (*lst && new)
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}
