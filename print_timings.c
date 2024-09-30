/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_timings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:55:02 by mschulme          #+#    #+#             */
/*   Updated: 2023/07/02 16:45:26 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long sleep_time)
{
	long	start;

	start = helper_time();
	while (start + sleep_time > helper_time())
		usleep(1000);
}

long	helper_time(void)
{
	struct timeval	check_time;

	gettimeofday(&check_time, NULL);
	return (check_time.tv_sec * 1000 + check_time.tv_usec * 0.001);
}

void	print_action(long start_time, int index, t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo)->lock);
	if ((*philo).stop != 1)
		printf("%ld %d %s \n", helper_time() - start_time, index, str);
	pthread_mutex_unlock(&(philo)->lock);
	return ;
}
