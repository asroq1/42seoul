/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:05:04 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/19 10:18:04 by hyunjung         ###   ########.fr       */
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

size_t	ft_int_length(int n)
{
	size_t	length;

	if (n == 0)
	{
		return (1);
	}
	length = 0;
	if (n < 0)
	{
		length++;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	long	value;
	size_t	length;
	char	*new_str;

	length = ft_int_length(n);
	value = n;
	new_str = malloc(length * sizeof(char) + 1);
	if (new_str == 0)
		return (0);
	if (value < 0)
	{
		new_str[0] = '-';
		value *= -1;
	}
	if (value == 0)
		new_str[0] = '0';
	new_str[length] = 0;
	length -= 1;
	while (value != 0)
	{
		new_str[length] = '0' + value % 10;
		length--;
		value /= 10;
	}
	return (new_str);
}
