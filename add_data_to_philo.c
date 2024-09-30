/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data_to_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:29:26 by mschulme          #+#    #+#             */
/*   Updated: 2023/07/02 17:13:39 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*add_data_to_philo(t_philo *philo, t_input *input, int ac)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * input->num_philo);
	if (forks == NULL)
		return (NULL);
	i = 0;
	while (i < input->num_philo)
		pthread_mutex_init(&forks[i++], NULL);
	pthread_mutex_init(&lock, NULL);
	i = 0;
	while (i < input->num_philo)
	{
		philo[i].forks = forks;
		philo[i].lock = lock;
		philo[i].data = *input;
		philo[i].stop = 0;
		philo[i].ac = ac;
		philo[i].philo_index = i;
		philo[i].philos = malloc(sizeof(pthread_t));
		if (philo[i++].philos == NULL)
			return (NULL);
	}
	return (philo);
}
