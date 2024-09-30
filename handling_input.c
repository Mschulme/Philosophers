/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:00:34 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/27 16:46:10 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long	res;

	res = 0;
	while (((*str == ' ' || (*str >= 9 && *str <= 13)) == 1) && *str)
		str++;
	if (*str == '-')
		res = -1;
	if (*str == '+' && *str++ != 0)
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if (*str != 0 || res < 0)
		return (-1);
	return (res);
}

int	input_handler(t_input *input, int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		input->num_philo = ft_atoi(av[1]);
		input->time_to_die = ft_atoi(av[2]);
		input->time_to_eat = ft_atoi(av[3]);
		input->time_to_sleep = ft_atoi(av[4]);
		if (input->num_philo <= 0 || input->time_to_die == -1 \
				|| input->time_to_eat == -1 || input->time_to_sleep == -1)
			return (-1);
		if (ac == 6)
		{
			input->num_times_to_eat = ft_atoi(av[5]);
			if (input->num_times_to_eat == -1)
				return (-1);
			if (input->num_times_to_eat == 0)
				return (-2);
		}
		return (0);
	}
	else
		return (-1);
}

int	input_checker(t_input *input, int ac, char **av)
{
	if (input_handler(input, ac, av) == -1)
	{
		write(1, "Input Error\n", 12);
		free(input);
		return (-1);
	}
	if (input_handler(input, ac, av) == -2)
	{
		write(1, "Please enter number large then zero\n", 36);
		free(input);
		return (-1);
	}
	return (1);
}

t_input	*handling_input(t_input *input, int ac, char **av)
{
	input = malloc(sizeof(t_input));
	if (input == NULL)
		return (NULL);
	input->num_times_to_eat = 0;
	if (input_checker(input, ac, av) == -1)
		return (NULL);
	return (input);
}
