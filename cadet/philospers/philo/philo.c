/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:05:09 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/25 20:01:29 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"


/* 
	새로운_슬립_함수(대기시간)
{
    목표시각=대기시간 + 현재시각();
    while(목표시각 > 현재시각())
    {usleep(100)}
}
*/

void	get_passed_time(long long wait_time, t_info *info)
{
	long long	now;	
	long long	start;

	start = get_time();
	while (info->death == 0)
	{
		now = get_time();
		if ((now - start) >= wait_time)
		{
			break ;
		}
		usleep(10);
	}
}

int	print_state(t_info *info, char *str, int id)
{
	long long	now;

	now = get_time();
	if (now == 1)
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
	/* 
		철학자 수가 1명이면 끝나지 않기에 따로 예외처리를 해준다. 
		왼쪽부터 집고 오른쪽을 집고 먹은 다음에 오른쪽부터 내려준다.
	*/

int	execute_philo(t_info *info, t_philo *philo)
{
		pthread_mutex_lock(&(info->fork[philo->left]));
		print_state(info, "has taken a fork", philo->id);
		pthread_mutex_lock(&(info->fork[philo->right]));
		print_state(info, "has taken a fork", philo->id);
		print_state(info, "is eating", philo->id);
		philo->last_food_time = get_time();
		philo->cnt_of_eat += 1;
		get_passed_time((long long)info->time_to_eat, info);
		pthread_mutex_unlock(&(info->fork[philo->right]));
		pthread_mutex_unlock(&(info->fork[philo->left]));
	return (0);
}
