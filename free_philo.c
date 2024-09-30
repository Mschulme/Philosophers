/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:52:58 by mschulme          #+#    #+#             */
/*   Updated: 2023/07/02 15:38:44 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo *philo, t_input *input)
{
	int	i;

	i = 0;
	while (i < input->num_philo)
	{
		pthread_mutex_destroy(philo[i].forks);
		pthread_mutex_destroy(&philo[i].lock);
		i++;
	}
	i = 0;
	free(philo[i].forks);
	while (i < input->num_philo)
	{
		free(philo[i].philos);
		i++;
	}
	free(philo);
	free(input);
	return ;
}
