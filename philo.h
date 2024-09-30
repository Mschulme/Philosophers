/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:53:43 by mschulme          #+#    #+#             */
/*   Updated: 2023/07/02 17:11:41 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_input
{
	int		num_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_times_to_eat;
	long	start_last_eat;
}	t_input;

typedef struct s_philo
{
	t_input			data;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	int				stop;
	int				ac;
	int				philo_index;
}	t_philo;

/* handling_input.c */

int		input_checker(t_input *input, int ac, char **av);
t_input	*handling_input(t_input *input, int ac, char **av);

/* add_data_to_philo.c */

t_philo	*add_data_to_philo(t_philo *philo, t_input *input, int ac);

/* create_thread.c */

void	create_thread(t_philo *philo, long starttime, t_input *input);

/* eatsleepthink.c */

void	*eatsleepthink(void *philosopher);

/* print_timings.c */

void	ft_usleep(long sleep_time);
long	helper_time(void);
void	print_action(long start_time, int index, t_philo *philo, char *str);

/* death_checker.c */

void	deathcheck(t_philo *philo, long starttime, t_input *input);

/* free_philo.c */

void	free_philo(t_philo *philo, t_input *input);

#endif