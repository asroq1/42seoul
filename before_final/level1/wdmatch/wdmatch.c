/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:57:27 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/28 17:41:10 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_valid(char *ins1 , char*ins2)
{
	int i = 0;
	int j = 0;
	while (ins1[i] != 0)
	{
		while (1)
		{
			if (ins1[i] == ins2[j])
			{
				j++;
				break;
			}	
			if (ins2[j] == 0)
			{
				return 0;
			}
			j++;
		}	
		i++;
	}	
	return 1;
}
int main(int ac, char **av)
{
	int i = 0;

	if (ac == 3)
	{
		if (is_valid(av[1], av[2]))
		{
			while (av[1][i] != 0)
			{	
				write(1, &av[1][i], 1);
				i++;
			}
		}
	}
		  write(1, "\n", 1);		
}