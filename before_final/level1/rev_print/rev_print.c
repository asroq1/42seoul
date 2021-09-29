/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:47:52 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/29 19:44:31 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return i;
}
int main(int ac, char **av)
{
	//int length = ft_strlen(av[1]);
	if (ac == 2)
	{
		int i =  ft_strlen(av[1]) - 1;
		
		while (i >= 0)
		{
			printf("%c", av[1][i]);
			i--;
		}
	}
	printf("\n");
	return 0;
}