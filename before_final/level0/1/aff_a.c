/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:38:51 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/28 16:53:03 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Write a program that takes a string, and displays the first 'a' character it
// encounters in it, followed by a newline. If there are no 'a' characters in the
// string, the program just writes a newline. If the number of parameters is not
// 1, the program displays 'a' followed by a newline.

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "a", 1);
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	while (av[1][i] != '\0')
	{
		if (av[1][i] == 'a')
		{
			write(1, "a", 1);
			write(1, "\n", 1);
			return 0;
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;
}