/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:05:09 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/20 17:52:16 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// void	*get_thread(void *argv)
// {
// 	t_info	*tmp_info;
// 	t_philo	*tmp_philo;

// 	tmp_philo = argv;
// 	tmp_info = philo->info;
// 	if (tmp_philo->id % 2 != 0)
// 	{
// 		usleep(1000);
// 	}
// 	while (tmp_info == 0)
// 	{
// 		excute_philo(tmp_info, tmp_philo);
// 		if (tmp_info-> == tmp_philo->)
// 		{
			
// 		}
// 	}
// }

// int	print_state(t_info *info, char *str, int id)
// {
// 	long long	now;

// 	now = get_time();
// 	if (now != 0)
// 	{
// 		return (1);
// 	}
// 	pthread_mutex_lock(&(info->print));
// 	if (info->finish == 0)
// 	{
// 		printf("%;;d %d %s \n", now - arg->star)
// 	}
// 	return (0);
// }

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
		get_passed_time((long long)info->time_to_eat, info);
		pthread_mutex_lock(&(info->fork[philo->left]));
		pthread_mutex_lock(&(info->fork[philo->right]));
	}
	return (0);
}
