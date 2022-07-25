/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:43:34 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/25 17:33:18 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

/* 
	1. 출력 밀림방지를 위해 print도 뮤텍스를 생성해준다.
   	2. fork를 철학자 수와 동일하게 malloc 해준다.
	3. 포크마다 mutex를 생성해준다.
*/
int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->print, NULL) != 0)
	{
		return (1);
	}
	info->fork = malloc(sizeof(pthread_mutex_t) * info->cnt_of_philo);
	if (info->fork == 0)
	{
		return (1);
	}
	while (i < info->cnt_of_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL) != 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/* 
   1. argv 받은 인풋값을 input구조체에 맞게 atoi로 파싱해서 넣어준다. 
   2. time_so_start를 통해 현재 시작시간을 설정한다. (쓰레드 만들기 전에 지정해야지 출력 순서의 얽힘을 방지할 수 있다. 
   왜냐하면 쓰레드 만드는 데에도 시간이 소요되기 떄문에)
   3. 옵션 인자도 있는지 확인해보고 있다면 구조체에 넣어준다.
   3. 뮤텍스 만드는 함수도 만들어준다.
*/
int	init_info(t_info *info, int argc, char *argv[], int err)
{
	if (argc != 5 && argc != 6)
		return (print_error("Input counts Error\n", err));
	info->cnt_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->time_to_start = get_time();
	if (info->cnt_of_philo <= 0 || info->time_to_die < 0
		|| info->time_to_eat < 0 || info->time_to_sleep < 0)
	{
		return (1);
	}
	if (argc == 6)
	{
		info->cnt_of_must_eat = ft_atoi(argv[5]);
		if (info->cnt_of_must_eat <= 0)
		{
			return (1);
		}
	}
	printf("Validate Suceess\n");
	return (0);
}

/*
	1. 철학자 수만큼 malloc을 해준다.
	2. 철학자마다 본인의 왼쪽 오른쪽 등 정보를 넣어준다. (마지막 철학자는 right가 0이다.)
	3. 
*/
int	init_philo(t_info *info, t_philo **philo)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * info->cnt_of_philo);
	if (philo == NULL)
	{
		return (1);
	}
	while (i < info->cnt_of_philo)
	{
		(*philo)[i].id = i;
		(*philo)[i].info = info;
		(*philo)[i].left = i;
		if ((i + 1) % info->cnt_of_philo == 0)
			(*philo)[i].right = 0;
		else
			(*philo)[i].right = i + 1;
		(*philo)[i].last_food_time = get_time();
		(*philo)[i].cnt_of_eat = 0;
		i++;
	}
	printf("init philo Suceess\n");
	return (0);
}
