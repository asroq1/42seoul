/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:44:58 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/28 18:55:49 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_validater(t_stack_data *stack, char *argv[])
{	
	char		**arr;
	int			i;
	int			j;
	long long	value;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		arr = ft_split(argv[i++], ' ');
		if (arr[j] == NULL)
		{
			occur_error(1);
		}
		while (arr[j] != 0)
		{
			value = check_numbers(arr[j]);
			get_a(stack, (int)value);
			j++;
		}
		free_str(arr);
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
