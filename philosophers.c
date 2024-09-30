/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:53:49 by mschulme          #+#    #+#             */
/*   Updated: 2023/07/02 18:00:28 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	main_helper(t_input *input, t_philo *philo, int ac)
{
	long	starttime;
	int		i;

	philo = add_data_to_philo(philo, input, ac);
	starttime = helper_time();
	create_thread(philo, starttime, input);
	deathcheck(philo, starttime, input);
	i = 0;
	while (i < input->num_philo)
		pthread_join(*(philo[i++].philos), NULL);
	free_philo(philo, input);
	return ;
}

int	main(int ac, char **av)
{
	t_input	*input;
	t_philo	*philo;

	input = NULL;
	input = handling_input(input, ac, av);
	if (input == NULL)
		return (EXIT_FAILURE);
	philo = malloc(input->num_philo * sizeof(*philo));
	if (philo == NULL)
		return (EXIT_FAILURE);
	main_helper(input, philo, ac);
	return (EXIT_SUCCESS);
}
