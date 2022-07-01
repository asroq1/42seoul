/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:44:58 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/01 09:46:19 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(t_stack_data *stack)
{
	int	i;
	int	length;

	i = 0;
	length = stack->length - 1;
	while (i < length)
	{	
		if (stack->arr[i] < stack->arr[i + 1])
		{
			return (0);
		}
		i++;
	}
	exit(1);
}

void	check_duplicate(t_stack_data *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < stack->length)
	{
		j = i + 1;
		tmp = stack->arr[i];
		while (j < stack->length)
		{
			if (stack->arr[j] == tmp)
			{
				occur_error(1);
			}
			j++;
		}
		i++;
	}
}

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
	check_input(stack);
	check_duplicate(stack);
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
