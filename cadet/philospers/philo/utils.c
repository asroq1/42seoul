/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:30:57 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/19 17:38:34 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int	print_error(char *str, int code)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		write(1, &str[i++], 1);
	}
	exit(code);
	return (0);
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
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
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

int	get_time(void)
{
	return (0);
}
