/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:18:10 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/23 18:39:50 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_atoi(const char *str)
{
	int sign = 1;
	int value = 0;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			value = (value * 10) + (*str - '0');
			printf("%d\n", value);
			str++;
		}
		else
		{
			break;
		}		
	}
	return value * sign;
}
int main()
{
	char c[10] = "-asd23ff";
	printf("%d",ft_atoi(c));
}