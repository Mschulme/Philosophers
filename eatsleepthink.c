/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eatsleepthink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:52:38 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/22 19:52:38 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	helper3(t_philo *philo, long start_time, int left, int right)
{
	ft_usleep((*philo).data.time_to_eat);
	pthread_mutex_unlock(&(philo)->forks[left]);
	pthread_mutex_unlock(&(philo)->forks[right]);
	print_action(start_time, (*philo).philo_index, philo, "is sleeping");
	ft_usleep((*philo).data.time_to_sleep);
	print_action(start_time, (*philo).philo_index, philo, "is thinking");
}

static int	helper2(t_philo *philo, int left, int right)
{
	pthread_mutex_lock(&(philo)->lock);
	(*philo).data.start_last_eat = helper_time();
	(*philo).data.num_times_to_eat--;
	if ((*philo).stop == 1)
	{
		pthread_mutex_unlock(&(philo)->lock);
		pthread_mutex_unlock(&(philo)->forks[left]);
		pthread_mutex_unlock(&(philo)->forks[right]);
		return (-1);
	}
	pthread_mutex_unlock(&(philo)->lock);
	return (0);
}

static void	helper1(t_philo *philo, long start_time, int left, int right)
{
	pthread_mutex_lock(&(philo)->forks[left]);
	print_action(start_time, (*philo).philo_index, philo, "has taken a fork");
	if ((*philo).data.num_philo == 1)
		(*philo).stop = 1;
	else
		pthread_mutex_lock (&(philo)->forks[right]);
	print_action(start_time, (*philo).philo_index, philo, "has taken a fork");
	print_action(start_time, (*philo).philo_index, philo, "is eating");
}

void	*eatsleepthink(void *philosopher)
{
	t_philo	*philo;
	int		left;
	int		right;
	long	start_time;

	philo = philosopher;
	left = (*philo).philo_index;
	right = ((*philo).philo_index + 1) % (*philo).data.num_philo;
	start_time = (*philo).data.start_last_eat;
	if ((*philo).philo_index % 2 == 1)
		ft_usleep((*philo).data.time_to_eat * 0.5);
	while (1)
	{
		helper1(philo, start_time, left, right);
		if (helper2(philo, left, right) == -1)
			return (NULL);
		helper3(philo, start_time, left, right);
	}
	return (NULL);
}
