/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:18:35 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/23 14:14:27 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
	{
		return 0;
	}
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			argv[1][i] = 'M' - (argv[1][i] - 'N');
			write(1, &argv[1][i], 1);
		}
		else if(argv[1][i] >= 'A' && argv[1][i] <= 'z')
		{
			argv[1][i] = 'm' - (argv[1][i] - 'n');
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;
}