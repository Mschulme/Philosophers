/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:33:25 by mschulme          #+#    #+#             */
/*   Updated: 2023/07/02 17:12:02 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	helper2(t_philo *phi, long start, int i)
{
	int	j;

	j = 0;
	if (helper_time() - phi[i].data.start_last_eat > phi[i].data.time_to_die)
	{
		j = 0;
		while (j < phi[0].data.num_philo)
			phi[j++].stop = 1;
		printf("%ld %d has died\n", helper_time() - start, phi[i].philo_index);
		i = 0;
		while (i < phi[0].data.num_philo)
			pthread_mutex_unlock(&phi[i++].lock);
		return (-1);
	}
	return (0);
}

static int	helper1(t_philo *philo, t_input *input, int *sum, int i)
{
	int	j;

	j = 0;
	if (philo[i].data.num_times_to_eat <= 0)
		*sum += 1;
	if (*sum == input->num_philo && philo[0].ac == 6)
	{
		while (j < philo[0].data.num_philo)
			philo[j++].stop = 1;
		j = 0;
		while (j < philo[0].data.num_philo)
			pthread_mutex_unlock(&philo[j++].lock);
		return (-1);
	}
	return (0);
}

void	deathcheck(t_philo *philo, long starttime, t_input *input)
{
	int	i;
	int	*sum;
	int	a;

	sum = &a;
	while (1)
	{
		i = 0;
		ft_usleep(8);
		while (i < philo[0].data.num_philo)
			pthread_mutex_lock(&philo[i++].lock);
		i = 0;
		*sum = 0;
		while (i < input->num_philo)
		{
			if (helper1(philo, input, sum, i) == -1)
				return ;
			if (helper2(philo, starttime, i) == -1)
				return ;
			i++;
		}
		i = 0;
		while (i < philo[0].data.num_philo)
			pthread_mutex_unlock(&philo[i++].lock);
	}
}
