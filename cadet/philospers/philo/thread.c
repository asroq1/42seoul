/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:08:21 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/21 17:53:02 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	free_thread(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->cnt_of_philo)
	{
		pthread_mutex_destroy(&(info->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(info->print));
	free(info->fork);
	free(philo);
}

void	check_even_odd(int id)
{
	if (id % 2 != 0)
	{
		usleep(1000);
	}
	else
	{
		usleep(1000);
	}
}

void	*get_thread(void *philo)
{
	t_info	*tmp_info;
	t_philo	*tmp_philo;

	tmp_philo = philo;
	tmp_info = tmp_philo->info;
	check_even_odd(tmp_philo->id);
	return (0);
}

int	execute_thread(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->cnt_of_philo)
	{
		// philo[i].last_food_time = get_time();
		if (pthread_create(&(philo[i].thread), NULL, get_thread, &(philo[i])))
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < info->cnt_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	free_thread(info, philo);
	printf("execute thread Success\n");
	return (0);
}
