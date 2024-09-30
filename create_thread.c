/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:29:01 by mschulme          #+#    #+#             */
/*   Updated: 2023/07/01 16:49:44 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_philo *philo, long starttime, t_input *input)
{
	int	i;

	i = 0;
	while (i < input->num_philo)
	{
		philo[i].data.start_last_eat = starttime;
		pthread_create(philo[i].philos, NULL, eatsleepthink, \
			(void *) &philo[i]);
		i++;
	}
}
