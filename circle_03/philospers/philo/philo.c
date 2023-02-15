/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:05:09 by hyunjung          #+#    #+#             */
/*   Updated: 2022/08/08 17:07:24 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	new_sleep(long long wait_time)
{
	long long	now;	
	long long	start;

	start = get_time();
	while (1)
	{
		now = get_time();
		if ((now - start) >= wait_time)
		{
			break ;
		}
		usleep(100);
	}
}

int	print_state(t_info *info, char *str, int id)
{
	long long	now;
	int			life;

	pthread_mutex_lock(&(info->print));
	pthread_mutex_lock(&(info->check_death));
	life = info->death;
	pthread_mutex_unlock(&(info->check_death));
	if (life == 0)
	{
		now = get_time();
		if (now == 1)
		{
			return (1);
		}
		printf("%lld %d %s \n", now - info->time_to_start, id + 1, str);
	}
	pthread_mutex_unlock(&(info->print));
	return (0);
}

int	execute_philo(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->fork[philo->left]));
	print_state(info, "has taken a fork", philo->id);
	pthread_mutex_lock(&(info->fork[philo->right]));
	print_state(info, "has taken a fork", philo->id);
	print_state(info, "is eating", philo->id);
	pthread_mutex_lock(&(info->check_last_food));
	philo->last_food_time = get_time();
	pthread_mutex_unlock((&info->check_last_food));
	philo->cnt_of_eat += 1;
	new_sleep(info->time_to_eat);
	pthread_mutex_unlock(&(info->fork[philo->right]));
	pthread_mutex_unlock(&(info->fork[philo->left]));
	return (0);
}

void	check_all_philo(int i, t_info *info, t_philo *philo)
{
	long long	left_time;
	long long	start_time;

	start_time = info->time_to_start;
	pthread_mutex_lock(&(info->check_last_food));
	left_time = get_time() - philo[i].last_food_time;
	pthread_mutex_unlock(&(info->check_last_food));
	if (left_time >= info->time_to_die)
	{
		pthread_mutex_lock(&info->print);
		pthread_mutex_lock(&info->check_death);
		info->death = 1;
		pthread_mutex_unlock(&info->check_death);
		printf("%lld %d died\n", (get_time() - start_time), philo[i].id + 1);
		pthread_mutex_unlock(&info->print);
	}
	i++;
}

void	check_death(t_info *info, t_philo *philo)
{
	int			i;
	int			cnt_of_eaten;

	while (info->death == 0)
	{
		pthread_mutex_lock(&(info->check_eat_cnt));
		cnt_of_eaten = info->finish_to_eat;
		pthread_mutex_unlock(&(info->check_eat_cnt));
		if ((info->time_to_eat != 0) && (info->cnt_of_philo == cnt_of_eaten))
		{
			pthread_mutex_lock(&info->check_death);
			info->death = 1;
			pthread_mutex_unlock(&info->check_death);
		}
		i = 0;
		while (i < info->cnt_of_philo)
		{
			if (info->death == 1)
				break ;
			check_all_philo(i, info, philo);
			i++;
		}
	}
}
