/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:33:30 by hyunjung          #+#    #+#             */
/*   Updated: 2021/09/14 11:49:55 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);

int test = 1;

void ft_putnbr(int nb)
{	
	
	if(nb <= 9 && nb >= 0)
	{
		ft_putchar(nb + '0');
	}
	else if(nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if(nb < 0 && nb != -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(nb * (-1));
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}