/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:05:04 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/18 16:06:55 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{	
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n <= 9 && n >= 0)
	{
		ft_putchar(n + '0');
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (n < 0 && n != -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
