/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:30:34 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/30 22:15:26 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_doubles(char *str, char c, int idx)
{
	int i;

	i = 0;

	while (i < idx)
	{
		if (str[i] == c)
		{
			return 0;
		}
		i++;
	}
	return 1;
}
int main(int ac, char **av)
{
	int i;
	int j;
	
	i = 0;
	if (ac == 3)
	{
		while (av[1][i] != 0)
		{
			j = 0;
			while (av[2][j] != 0)
			{
				if (av[1][i] == av[2][j])
				{
					if (check_doubles(av[1], av[1][i], i))
					{
						write(1, &av[1][i], 1);
						break;
					}
					
				}
			j++;	
			}
		i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}