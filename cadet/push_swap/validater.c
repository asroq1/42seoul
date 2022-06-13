/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:44:58 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/13 18:46:24 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	occur_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

void	input_validater(char *argv[])
{	
	int	i;

	i = 0;
	while (argv[i] != 0)
	{
		ft_atoall(argv[i]);
		printf("%s\n", argv[i]);
		i++;
	}
}

// void	empty_validarer(char argv[])
// {
// 	if (argv ==)
// 	{
// 		/* code */
// 	}
// }

int	ft_atoall(const char *str)
{
	int					i;
	int					sign;
	int					marker;
	long long			value;

	sign = 1;
	i = 0;
	value = 0;
	marker = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
		marker++;
	}
		printf("value ==> %lld\n", value);
		value = value * sign;
		if (str[i] != '\0' || marker > 10 || value > 2147483647 || value < -2147483647)
		occur_error();
	return (int)(value);	
}
