/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:30:57 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/26 17:27:46 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	print_error(char *str, int code)
{
	printf("%s", str);
	return (code);
}

int	ft_isdigit(int arg)
{
	if (arg >= 48 && arg <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	value;
	int			flag;

	value = 0;
	flag = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		value = value * 10 + (*str - '0');
		i++;
		if ((value < 0 || i > 19) && flag == 1)
			return (-1);
		else if ((value < 0 || i > 19) && flag == -1)
			return (-1);
		str++;
	}
	return (value * flag);
}

int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		return (1);
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/*
	1. 밖 반복문에서 누군가 죽을 때까지 확인
	2. 조건문에서는 철학자의 수와 철학자 수 + 다 먹은 수 = 즉 다먹음. 이니깐 death로 돌림
	3. 현재 - 마지막 식사시간이 time_to_die 보다 크면 출력해주고 죽인다.
*/
