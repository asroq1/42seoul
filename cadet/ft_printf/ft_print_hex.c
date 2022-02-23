/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:45:13 by hyunjung          #+#    #+#             */
/*   Updated: 2022/02/23 16:28:22 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(const char **str, va_list ap)
{	
	int		i;
	unsigned int		n;
	int		str_length;
	char	*tmp;

	i = 0;
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
