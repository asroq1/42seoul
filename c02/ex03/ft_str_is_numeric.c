/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:18:15 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/15 23:35:25 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_str_is_numeric(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			return 1;
		}
		else if(!str[i] >= '0' && !str[i] <= '9')
		{

		}
		// printf("%c", str[i]);
		i++;
	}
}

int main()
{	
	int t = 0;
	char test[4] = "SETs";
	t = ft_str_is_numeric(test);
	printf(" RES : %d", t);
}