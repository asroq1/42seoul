/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:43:34 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/14 16:55:36 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
/* 
   1. argv 받은 인풋값을 input구조체에 맞게 atoi로 파싱해서 넣어준다. 
   2. 옵션 인자도 있는지 확인해보고 있다면 구조체에 넣어준다.
   3. 뮤텍스 만드는 함수도 만들어준다.
*/
int	init_input(t_input *input, int argc, char *argv)
{
	input->philo_num = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		input->cnt_of_must_eat = ft_atoi(argv[5]);
		if (input->cnt_of_must_eat >= 0)
		{
			return (FAILURE);
		}
	}
	if (input->philo_num <= 0 || input->time_to_die < 0
		|| input->time_to_eat < 0 || input->time_to_sleep < 0)
	{
		return (FAILURE);
	}
	return (0);
}

/* 
   1. 철학자 수만큼 동적할당 해준다.
   2. 철학자마다 들어온 인자값을 할당해준다.
*/
//int	init_philo(&philo, &input)
//{
	
//}

//int	philo_start()
//{
	
//}
