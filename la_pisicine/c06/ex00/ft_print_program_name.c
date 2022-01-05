/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:36:53 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/24 23:00:32 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[0][i] != 0 && argc == 1)
	{
		write(1, &argv[0][i], 1);
		i++;
	}
	write (1, "\n", 1);
	return (0);
}