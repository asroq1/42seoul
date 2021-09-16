/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:01:48 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/16 15:37:01 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	trans_to_low(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (*str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	sc;

	sc = 1;
	i = 0;
	trans_to_low(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (sc == 1)
				str[i] = str[i] - 32;
			sc = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			sc = 0;
		else
			sc = 1;
		i++;
	}
	str[i] = '\0';
	return (str);
}
