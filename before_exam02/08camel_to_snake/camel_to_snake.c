/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 22:45:22 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/23 23:13:40 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	if (argc < 2)
	{
		return 0;
	}
	
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == '_')
		{
			argv[1][i + 1] -= 32;
			write(1, &argv[1][i + 1], 1);
			i += 2;
			
		}
		else
		{
		write(1, &argv[1][i], 1);	
		i++;
		}		
	}
	write(1, "\n", 1);
}
