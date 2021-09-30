/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:17:09 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/30 18:25:35 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] != 0)
	{
		if (s1[i] != s2[i])
		{
			return (-1);
		}
		i++;		
	}
	return (s1 - s2);
}

int main()
{
	printf("mine : %d\n", ft_strcmp("Block!Fmask", "BlockFmask"));
	printf(" original :%d\n", strcmp("Block!Fmask", "BlockFmask"));
}