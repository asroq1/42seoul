/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:07:11 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/06 19:48:58 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	sign;
	size_t	value;

	sign = 1;
	value = 0;
	if (isspace(*str))
		str++;
	while (*str != 0)
	{
		if (*str == '-')
		{
			sign = -1;
			str++;
		}
		else if ((*str >= '0') && (*str < '9'))
		{
			value = (value * 10) + (*str - '0');
			str++;
		}
		else
			break ;
	}
	return (value * sign);
}
