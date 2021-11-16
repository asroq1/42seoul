/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_wdmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:16:07 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/28 20:40:36 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(char *av1, char *av2)
{
	int i = 0;
	int j = 0;
	while (av1[i] != 0)
	{
		while (1)
		{
			if (av1[i] == av2[j])
			{
				j++;
				break;
			}
			if (av2[j] == 0)
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
	return 0;
}