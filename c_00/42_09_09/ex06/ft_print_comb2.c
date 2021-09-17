/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:41:52 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/17 21:49:31 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

#include <unistd.h>

void	comb_two(char i, char j)
{
	char	first_units;
	char	first_tens;
	char	second_tens;
	char	second_units;

	first_units = 48 + (i % 10);
	first_tens = 48 + (i / 10);
	second_units = 48 + (j % 10);
	second_tens = 48 + (j / 10);
	write(1,&first_tens, 1);
	write(1,&first_units, 1);
	write(1," ", 1);
	write(1, &second_tens, 1);
	write(1, &second_units, 1);
	write(1,",", 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j <= 99)
		{	
			if (i < j)
			{
				comb_two(i, j);
				j++;
			}
		}
		i++;
	}
}
