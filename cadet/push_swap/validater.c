/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:44:58 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/21 12:04:56 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_validater(char *argv[])
{	
	int	i;

	i = 0;
	while (argv[i] != 0)
	{
		check_numbers(argv[i + 1]);
		printf("%s\n", argv[i + 1]);
		i++;
	}
}

int	check_numbers(const char *str)
{
	int					i;
	int					sign;
	int					digit_checker;
	long long			value;

	sign = 1;
	i = 0;
	digit_checker = 0;
	value = 0;
	while (ft_isspace(*str))
		str++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
		digit_checker++;
	}
	if (value * sign > 2147483647 || value * sign < -2147483648
		|| digit_checker == 0)
		occur_error(1);
	return (value * sign);
}
