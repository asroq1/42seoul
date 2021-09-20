/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:39:16 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/20 23:26:45 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ten_to_sixten(char c)
{
	char	*hex;
	char	left;
	char	mok;

	hex = "0123456789abcdef";
	mok = c / 16;
	left = c % 16;
	ft_putchar('\\');
	ft_putchar(hex[(unsigned char)mok]);
	ft_putchar(hex[(unsigned char)left]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			ten_to_sixten(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}
