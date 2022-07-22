/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:05:09 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/22 17:57:52 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// void	get_passed_time(long long wait_time, t_info *info)
// {
// 	long long	now;	
// 	long long	start;

// 	start = get_time();
// 	while (info->finish == 0)
// 	{
// 		now = get_time();
// 		if ((now - start) >= wait_time)
// 		{
// 			break ;
// 		}
// 		usleep(10);
// 	}
// }

int	print_state(t_info *info, char *str, int id)
{
	long long	now;

	now = get_time();
	if (now != 0)
	{
		return (1);
	}
	pthread_mutex_lock(&(info->print));
	if (info->death == 0)
	{
		printf("%lld %d %s \n", now - info->time_to_start, id + 1, str);
	}
	pthread_mutex_unlock(&(info->print));
	return (0);
}

int	execute_philo(t_info *info, t_philo *philo)
{
	if (info->cnt_of_philo == 1)
	{
		pthread_mutex_lock(&(info->fork[philo->left]));
		print_state(info, "has taken a fork", philo->id);
		pthread_mutex_unlock(&(info->fork[philo->left]));
	}
	else
	{
		pthread_mutex_lock(&(info->fork[philo->left]));
		print_state(info, "has taken a fork", philo->id);
		pthread_mutex_lock(&(info->fork[philo->right]));
		print_state(info, "has taken a fork", philo->id);
		print_state(info, "is eating", philo->id);
		philo->last_food_time = get_time();
		philo->cnt_of_eat = philo->cnt_of_eat++;
		// get_passed_time((long long)info->time_to_eat, info);
		pthread_mutex_unlock(&(info->fork[philo->right]));
		pthread_mutex_unlock(&(info->fork[philo->left]));
	}
	return (0);
}
