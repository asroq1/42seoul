/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:08:21 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/22 18:23:57 by hyunjung         ###   ########.fr       */
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
		usleep(100);
	}
	(void) id;
}

	/* void타입밖에 적용이 안되기에 다시 타입을 바꿔준다.*/
void	*get_thread(void *philo)
{
	t_info	*tmp_info;
	t_philo	*tmp_philo;

	tmp_philo = philo;
	tmp_info = tmp_philo->info;
	check_even_odd(tmp_philo->id);
	while (tmp_info->death == 0)
	{
		
	}
	printf("philo[%d] hello \n", tmp_philo->id);
	return (0);
}

int	execute_thread(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->cnt_of_philo)
	{
		/* 1. 철학자들마다 한 번은 밥을 먹었다고 가정한다. */
		philo[i].last_food_time = get_time();
		if (pthread_create(&(philo[i].thread), NULL, get_thread, &(philo[i])))
		{
			return (1);
		}
		i++;
	}
	/* 2.계속 죽음을 확인해주는 함수로 확인해준다. */
	// check_death(info, philo);
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
