/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:39:25 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/20 19:33:20 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	val;
	int	button;

	val = 0;
	button = 1;
	while ((*str <= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			button *= -1;
		}
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		val = (val * 10) + (*str - '0');
		str++;
	}
	return (val * button);
}
