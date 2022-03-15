/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:45:13 by hyunjung          #+#    #+#             */
/*   Updated: 2022/03/15 14:06:17 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(const char **str, va_list ap)
{	
	unsigned int		n;
	int					str_length;

	str_length = 0;
	n = va_arg(ap, int);
	if (n == 0)
	{
		(*str)++;
		write(1, "0", 1);
		str_length++;
	}
	if (**str == 'x')
	{
		str_length = ft_putnbr_base(n, "0123456789abcdef");
		(*str)++;
	}
	else if (**str == 'X')
	{
		str_length = ft_putnbr_base(n, "0123456789ABCDEF");
		(*str)++;
	}
	return (str_length);
}

int	ft_printf_addr(const char **str, va_list ap)
{
	size_t		n;
	int			str_length;

	n = va_arg(ap, size_t);
	str_length = 0;
	if (n == 0)
	{
		(*str)++;
		write(1, "0x0", 3);
		str_length++;
	}
	if (**str == 'p')
	{
		write(1, "0x", 2);
		str_length = ft_putnbr_addr(n, "0123456789abcdef");
		(*str)++;
	}
	return (str_length + 2);
}

int	ft_putnbr_base(unsigned int n, char *base)
{
	int	i;
	int	base_length;
	int	str_length;
	int	nbr_box[256];

	i = 0;
	str_length = 0;
	base_length = 0;
	while (base[base_length] != 0)
	{
		base_length++;
	}
	while (n != 0)
	{
		nbr_box[i] = n % base_length;
		n = n / base_length;
		i++;
	}
	while (--i >= 0)
	{
		ft_putchar(base[nbr_box[i]]);
		str_length++;
	}
	return (str_length);
}

int	ft_putnbr_addr(size_t n, char *base)
{
	int	i;
	int	str_length;
	int	base_length;
	int	nbr_box[256];

	i = 0;
	str_length = 0;
	base_length = 0;
	while (base[base_length] != 0)
	{
		base_length++;
	}
	while (n != 0)
	{
		nbr_box[i] = n % base_length;
		n = n / base_length;
		i++;
	}
	while (--i >= 0)
	{
		ft_putchar(base[nbr_box[i]]);
		str_length++;
	}
	return (str_length);
}
