/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:08:21 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/26 16:39:57 by hyunjung         ###   ########.fr       */
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
		usleep(500);
	}
}

	/* 
		get_thread 함수는 실행된 쓰레드의  death가 1이 아닐 떄까지 계속 동작한다.
		1. 인자값으로 void타입밖에 적용이 안되기에 다시 타입을 바꿔준다.
		2. check_even_odd 함수를 통해 홀수부터 재우고, 짝수부터 밥을 먹인다 (데드락 방지).
		3. 반드시 먹어야 하는 횟수랑, 철학자가 먹은 횟수가 같다면 다 먹은 횟수(finish_to_eat)을 ++
	*/
void	*get_thread(void *philo)
{
	t_info	*tmp_info;
	t_philo	*tmp_philo;

	tmp_philo = philo;
	tmp_info = tmp_philo->info;
	check_even_odd(tmp_philo->id);
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
		print_state(tmp_info, "is sleeping", tmp_philo->id);
		new_sleep((long long)tmp_info->time_to_sleep);
		print_state(tmp_info, "is thinking", tmp_philo->id);
	}
}

	/*
	 1. 철학자들마다 한 번은 밥을 먹었다고 가정해서, 저마다 last_food_time을 초기화 해준다.
	 2. 그리고 철학자마다의 thread를 생성해준다.
	 3.  
	 */
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
