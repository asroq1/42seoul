/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:30:57 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/22 18:34:26 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	print_error(char *str, int code)
{
	printf("%s", str);
	return (code);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	long long			value;

	sign = 1;
	i = 0;
	value = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	if (ft_is_digit(str[i] != 0))
	{
		printf("here \n");
		return (1);
	}
	else
	{
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (value * sign > 2147483647)
			return (-1);
		else if (value * sign < -2147483648)
			return (0);
		else
			value = value * 10 + (str[i] - '0');
		i++;
	}
	return (value * sign);
}

/* ms초를 기준으로 하기 때문에 tv_sec(초) * 1000을 해서 ms(밀리초)를 구하고, tv_usec(마이크로초)를 더해서 현재의 밀리초를 구한다. */
int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		return (1);
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	check_death(t_info *info, t_philo *philo)
{
	int			i;
	long long	now;	

	i = 0;
	while (info->death == 0)
	{
		if ((info->time_to_eat != 0) && (info->cnt_of_philo == info->finish_to_eat))
		{
			info->death = 1;
		}
		while (i < info->cnt_of_philo)
		{
			now = get_time();
			if ((now - philo[i].last_food_time) >= info->time_to_die)
			{
				print_state(info, "died", i);
				info->death = 1;
			}
			i++;
		}
	}
}
