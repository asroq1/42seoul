/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:00:35 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/29 23:03:05 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int ac, char **argv)
{
	int i = 0;
	int j = 0;
	int rep;
	if (ac == 2)
	{
		while (argv[1][i] != 0)
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
			 rep = argv[1][i] - 97;
			}
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
			 rep = argv[1][i] - 65;
			}
			while (rep != 0)
			{
				printf("%c", argv[1][i]);
				rep--;
			}
				printf("%c", argv[1][i]);
			i++;
		}
	}
			printf("\n");
}