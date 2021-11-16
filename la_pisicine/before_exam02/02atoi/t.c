/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:55:09 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/24 11:18:38 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int i = 0;
	int value = 0;
	int sing = 1;
	int cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 32)
		{
			str++;
		}
		else if(str[i] == '+')
		{
			cnt++;
			str++;
		}
		else if(str[i] == '-')
		{
			cnt++;
			str++;
			sing = -1;
		}
		else if(str[i] >= '0' && str[i] <= '9')
		{
			value = value * 10 + (str[i] - '0');
		}
		else
		{
			break;
		}
		i++;
	}
	if(cnt > 2)
		{
			printf("%d", cnt);
			return 0;
		}
	return value * sing;
}

int main()
{
	char t[50] = "+1234tt";
	printf("origin :%d\n", ft_atoi(t));
	printf("%d", atoi(t));
}