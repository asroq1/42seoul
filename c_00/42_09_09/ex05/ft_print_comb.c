/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:22:42 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/12 21:26:37 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	ft_putchar(char c);

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0' - 1;
	while (++i <= '7')
	{
		j = i;
		while (++j <= '8')
		{
			k = j;
			while (++k <= '9')
			{
				ft_putchar(i);
				ft_putchar(j);
				ft_putchar(k);
				if (i == '7' && j == '8' && k == '9')
				{
					break ;
				}
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
