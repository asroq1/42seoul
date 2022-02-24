/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:45:13 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/24 13:05:11 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(const char **str, va_list ap)
{	
	unsigned int		n;
	int					str_length;

	str_length = 0;
	n = va_arg(ap, int);
	if (**str == 'x')
	{
		ft_putnbr_base(n, "0123456789abcdef");
		(*str)++;
	}
	else if (**str == 'X')
	{
		ft_putnbr_base(n, "0123456789ABCDEF");
		(*str)++;
	}
	return (0);
}

int	ft_printf_addr(const char **str, va_list ap)
{
	size_t		n;

	n = va_arg(ap, size_t);
	if (**str == 'p')
	{
		write(1, "0x", 2);
		ft_putnbr_addr(n, "0123456789abcdef");
		(*str)++;
	}
}
