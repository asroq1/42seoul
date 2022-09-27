/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:08:21 by hyunjung          #+#    #+#             */
/*   Updated: 2022/08/08 17:08:18 by hyunjung         ###   ########.fr       */
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
	pthread_mutex_destroy(&(info->check_death));
	pthread_mutex_destroy(&(info->check_eat_cnt));
	pthread_mutex_destroy(&(info->check_last_food));
	free(info->fork);
	free(philo);
}

void	check_even_odd(int id, t_info *info)
{
	if (id % 2 != 0)
	{
		usleep((info->time_to_eat - 10) * 1000);
	}
}

void	*get_thread(void *philo)
{
	t_info	*tmp_info;
	t_philo	*tmp_philo;

	tmp_philo = philo;
	tmp_info = tmp_philo->info;
	check_even_odd(tmp_philo->id, tmp_info);
	routine(tmp_info, tmp_philo);
	return (0);
}

void	routine(t_info *tmp_info, t_philo *tmp_philo)
{
	int		life;

	while (1)
	{
		pthread_mutex_lock(&(tmp_info->check_death));
		life = tmp_info->death;
		pthread_mutex_unlock(&(tmp_info->check_death));
		if (life == 1)
			break ;
		execute_philo(tmp_info, tmp_philo);
		if (tmp_info->cnt_of_must_eat == tmp_philo->cnt_of_eat)
		{
			pthread_mutex_lock(&(tmp_info->check_eat_cnt));
			tmp_info->finish_to_eat++;
			pthread_mutex_unlock(&(tmp_info->check_eat_cnt));
			break ;
		}		
		pthread_mutex_lock(&(tmp_info->check_death));
		life = tmp_info->death;
		pthread_mutex_unlock(&(tmp_info->check_death));
		print_state(tmp_info, "is sleeping", tmp_philo->id);
		new_sleep((long long)tmp_info->time_to_sleep);
		print_state(tmp_info, "is thinking", tmp_philo->id);
	}
}

int	execute_thread(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->cnt_of_philo)
	{
		philo[i].last_food_time = get_time();
		if (pthread_create(&(philo[i].thread), NULL, get_thread, &(philo[i])))
		{	
			return (1);
		}
		i++;
	}
	check_death(info, philo);
	if (info->cnt_of_philo == 1)
	{
		pthread_mutex_unlock(&(info->fork[philo->left]));
	}
	i = 0;
	while (i < info->cnt_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	free_thread(info, philo);
	return (0);
}
